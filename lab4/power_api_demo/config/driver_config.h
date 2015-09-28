/*
 * driver_config.h
 *
 *  Created on: Aug 31, 2010
 *      Author: nxp28548
 */

#ifndef DRIVER_CONFIG_H_
#define DRIVER_CONFIG_H

#include <LPC11xx.h>

#define CONFIG_ENABLE_DRIVER_CRP						1
#define CONFIG_CRP_SETTING_NO_CRP						1

#define CONFIG_ENABLE_DRIVER_ADC						0
#define CONFIG_ADC_ENABLE_ADC_IRQHANDLER				1
#define CONFIG_ADC_ENABLE_BURST_MODE					0
#define CONFIG_ADC_ENABLE_DEBUG_MODE					1

#define CONFIG_ENABLE_DRIVER_CAN						0
#define CONFIG_ENABLE_DRIVER_CLKCONFIG					0
#define CONFIG_ENABLE_DRIVER_PRINTF						0
#define CONFIG_ENABLE_DRIVER_GPIO						1
#define CONFIG_ENABLE_DRIVER_I2C						0
#define CONFIG_ENABLE_DRIVER_I2CSLAVE					0
#define CONFIG_ENABLE_DRIVER_SWUART						0
#define CONFIG_ENABLE_DRIVER_ROMCAN						0
#define CONFIG_ENABLE_DRIVER_ROMUSB						0
#define CONFIG_ENABLE_DRIVER_ROMPOWER					1
#define CONFIG_ENABLE_DRIVER_RS485						0
#define CONFIG_ENABLE_DRIVER_SMALLGPIO					0
#define CONFIG_ENABLE_DRIVER_SSP						0
#define CONFIG_ENABLE_DRIVER_TIMER16					1
#define CONFIG_ENABLE_DRIVER_TIMER32					0
#define CONFIG_ENABLE_DRIVER_UART						0
#define CONFIG_ENABLE_DRIVER_WDT						1

#define CONFIG_TIMER32_DEFAULT_TIMER32_0_IRQHANDLER		1

 /* DRIVER_CONFIG_H_ */
#endif
