/****************************************************************************
 *   $Id:: uart_main.c 4824 2010-09-07 18:47:51Z nxp21346                   $
 *   Project: NXP LPC11xx UART example
 *
 *   Description:
 *     This file contains UART test modules, main entry, to test UART APIs.
 *
 ****************************************************************************
 * Software that is described herein is for illustrative purposes only
 * which provides customers with programming information regarding the
 * products. This software is supplied "AS IS" without any warranties.
 * NXP Semiconductors assumes no responsibility or liability for the
 * use of the software, conveys no license or title under any patent,
 * copyright, or mask work right to the product. NXP Semiconductors
 * reserves the right to make changes in the software without
 * notification. NXP Semiconductors also make no representation or
 * warranty that such application will be suitable for the specified
 * use without further testing or modification.
****************************************************************************/
#include "driver_config.h"
#include "target_config.h"
#include "uart.h"
#include "gpio.h"
#include "timer32.h"
#include <stdio.h>

extern volatile uint32_t UARTCount;
extern volatile uint8_t UARTBuffer[BUFSIZE];
extern volatile uint32_t waitForINT;
// period
uint32_t slow = 100; 		// 1Hz
uint32_t medium = 50;		// 2Hz
uint32_t fast = 25; 		// 4Hz
uint32_t veryFast = 12; 	// 8Hz

// duty cycle
float d10 = .1; 	// 10%
float d25 = .25;	// 25%
float d50 = .50;	// 50%
float d75 = .75;	// 75%
float d90 = .9;		// 90%

// menus
uint32_t controlM = 0;
uint32_t freqM = 0;
uint32_t dutyM = 0;

// color
volatile uint32_t red = 1;
volatile uint32_t green = 0;
volatile uint32_t blue = 0;

volatile uint32_t onT = 50;		// on time
volatile uint32_t offT = 50;		// off time
volatile uint32_t currentT = 100;
volatile float duty = .5;		// duty cycle
volatile uint32_t ms = 0;		// time in 10ms increments
volatile uint32_t led = 0; 		// led on/off

// executes each 10ms @ 60 MHz CPU Clock
void TIMER32_0_IRQHandler(void)
{
  if ( LPC_TMR32B0->IR & 0x01 ) {
	LPC_TMR32B0->IR = 1;				/* clear interrupt flag */
	ms++;
	if(led) {
		// turn off unused colors
		GPIOSetValue(PORT2,7,0);
		GPIOSetValue(PORT2,8,0);
		if(ms < onT) {
			GPIOSetValue(PORT2,6,1);
		}
		else if(ms >= onT && ms <= currentT) {
			GPIOSetValue(PORT2,6,0);
		}
		else {
			ms = 0;
		}
	}
  }
  if ( LPC_TMR32B0->IR & (0x1<<4) ) {
	LPC_TMR32B0->IR = 0x1<<4;			/* clear interrupt flag */
  }
  return;
}

void displayMenu(int menutype){
   if(menutype == 1)
	{
		//LPC_UART->IER = IER_THRE | IER_RLS;            /* Disable RBR */
		uint8_t LED_con_menu[] = "LED Control Menu\r\n1. Blink ON\r\n2. Blink OFF\r\n3. Set Frequency\r\n4. Set Duty Cycle\r\n";
		UARTSend( (uint8_t *)LED_con_menu, sizeof(LED_con_menu) );
		//LPC_UART->IER = IER_THRE | IER_RLS | IER_RBR;    /* Re-enable RBR */
		//return 0;
	}
    else if(menutype == 2)
    {
    	LPC_UART->IER = IER_THRE | IER_RLS;            /* Disable RBR */
        uint8_t LED_freq_menu[] = "LED Frequency Menu\r\n1. Slow\r\n2. Medium\r\n3. Fast\r\n4. Very Fast\r\n5. Go Back\r\n";
        UARTSend( LED_freq_menu, sizeof(LED_freq_menu) );
       // return 0;
    }
    else if(menutype == 3)
    {
    	LPC_UART->IER = IER_THRE | IER_RLS;            /* Disable RBR */
        uint8_t LED_duty_menu[] = "LED Duty Cycle Menu\r\n1. 10\%\r\n2. 25\%\r\n3. 50\%\r\n4. 75\%\r\n5. 90\%\r\n6. Go Back\r\n";
        UARTSend( LED_duty_menu, sizeof(LED_duty_menu) );
        LPC_UART->IER = IER_THRE | IER_RLS | IER_RBR;
      //  return 0;
    }
//    else
//    {
//        uint8_t LED_duty_menu[] = "Bad menu selection\r\n";
//        UARTSend( LED_duty_menu, 24 );
//        return 1;
//    }
}

