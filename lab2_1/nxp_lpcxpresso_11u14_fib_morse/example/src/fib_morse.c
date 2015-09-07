
#include "board.h"
#include <stdio.h>

static const short table[16][6] = {
{5,1,1,1,1,1}, /* 0 r0*/
{5,0,1,1,1,1}, /* 1 r1*/
{5,0,0,1,1,1}, /* 2 r2*/
{5,0,0,0,1,1}, /* 3 r3*/
{5,0,0,0,0,1}, /* 4 r4*/
{5,0,0,0,0,0}, /* 5 r5*/
{5,1,0,0,0,0}, /* 6 r6*/
{5,1,1,0,0,0}, /* 7 r7*/
{5,1,1,1,0,0}, /* 8 r8*/
{5,1,1,1,1,0}, /* 9 r9*/
{2,0,1,9,9,9}, /* A r10*/
{4,1,0,0,0,9}, /* B r11*/
{4,1,0,1,0,9}, /* C r12*/
{3,1,0,0,9,9}, /* D r13*/
{1,0,9,9,9,9}, /* E r14*/
{4,0,0,1,0,9}  /* F r15*/
};

int fibonacci(int n)
{
	if ( n == 0 )
    	return 0;
	else if ( n == 1 )
    	return 1;
	else
    	return ( fibonacci(n-1) + fibonacci(n-2) );
}

void lookup(int dig) {
	// morse code lookup
	int i;
	for(i=1; i<table[dig][0]+1; i++)
		printf("%d",table[dig][i]);
}

void extract(int fib) {
	printf("Hex value of fibonacci number: %x\n",fib);
	int hex[4] = {-1,-1,-1,-1};
	unsigned int mask, temp;
	int i=0;
	mask = 0xF;

	// extract each hex digit (stored in reverse order)
	for(i=0; fib!=0; i++) {
		temp = fib & mask;
		hex[i] = temp;
		fib = fib >> 4;
	}
	// convert to morse
	for(i=3; i>=0; i--) {
		if(hex[i] == -1)
			; // do nothing if no value stored
		else
			lookup(hex[i]);
	}

	printf("\n");
}


void TIMER32_0_IRQHandler(void)
{
	if (Chip_TIMER_MatchPending(LPC_TIMER32_0, 1)) {
		Chip_TIMER_ClearMatch(LPC_TIMER32_0, 1);
		Board_LED_Set(0, true);
	}
}

int main(void) {
	// variables
	uint32_t timerFreq;
	int f;

	// board initilization
	SystemCoreClockUpdate();
	Board_Init();

	// timer setup
	Chip_TIMER_Init(LPC_TIMER32_0);
	timerFreq = Chip_Clock_GetSystemClockRate();
	Chip_TIMER_Reset(LPC_TIMER32_0);
	Chip_TIMER_MatchEnableInt(LPC_TIMER32_0, 1);
	Chip_TIMER_SetMatch(LPC_TIMER32_0, 1, (timerFreq / 10));
	Chip_TIMER_ResetOnMatchEnable(LPC_TIMER32_0, 1);
	Chip_TIMER_Enable(LPC_TIMER32_0);

	/* Enable timer interrupt */
	NVIC_ClearPendingIRQ(TIMER_32_0_IRQn);
	NVIC_EnableIRQ(TIMER_32_0_IRQn);

	f = fibonacci(10);
	extract(f);

	return 0;
}
