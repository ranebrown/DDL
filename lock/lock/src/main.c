/*
 * main.c
 *
 *  Created on: Oct 14, 2015
 *      Author: Rane
 */

#include "lock.h"

extern volatile uint32_t UARTCount;
extern volatile uint8_t UARTBuffer[BUFSIZE];

int main() {
	init_timer32(0,TIME_INTERVAL); // initilize timer32_0
	GPIOInit();			// enable clock to gpio
	UARTInit(9600);		// initialize uart at 9600 baud
	ADCInit(ADC_CLK);	// enable adc at 2.4MHz
	initLED();			// initialize pins for led
	unlock();
	GPIOSetValue(PORT2,7,1); // green

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
