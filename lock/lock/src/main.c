/*
 * main.c
 *
 *  Created on: Oct 14, 2015
 *      Author: Rane
 */

#include "driver_config.h"
#include "target_config.h"
#include "timer32.h"
#include "gpio.h"
#include "lock.h"

volatile uint32_t period = 1000;  			//48Khz PWM frequency

int main() {
	GPIOInit();								// enable clock to gpio

	init_timer32PWM(1, period, MATCH0);		/* set timer32_1 to generate pwm signal with period, use MR0
											 * pwm signal on PIO1_1
											 */
	setMatch_timer32PWM (1, 0, period/4);	// set the timer32_1 MR0 value
	enable_timer32(1);						// enable timer32_1


	return 0;
}
