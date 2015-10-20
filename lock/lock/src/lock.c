/*
 * lock.c
 *
 *  Created on: Oct 14, 2015
 *      Author: Rane
 */
#include "lock.h"

/*
 * Lock deadbolt
 * returns 0 for success, 1 for fail
 */
void lock() {
	int adc = 1023;
	delay32Ms(0,100);
	init_timer32PWM(1, freq(430), MATCH0);	/* set timer32_1 to generate pwm signal with period, use MR0
											 * pwm signal on PIO1_1 (labeled as AD2)
											 */
	delay32Ms(0,100);
	enable_timer32(1);						// enable timer32_1
	while(adc > 500) {						// rotate servo until stop hit
		if(LPC_TMR32B1->TCR != 1)
			LPC_TMR32B1->TCR = 1;
		adc = ADCRead(0);
		delay32Ms(0,100);
	}
	disable_timer32(1);						// stop rotation
	GPIOSetValue(PORT2,7,0); // green
	GPIOSetValue(PORT2,6,1); // red
}

/*
 * unlock deadbolt
 * returns 0 for success, 1 for fail
 */
void unlock() {
	int adc = 1023;
	delay32Ms(0,100);
	init_timer32PWM(1, freq(270), MATCH0);	/* set timer32_1 to generate pwm signal with period, use MR0
											 * pwm signal on PIO1_1 (labeled as AD2)
											 */
	delay32Ms(0,100);
	enable_timer32(1);						// enable timer32_1
	while(adc > 500) {						// rotate servo until stop hit
		if(LPC_TMR32B1->TCR != 1)
			LPC_TMR32B1->TCR = 1;
		adc = ADCRead(0);
		delay32Ms(0,100);
	}
	disable_timer32(1);						// stop rotation
	GPIOSetValue(PORT2,6,0); // red
	GPIOSetValue(PORT2,7,1); // green
}

/*
 * calculates the value needed to set the specified frequency
 */
int freq(float f) {
	float v = ((1/((f)/750))*64000);
	return (int)v;
}

/*
 * initilizes pins for multi color led
 */
void initLED(){
	GPIOSetDir(PORT2,6,1);
	GPIOSetDir(PORT2,7,1);
	GPIOSetDir(PORT2,8,1);
	GPIOSetValue(PORT2,6,0); // red
	GPIOSetValue(PORT2,7,0); // green
	GPIOSetValue(PORT2,8,0); // blue
}
