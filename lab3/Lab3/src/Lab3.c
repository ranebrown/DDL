/*
===============================================================================
 Name        : Lab3.c
 Author      : Brian Douglass and Rane Brown
 Description : GPIO port 0 pin 9 functions as a digital oscilloscope. Every 10 sec duty cycle is switched
 	 	 	 	 between 25% and 75%
===============================================================================
*/

#ifdef __USE_CMSIS
#include "LPC11Uxx.h"
#endif

#include <cr_section_macros.h>

#include <stdio.h>

volatile uint32_t newTime = 0;
volatile uint32_t oldTime = 0;
volatile uint32_t period = 0;
volatile uint32_t timeKeeper = 0;
volatile float dutyCycle = .25;
volatile float onTime = 0;

/* GPIO and GPIO Interrupt Initialization */
void GPIOInit() {
	LPC_SYSCON->SYSAHBCLKCTRL |= 1<<6;	//Enable AHB clock to the GPIO domain
	LPC_SYSCON->SYSAHBCLKCTRL |= 1<<19; // enable clock to gpio pin interrupt register

//	LPC_IOCON->PIO0_9 // register controls the function of i/o pin

	LPC_GPIO->DIR[0] &= ~(1<<9);			//Set PORT-0 Pin-9 as an input
	LPC_GPIO->DIR[0] |= 1<<7;  				//Set PORT-0 Pin-7 as an output

	LPC_GPIO->CLR[0] |= 1<<7;				//Turn the LED off initially

	LPC_SYSCON->PINTSEL[0] = 9;				//maps port 0 pin 9 to interrupt vector 0 (FLEX_INT0_IRQn)

	LPC_GPIO_PIN_INT->ISEL = 0;		//Edge Sensitive interrupt
	LPC_GPIO_PIN_INT->IENR = 1;		// Enable rising edge interrupt

	NVIC_ClearPendingIRQ(FLEX_INT0_IRQn);
	NVIC_SetPriority(FLEX_INT0_IRQn,2); 	//Set interrupt priority to 2, same as timer.
	NVIC_EnableIRQ(FLEX_INT0_IRQn); 		//Enable the interrupt handler

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
	LPC_CT32B0->MR0 = 48000; // set match value - interrupt every 1ms

	// enable timer 32 ch0 (start counting)
	LPC_CT32B0->TCR |= 1<<0; // bit 0

	// Enable interrupt for timer32_0, see pg. 72 of UM10462 for details
	NVIC_ClearPendingIRQ(TIMER_32_0_IRQn);
	NVIC_SetPriority(TIMER_32_0_IRQn,2); 	//Set interrupt priority to 2, same as gpio
	NVIC_EnableIRQ(TIMER_32_0_IRQn);

	// timer 1
	LPC_SYSCON->SYSAHBCLKCTRL |= (1<<10); // enable timer 1
	LPC_CT32B1->TC = 0; // clear count
	LPC_CT32B1->TCR = 1; // enable counter
}

/* GPIO Interrupt Handler */
void FLEX_INT0_IRQHandler(void) {
	LPC_GPIO_PIN_INT->RISE |= 1<<0; // clear pending interrupt

	// calculate period
	newTime = LPC_CT32B1->TC;
	period = newTime - oldTime;
	oldTime = newTime;

	// calculate how long led should be on in ms
	onTime = (period*dutyCycle)/48000;
}

/* TIMER32 Interrupt Handler */
void TIMER32_0_IRQHandler(void) {
	// reset interrupt flag for match channel 0, see pg. 353 of UM10462 for details
	LPC_CT32B0->IR |= 1<<0;

	// every 10 seconds switch duty cycle
	if(timeKeeper<10000) {
		timeKeeper++;
		dutyCycle = .25;
	}
	else if(timeKeeper >= 10000 && timeKeeper < 20000) {
		timeKeeper++;
		dutyCycle = .75;
	}
	else
		timeKeeper = 0;

	if(onTime > 0) {
		// led on for specified duty cycle
		LPC_GPIO->SET[0] |= 1<<7;
		onTime--;
	}
	else
		// led off
		LPC_GPIO->CLR[0] |= 1<<7;
}

int main(void) {
	// basic system initialization taken care of in cr_startup_lpc11ux
	SystemCoreClockUpdate(); // update system clock

    /* Initialization code */
    GPIOInit();                   // Initialize GPIO ports for both Interrupts and LED control
    TIMERInit();               	  // Initialize Timer and Generate a 1ms interrupt

    /* Infinite looping */
    while(1) {
    	__WFI(); // wait for an interrupt to occur
    }

    return 0;
}