void clear() {
		uint32_t dump;
	  while (( LPC_UART->LSR & (LSR_THRE|LSR_TEMT)) != (LSR_THRE|LSR_TEMT) );
	  while ( LPC_UART->LSR & LSR_RDR )
			  {
				dump = LPC_UART->RBR;	/* Dump data from RX FIFO */
			  }
	  UARTCount = 0;
}

int main (void) {
	// gpio config
	GPIOInit();
	GPIOSetDir(PORT2,6,1);
	GPIOSetDir(PORT2,7,1);
	GPIOSetDir(PORT2,8,1);
	GPIOSetValue(PORT2,6,0); // red
	GPIOSetValue(PORT2,7,0); // green
	GPIOSetValue(PORT2,8,0); // blue

	// timer 32 config with 10ms interrupt
	init_timer32(0, TIME_INTERVAL);
	enable_timer32(0);

	/* NVIC is installed inside UARTInit file. */
	UARTInit(9600);

#if MODEM_TEST
	ModemInit();
#endif

// UART RBR register read during interrupt and characters stored in UARTBuffer
	controlM = 1;
	displayMenu(1);
	while (1) {
		if(controlM) {
			if ( UARTCount != 0 )
			{
			  LPC_UART->IER = IER_THRE | IER_RLS;			/* Disable RBR */
			  switch(UARTBuffer[0]) {
			  				case '1':
			  					led = 1;
			  					displayMenu(1);
			  					break;
			  				case '2':
			  					led = 0;
			  					displayMenu(1);
			  					break;
			  				case '3':
			  					controlM = 0;
			  					freqM = 1;
			  					displayMenu(2);
			  					break;
			  				case '4':
			  					controlM = 0;
			  					dutyM = 1;
			  					displayMenu(3);
			  					break;
			  				default:
			  					break;
			  			}
			  		}
			  UARTCount = 0;
			  LPC_UART->IER = IER_THRE | IER_RLS | IER_RBR;	/* Re-enable RBR */
			}
		else if(freqM) {
			if ( UARTCount != 0 )
			{
			  LPC_UART->IER = IER_THRE | IER_RLS;			/* Disable RBR */
				switch(UARTBuffer[0]) {
						case '1':
							currentT = slow;
							onT = currentT*duty;
							offT = currentT-onT;
							displayMenu(2);
							break;
						case '2':
							currentT = medium;
							onT = currentT*duty;
							offT = currentT-onT;
							displayMenu(2);
							break;
						case '3':
							currentT = fast;
							onT = currentT*duty;
							offT = currentT-onT;
							displayMenu(2);
							break;
						case '4':
							currentT = veryFast;
							onT = currentT*duty;
							offT = currentT-onT;
							displayMenu(2);
							break;
						case '5':
							freqM = 0;
							controlM = 1;
							displayMenu(1);
							break;
						default:
							break;
					}
			  UARTCount = 0;
			  LPC_UART->IER = IER_THRE | IER_RLS | IER_RBR;	/* Re-enable RBR */
			}
		}
		else if(dutyM) {
			if ( UARTCount != 0 )
			{
			  LPC_UART->IER = IER_THRE | IER_RLS;			/* Disable RBR */
			  switch(UARTBuffer[0]) {
			  				case '1':
			  					duty = d10;
			  					onT = currentT*duty;
			  					offT = currentT-onT;
			  					displayMenu(3);
			  					break;
			  				case '2':
			  					duty = d25;
			  					onT = currentT*duty;
			  					offT = currentT-onT;
			  					displayMenu(3);
			  					break;
			  				case '3':
			  					duty = d50;
			  					onT = currentT*duty;
			  					offT = currentT-onT;
			  					displayMenu(3);
			  					break;
			  				case '4':
			  					duty = d75;
			  					onT = currentT*duty;
			  					offT = currentT-onT;
			  					displayMenu(3);
			  					break;
			  				case '5':
			  					duty = d90;
			  					onT = currentT*duty;
			  					offT = currentT-onT;
			  					displayMenu(3);
			  					break;
			  				case '6':
			  					dutyM = 0;
			  					controlM = 1;
			  					displayMenu(1);
			  					break;
			  				default:
			  					break;
			  			}
			  UARTCount = 0;
			  LPC_UART->IER = IER_THRE | IER_RLS | IER_RBR;	/* Re-enable RBR */
			}
		}
	}
}
