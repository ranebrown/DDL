/*
 * lock.h
 *
 *  Created on: Oct 14, 2015
 *      Author: Rane
 */

#ifndef LOCK_H_
#define LOCK_H_

#include "driver_config.h"
#include "target_config.h"
#include "timer32.h"
#include "gpio.h"
#include "adc.h"
#include "uart.h"
#include "stdio.h"

/*
 * Lock deadbolt
 *
 */
void lock();

/*
 * unlock deadbolt
 *
 */
void unlock();

/*
 * calculates the value needed to set the specified frequency
 */
int freq(float f);

/*
 * short delay
 */
void delay();

/*
 * initilizes pins for multi color led
 */
void initLED();

#endif /* LOCK_H_ */
