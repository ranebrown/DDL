/*
===============================================================================
 Name        : Lab3.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#ifdef __USE_CMSIS
#include "LPC11Uxx.h"
#endif

#include <cr_section_macros.h>

#include <stdio.h>

// duty cycle definitions
#define duty_25 0.25
#define duty_75 0.75

// Interrupt flags checking for match registers
#define mr0_check 1
#define mr1_check 2

// global variables
int oldfreq = 0;
int newfreq = 0;

/* GPIO and GPIO Interrupt Initialization */
void GPIOInit() {
	LPC_SYSCON->SYSAHBCLKCTRL |= (1<<6);	//Enable AHB clock to the GPIO domain
	LPC_GPIO->DIR[0] = 0;					//Set PORT-0 pin-0 as an input
	NVIC_EnableIRQ(FLEX_INT0_IRQn); 		//Enable the interrupt
	NVIC_SetPriority(FLEX_INT0_IRQn,2); 	//Set interrupt priority to 2, same as timer.
	LPC_GPIO->DIR[0] |= (1<<7);  			//Set GPIO0 Pin7 as an output

	return;
}

/* TIMER32 and TIMER32 Interrupt Initialization */
void TIMERInit() {
	// access system clock control register and enable clock for 32-bit counter/timer 0
	// see pg. 31 of UM10462 for details
	LPC_SYSCON->SYSAHBCLKCTRL |= (1<<9);

	// reset timer counter to 0, see pg. 354 of UM10462 for details
	uint32_t reg = LPC_CT32B0->TCR; // store current TCR
	LPC_CT32B0->TCR = 0; // disable timer (bit 0)
	LPC_CT32B0->TC = 1; // set timer counter to a non-zero value
	LPC_CT32B0->TCR = 1<<1; // reset timer counter and prescale counter (bit 1)
	while(LPC_CT32B0->TC != 0) {} // wait to ensure reset occurred
	LPC_CT32B0->TCR = reg; // restore TCR

	// enable interrupt for match register 0, see pg. 355 of UM10462 for details
	LPC_CT32B0->MCR = 3; // enable interrupt on match register 0 (bit 0), reset TC on match bit(1)
	LPC_CT32B0->MR0 = 480000000; // set match value - interrupt every 10 sec

	// enable timer 32 ch0 (start counting)
	LPC_CT32B0->TCR |= 1<<0; // bit 0

	// Enable interrupt for timer32_0, see pg. 72 of UM10462 for details
	NVIC_ClearPendingIRQ(TIMER_32_0_IRQn);
	NVIC_EnableIRQ(TIMER_32_0_IRQn);
}

/* GPIO Interrupt Handler */
void FLEX_INT0_IRQHandler(void) {
	//First clear the interrupt
	//LPC_GPIO0->IC |= (0x1<<0);

	//Turn on the LED at PORT0 PIN7
	//LPC_GPIO0 |= ~(1<<6);
	//LPC_GPIO[0]->MASKED_ACCESS[(1<<6)] = (bitVal<<6);

	//Turn off the LED at PORT0 PIN7
	//LPC_GPIO0 &= (1<<6);



}

/* TIMER32 Interrupt Handler */
void TIMER32_0_IRQHandler(void) {
	unsigned int x = LPC_CT32B0->IR;
	x = x & 1;
	if(x = 1) {
		// reset interrupt flag for match channel 0, see pg. 353 of UM10462 for details
		LPC_CT32B0->IR &= 1<<0;
	}

	unsigned int y = LPC_CT32B0->IR;
	y = y & 2;
	if(y = 2) {
		// 1ms interrupt
		if(oldfreq != newfreq) {
			// update led blink rate
		}
	}

	// 10 sec interrupt
		// update duty cycle


	printf("test\n");


}

int main(void) {
	// basic system initialization taken care of in cr_startup_lpc11ux

	SystemCoreClockUpdate(); // update system clock


    /* Initialization code */
    GPIOInit();                   // Initialize GPIO ports for both Interrupts and LED control
    TIMERInit();                // Initialize Timer and Generate a 1ms interrupt

    /* Infinite looping */
    while(1) {
    	__WFI(); // wait for an interrupt to occur
    }


    return 0;
}