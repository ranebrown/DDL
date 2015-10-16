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
#include "adc.h"
#include "uart.h"
#include "lock.h"
#include "stdio.h"

extern volatile uint32_t UARTCount;
extern volatile uint8_t UARTBuffer[BUFSIZE];

int main() {
	GPIOInit();			// enable clock to gpio
	UARTInit(9600);		// initialize uart at 9600 baud
	ADCInit(ADC_CLK);

	while (1) {
		if ( UARTCount != 0 ) {
			LPC_UART->IER = IER_THRE | IER_RLS;				/* Disable RBR */
			UARTSend( (uint8_t *)UARTBuffer, UARTCount );
			if(UARTBuffer[0] == 'o')
				unlock();
			else if(UARTBuffer[0] == 'c')
				lock();
			UARTCount = 0;
			LPC_UART->IER = IER_THRE | IER_RLS | IER_RBR;	/* Re-enable RBR */
		}
	}
}
