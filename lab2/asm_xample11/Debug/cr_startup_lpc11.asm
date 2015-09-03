   1              		.cpu cortex-m0
   2              		.fpu softvfp
   3              		.eabi_attribute 20, 1
   4              		.eabi_attribute 21, 1
   5              		.eabi_attribute 23, 3
   6              		.eabi_attribute 24, 1
   7              		.eabi_attribute 25, 1
   8              		.eabi_attribute 26, 1
   9              		.eabi_attribute 30, 6
  10              		.eabi_attribute 34, 0
  11              		.eabi_attribute 18, 4
  12              		.code	16
  13              		.file	"cr_startup_lpc11.c"
  14              		.text
  15              	.Ltext0:
  16              		.cfi_sections	.debug_frame
  17              		.global	g_pfnVectors
  18              		.section	.isr_vector,"a",%progbits
  19              		.align	2
  22              	g_pfnVectors:
  23 0000 00000000 		.word	_vStackTop
  24 0004 00000000 		.word	ResetISR
  25 0008 00000000 		.word	NMI_Handler
  26 000c 00000000 		.word	HardFault_Handler
  27 0010 00000000 		.word	0
  28 0014 00000000 		.word	0
  29 0018 00000000 		.word	0
  30 001c 00000000 		.word	0
  31 0020 00000000 		.word	0
  32 0024 00000000 		.word	0
  33 0028 00000000 		.word	0
  34 002c 00000000 		.word	SVCall_Handler
  35 0030 00000000 		.word	0
  36 0034 00000000 		.word	0
  37 0038 00000000 		.word	PendSV_Handler
  38 003c 00000000 		.word	SysTick_Handler
  39 0040 00000000 		.word	WAKEUP_IRQHandler
  40 0044 00000000 		.word	WAKEUP_IRQHandler
  41 0048 00000000 		.word	WAKEUP_IRQHandler
  42 004c 00000000 		.word	WAKEUP_IRQHandler
  43 0050 00000000 		.word	WAKEUP_IRQHandler
  44 0054 00000000 		.word	WAKEUP_IRQHandler
  45 0058 00000000 		.word	WAKEUP_IRQHandler
  46 005c 00000000 		.word	WAKEUP_IRQHandler
  47 0060 00000000 		.word	WAKEUP_IRQHandler
  48 0064 00000000 		.word	WAKEUP_IRQHandler
  49 0068 00000000 		.word	WAKEUP_IRQHandler
  50 006c 00000000 		.word	WAKEUP_IRQHandler
  51 0070 00000000 		.word	WAKEUP_IRQHandler
  52 0074 00000000 		.word	WAKEUP_IRQHandler
  53 0078 00000000 		.word	WAKEUP_IRQHandler
  54 007c 00000000 		.word	I2C_IRQHandler
  55 0080 00000000 		.word	TIMER16_0_IRQHandler
  56 0084 00000000 		.word	TIMER16_1_IRQHandler
  57 0088 00000000 		.word	TIMER32_0_IRQHandler
  58 008c 00000000 		.word	TIMER32_1_IRQHandler
  59 0090 00000000 		.word	SSP_IRQHandler
  60 0094 00000000 		.word	UART_IRQHandler
  61 0098 00000000 		.word	USB_IRQHandler
  62 009c 00000000 		.word	USB_FIQHandler
  63 00a0 00000000 		.word	ADC_IRQHandler
  64 00a4 00000000 		.word	WDT_IRQHandler
  65 00a8 00000000 		.word	BOD_IRQHandler
  66 00ac 00000000 		.word	FMC_IRQHandler
  67 00b0 00000000 		.word	PIOINT3_IRQHandler
  68 00b4 00000000 		.word	PIOINT2_IRQHandler
  69 00b8 00000000 		.word	PIOINT1_IRQHandler
  70 00bc 00000000 		.word	PIOINT0_IRQHandler
  71              		.section	.text.Reset_Handler,"ax",%progbits
  72              		.align	2
  73              		.global	Reset_Handler
  74              		.code	16
  75              		.thumb_func
  77              	Reset_Handler:
  78              	.LFB0:
  79              		.file 1 "../src/cr_startup_lpc11.c"
   1:../src/cr_startup_lpc11.c **** //*****************************************************************************
   2:../src/cr_startup_lpc11.c **** //   +--+       
   3:../src/cr_startup_lpc11.c **** //   | ++----+   
   4:../src/cr_startup_lpc11.c **** //   +-++    |  
   5:../src/cr_startup_lpc11.c **** //     |     |  
   6:../src/cr_startup_lpc11.c **** //   +-+--+  |   
   7:../src/cr_startup_lpc11.c **** //   | +--+--+  
   8:../src/cr_startup_lpc11.c **** //   +----+    Copyright (c) 2009 Code Red Technologies Ltd. 
   9:../src/cr_startup_lpc11.c **** //
  10:../src/cr_startup_lpc11.c **** // Microcontroller Startup code for use with Red Suite
  11:../src/cr_startup_lpc11.c **** //
  12:../src/cr_startup_lpc11.c **** // Software License Agreement
  13:../src/cr_startup_lpc11.c **** // 
  14:../src/cr_startup_lpc11.c **** // The software is owned by Code Red Technologies and/or its suppliers, and is 
  15:../src/cr_startup_lpc11.c **** // protected under applicable copyright laws.  All rights are reserved.  Any 
  16:../src/cr_startup_lpc11.c **** // use in violation of the foregoing restrictions may subject the user to criminal 
  17:../src/cr_startup_lpc11.c **** // sanctions under applicable laws, as well as to civil liability for the breach 
  18:../src/cr_startup_lpc11.c **** // of the terms and conditions of this license.
  19:../src/cr_startup_lpc11.c **** // 
  20:../src/cr_startup_lpc11.c **** // THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
  21:../src/cr_startup_lpc11.c **** // OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
  22:../src/cr_startup_lpc11.c **** // MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
  23:../src/cr_startup_lpc11.c **** // USE OF THIS SOFTWARE FOR COMMERCIAL DEVELOPMENT AND/OR EDUCATION IS SUBJECT
  24:../src/cr_startup_lpc11.c **** // TO A CURRENT END USER LICENSE AGREEMENT (COMMERCIAL OR EDUCATIONAL) WITH
  25:../src/cr_startup_lpc11.c **** // CODE RED TECHNOLOGIES LTD. 
  26:../src/cr_startup_lpc11.c **** //
  27:../src/cr_startup_lpc11.c **** //*****************************************************************************
  28:../src/cr_startup_lpc11.c **** #define WEAK __attribute__ ((weak))
  29:../src/cr_startup_lpc11.c **** #define ALIAS(f) __attribute__ ((weak, alias (#f)))
  30:../src/cr_startup_lpc11.c **** 
  31:../src/cr_startup_lpc11.c **** // Code Red - if CMSIS is being used, then SystemInit() routine
  32:../src/cr_startup_lpc11.c **** // will be called by startup code rather than in application's main()
  33:../src/cr_startup_lpc11.c **** #ifdef __USE_CMSIS
  34:../src/cr_startup_lpc11.c **** #include "system_LPC11xx.h"
  35:../src/cr_startup_lpc11.c **** #endif
  36:../src/cr_startup_lpc11.c **** 
  37:../src/cr_startup_lpc11.c **** //*****************************************************************************
  38:../src/cr_startup_lpc11.c **** //
  39:../src/cr_startup_lpc11.c **** // Forward declaration of the default handlers. These are aliased.
  40:../src/cr_startup_lpc11.c **** // When the application defines a handler (with the same name), this will 
  41:../src/cr_startup_lpc11.c **** // automatically take precedence over these weak definitions
  42:../src/cr_startup_lpc11.c **** //
  43:../src/cr_startup_lpc11.c **** //*****************************************************************************
  44:../src/cr_startup_lpc11.c ****      void Reset_Handler(void);
  45:../src/cr_startup_lpc11.c ****      void ResetISR(void) ALIAS(Reset_Handler);
  46:../src/cr_startup_lpc11.c **** WEAK void NMI_Handler(void);
  47:../src/cr_startup_lpc11.c **** WEAK void HardFault_Handler(void);
  48:../src/cr_startup_lpc11.c **** WEAK void SVCall_Handler(void);
  49:../src/cr_startup_lpc11.c **** WEAK void PendSV_Handler(void);
  50:../src/cr_startup_lpc11.c **** WEAK void SysTick_Handler(void);
  51:../src/cr_startup_lpc11.c **** 
  52:../src/cr_startup_lpc11.c **** //*****************************************************************************
  53:../src/cr_startup_lpc11.c **** //
  54:../src/cr_startup_lpc11.c **** // Forward declaration of the specific IRQ handlers. These are aliased
  55:../src/cr_startup_lpc11.c **** // to the IntDefaultHandler, which is a 'forever' loop. When the application
  56:../src/cr_startup_lpc11.c **** // defines a handler (with the same name), this will automatically take
  57:../src/cr_startup_lpc11.c **** // precedence over these weak definitions
  58:../src/cr_startup_lpc11.c **** //
  59:../src/cr_startup_lpc11.c **** //*****************************************************************************
  60:../src/cr_startup_lpc11.c **** 
  61:../src/cr_startup_lpc11.c **** void I2C_IRQHandler (void) ALIAS(IntDefaultHandler);
  62:../src/cr_startup_lpc11.c **** void TIMER16_0_IRQHandler (void) ALIAS(IntDefaultHandler);
  63:../src/cr_startup_lpc11.c **** void TIMER16_1_IRQHandler (void) ALIAS(IntDefaultHandler);
  64:../src/cr_startup_lpc11.c **** void TIMER32_0_IRQHandler (void) ALIAS(IntDefaultHandler);
  65:../src/cr_startup_lpc11.c **** void TIMER32_1_IRQHandler (void) ALIAS(IntDefaultHandler);
  66:../src/cr_startup_lpc11.c **** void SSP_IRQHandler (void) ALIAS(IntDefaultHandler);
  67:../src/cr_startup_lpc11.c **** void UART_IRQHandler (void) ALIAS(IntDefaultHandler);
  68:../src/cr_startup_lpc11.c **** void USB_IRQHandler (void) ALIAS(IntDefaultHandler);
  69:../src/cr_startup_lpc11.c **** void USB_FIQHandler (void) ALIAS(IntDefaultHandler);
  70:../src/cr_startup_lpc11.c **** void ADC_IRQHandler (void) ALIAS(IntDefaultHandler);
  71:../src/cr_startup_lpc11.c **** void WDT_IRQHandler (void) ALIAS(IntDefaultHandler);
  72:../src/cr_startup_lpc11.c **** void BOD_IRQHandler (void) ALIAS(IntDefaultHandler);
  73:../src/cr_startup_lpc11.c **** void FMC_IRQHandler (void) ALIAS(IntDefaultHandler);
  74:../src/cr_startup_lpc11.c **** void PIOINT3_IRQHandler (void) ALIAS(IntDefaultHandler);
  75:../src/cr_startup_lpc11.c **** void PIOINT2_IRQHandler (void) ALIAS(IntDefaultHandler);
  76:../src/cr_startup_lpc11.c **** void PIOINT1_IRQHandler (void) ALIAS(IntDefaultHandler);
  77:../src/cr_startup_lpc11.c **** void PIOINT0_IRQHandler (void) ALIAS(IntDefaultHandler);
  78:../src/cr_startup_lpc11.c **** void WAKEUP_IRQHandler  (void) ALIAS(IntDefaultHandler);
  79:../src/cr_startup_lpc11.c **** 
  80:../src/cr_startup_lpc11.c **** //*****************************************************************************
  81:../src/cr_startup_lpc11.c **** //
  82:../src/cr_startup_lpc11.c **** // The entry point for the application.
  83:../src/cr_startup_lpc11.c **** // __main() is the entry point for redlib based applications
  84:../src/cr_startup_lpc11.c **** // main() is the entry point for newlib based applications
  85:../src/cr_startup_lpc11.c **** //
  86:../src/cr_startup_lpc11.c **** //*****************************************************************************
  87:../src/cr_startup_lpc11.c **** extern WEAK void __main(void);
  88:../src/cr_startup_lpc11.c **** extern WEAK void main(void);
  89:../src/cr_startup_lpc11.c **** //*****************************************************************************
  90:../src/cr_startup_lpc11.c **** //
  91:../src/cr_startup_lpc11.c **** // External declaration for the pointer to the stack top from the Linker Script
  92:../src/cr_startup_lpc11.c **** //
  93:../src/cr_startup_lpc11.c **** //*****************************************************************************
  94:../src/cr_startup_lpc11.c **** extern void _vStackTop;
  95:../src/cr_startup_lpc11.c **** 
  96:../src/cr_startup_lpc11.c **** //*****************************************************************************
  97:../src/cr_startup_lpc11.c **** //
  98:../src/cr_startup_lpc11.c **** // The vector table.  Note that the proper constructs must be placed on this to
  99:../src/cr_startup_lpc11.c **** // ensure that it ends up at physical address 0x0000.0000.
 100:../src/cr_startup_lpc11.c **** //
 101:../src/cr_startup_lpc11.c **** //*****************************************************************************
 102:../src/cr_startup_lpc11.c **** __attribute__ ((section(".isr_vector")))
 103:../src/cr_startup_lpc11.c **** void (* const g_pfnVectors[])(void) =
 104:../src/cr_startup_lpc11.c **** {
 105:../src/cr_startup_lpc11.c ****     (void *)&_vStackTop,		    		// The initial stack pointer
 106:../src/cr_startup_lpc11.c ****     ResetISR,                               // The reset handler
 107:../src/cr_startup_lpc11.c ****     NMI_Handler,                            // The NMI handler
 108:../src/cr_startup_lpc11.c ****     HardFault_Handler,                      // The hard fault handler
 109:../src/cr_startup_lpc11.c ****     0,                      				// Reserved
 110:../src/cr_startup_lpc11.c ****     0,                      				// Reserved
 111:../src/cr_startup_lpc11.c ****     0,                      				// Reserved
 112:../src/cr_startup_lpc11.c ****     0,                                      // Reserved
 113:../src/cr_startup_lpc11.c ****     0,                                      // Reserved
 114:../src/cr_startup_lpc11.c ****     0,                                      // Reserved
 115:../src/cr_startup_lpc11.c ****     0,                                      // Reserved
 116:../src/cr_startup_lpc11.c ****     SVCall_Handler,                      	// SVCall handler
 117:../src/cr_startup_lpc11.c ****     0,                      				// Reserved
 118:../src/cr_startup_lpc11.c ****     0,                                      // Reserved
 119:../src/cr_startup_lpc11.c ****     PendSV_Handler,                      	// The PendSV handler
 120:../src/cr_startup_lpc11.c ****     SysTick_Handler,                      	// The SysTick handler
 121:../src/cr_startup_lpc11.c **** 
 122:../src/cr_startup_lpc11.c ****     // Wakeup sources (15 ea.) for the I/O pins:
 123:../src/cr_startup_lpc11.c ****     //   PIO0 (0:11)
 124:../src/cr_startup_lpc11.c ****     //   PIO1 (0:2)
 125:../src/cr_startup_lpc11.c ****     WAKEUP_IRQHandler,                      // PIO0_0  Wakeup
 126:../src/cr_startup_lpc11.c ****     WAKEUP_IRQHandler,                      // PIO0_1  Wakeup
 127:../src/cr_startup_lpc11.c ****     WAKEUP_IRQHandler,                      // PIO0_2  Wakeup
 128:../src/cr_startup_lpc11.c ****     WAKEUP_IRQHandler,                      // PIO0_3  Wakeup
 129:../src/cr_startup_lpc11.c ****     WAKEUP_IRQHandler,                      // PIO0_4  Wakeup
 130:../src/cr_startup_lpc11.c ****     WAKEUP_IRQHandler,                      // PIO0_5  Wakeup
 131:../src/cr_startup_lpc11.c ****     WAKEUP_IRQHandler,                      // PIO0_6  Wakeup
 132:../src/cr_startup_lpc11.c ****     WAKEUP_IRQHandler,                      // PIO0_7  Wakeup
 133:../src/cr_startup_lpc11.c ****     WAKEUP_IRQHandler,                      // PIO0_8  Wakeup
 134:../src/cr_startup_lpc11.c ****     WAKEUP_IRQHandler,                      // PIO0_9  Wakeup
 135:../src/cr_startup_lpc11.c ****     WAKEUP_IRQHandler,                      // PIO0_10 Wakeup
 136:../src/cr_startup_lpc11.c ****     WAKEUP_IRQHandler,                      // PIO0_11 Wakeup
 137:../src/cr_startup_lpc11.c ****     WAKEUP_IRQHandler,                      // PIO1_0  Wakeup
 138:../src/cr_startup_lpc11.c ****     WAKEUP_IRQHandler,                      // PIO1_1  Wakeup
 139:../src/cr_startup_lpc11.c ****     WAKEUP_IRQHandler,                      // PIO1_2  Wakeup
 140:../src/cr_startup_lpc11.c ****     
 141:../src/cr_startup_lpc11.c ****     I2C_IRQHandler,                      	// I2C0
 142:../src/cr_startup_lpc11.c ****     TIMER16_0_IRQHandler,                   // CT16B0 (16-bit Timer 0)
 143:../src/cr_startup_lpc11.c ****     TIMER16_1_IRQHandler,                   // CT16B1 (16-bit Timer 1)
 144:../src/cr_startup_lpc11.c ****     TIMER32_0_IRQHandler,                   // CT32B0 (32-bit Timer 0)
 145:../src/cr_startup_lpc11.c ****     TIMER32_1_IRQHandler,                   // CT32B1 (32-bit Timer 1)
 146:../src/cr_startup_lpc11.c ****     SSP_IRQHandler,                      	// SSP0
 147:../src/cr_startup_lpc11.c ****     UART_IRQHandler,                      	// UART0
 148:../src/cr_startup_lpc11.c **** 
 149:../src/cr_startup_lpc11.c ****     USB_IRQHandler,                      	// USB IRQ
 150:../src/cr_startup_lpc11.c ****     USB_FIQHandler,                      	// USB FIQ
 151:../src/cr_startup_lpc11.c **** 
 152:../src/cr_startup_lpc11.c ****     ADC_IRQHandler,                      	// ADC   (A/D Converter)
 153:../src/cr_startup_lpc11.c ****     WDT_IRQHandler,                      	// WDT   (Watchdog Timer)
 154:../src/cr_startup_lpc11.c ****     BOD_IRQHandler,                      	// BOD   (Brownout Detect)
 155:../src/cr_startup_lpc11.c ****     FMC_IRQHandler,                      	// Flash (IP2111 Flash Memory Controller)
 156:../src/cr_startup_lpc11.c ****     PIOINT3_IRQHandler,                     // PIO INT3
 157:../src/cr_startup_lpc11.c ****     PIOINT2_IRQHandler,                     // PIO INT2
 158:../src/cr_startup_lpc11.c ****     PIOINT1_IRQHandler,                     // PIO INT1
 159:../src/cr_startup_lpc11.c ****     PIOINT0_IRQHandler,                     // PIO INT0
 160:../src/cr_startup_lpc11.c **** };
 161:../src/cr_startup_lpc11.c **** 
 162:../src/cr_startup_lpc11.c **** //*****************************************************************************
 163:../src/cr_startup_lpc11.c **** //
 164:../src/cr_startup_lpc11.c **** // The following are constructs created by the linker, indicating where the
 165:../src/cr_startup_lpc11.c **** // the "data" and "bss" segments reside in memory.  The initializers for the
 166:../src/cr_startup_lpc11.c **** // for the "data" segment resides immediately following the "text" segment.
 167:../src/cr_startup_lpc11.c **** //
 168:../src/cr_startup_lpc11.c **** //*****************************************************************************
 169:../src/cr_startup_lpc11.c **** extern unsigned char _etext;
 170:../src/cr_startup_lpc11.c **** extern unsigned char _data;
 171:../src/cr_startup_lpc11.c **** extern unsigned char _edata;
 172:../src/cr_startup_lpc11.c **** extern unsigned char _bss;
 173:../src/cr_startup_lpc11.c **** extern unsigned char _ebss;
 174:../src/cr_startup_lpc11.c **** 
 175:../src/cr_startup_lpc11.c **** //*****************************************************************************
 176:../src/cr_startup_lpc11.c **** //
 177:../src/cr_startup_lpc11.c **** // This is the code that gets called when the processor first starts execution
 178:../src/cr_startup_lpc11.c **** // following a reset event.  Only the absolutely necessary set is performed,
 179:../src/cr_startup_lpc11.c **** // after which the application supplied entry() routine is called.  Any fancy
 180:../src/cr_startup_lpc11.c **** // actions (such as making decisions based on the reset cause register, and
 181:../src/cr_startup_lpc11.c **** // resetting the bits in that register) are left solely in the hands of the
 182:../src/cr_startup_lpc11.c **** // application.
 183:../src/cr_startup_lpc11.c **** //
 184:../src/cr_startup_lpc11.c **** //*****************************************************************************
 185:../src/cr_startup_lpc11.c **** void Reset_Handler(void)
 186:../src/cr_startup_lpc11.c **** {
  80              		.loc 1 186 0
  81              		.cfi_startproc
  82 0000 80B5     		push	{r7, lr}
  83              		.cfi_def_cfa_offset 8
  84              		.cfi_offset 7, -8
  85              		.cfi_offset 14, -4
  86 0002 82B0     		sub	sp, sp, #8
  87              		.cfi_def_cfa_offset 16
  88 0004 00AF     		add	r7, sp, #0
  89              		.cfi_def_cfa_register 7
 187:../src/cr_startup_lpc11.c ****     unsigned char *pulSrc, *pulDest;
 188:../src/cr_startup_lpc11.c **** 
 189:../src/cr_startup_lpc11.c ****     //
 190:../src/cr_startup_lpc11.c ****     // Copy the data segment initializers from flash to SRAM.
 191:../src/cr_startup_lpc11.c ****     //
 192:../src/cr_startup_lpc11.c ****     pulSrc = &_etext;
  90              		.loc 1 192 0
  91 0006 134B     		ldr	r3, .L8
  92 0008 7B60     		str	r3, [r7, #4]
 193:../src/cr_startup_lpc11.c ****     for(pulDest = &_data; pulDest < &_edata; )
  93              		.loc 1 193 0
  94 000a 134B     		ldr	r3, .L8+4
  95 000c 3B60     		str	r3, [r7]
  96 000e 07E0     		b	.L2
  97              	.L3:
 194:../src/cr_startup_lpc11.c ****     {
 195:../src/cr_startup_lpc11.c ****         *pulDest++ = *pulSrc++;
  98              		.loc 1 195 0
  99 0010 3B68     		ldr	r3, [r7]
 100 0012 5A1C     		add	r2, r3, #1
 101 0014 3A60     		str	r2, [r7]
 102 0016 7A68     		ldr	r2, [r7, #4]
 103 0018 511C     		add	r1, r2, #1
 104 001a 7960     		str	r1, [r7, #4]
 105 001c 1278     		ldrb	r2, [r2]
 106 001e 1A70     		strb	r2, [r3]
 107              	.L2:
 193:../src/cr_startup_lpc11.c ****     for(pulDest = &_data; pulDest < &_edata; )
 108              		.loc 1 193 0 discriminator 1
 109 0020 3A68     		ldr	r2, [r7]
 110 0022 0E4B     		ldr	r3, .L8+8
 111 0024 9A42     		cmp	r2, r3
 112 0026 F3D3     		bcc	.L3
 196:../src/cr_startup_lpc11.c ****     }
 197:../src/cr_startup_lpc11.c **** 
 198:../src/cr_startup_lpc11.c ****     //
 199:../src/cr_startup_lpc11.c ****     // Zero fill the bss segment.
 200:../src/cr_startup_lpc11.c ****     //
 201:../src/cr_startup_lpc11.c **** 	for(pulDest = &_bss; pulDest < &_ebss; pulDest++)
 113              		.loc 1 201 0
 114 0028 0D4B     		ldr	r3, .L8+12
 115 002a 3B60     		str	r3, [r7]
 116 002c 05E0     		b	.L4
 117              	.L5:
 202:../src/cr_startup_lpc11.c **** 	  *pulDest = 0;
 118              		.loc 1 202 0 discriminator 3
 119 002e 3B68     		ldr	r3, [r7]
 120 0030 0022     		mov	r2, #0
 121 0032 1A70     		strb	r2, [r3]
 201:../src/cr_startup_lpc11.c **** 	  *pulDest = 0;
 122              		.loc 1 201 0 discriminator 3
 123 0034 3B68     		ldr	r3, [r7]
 124 0036 0133     		add	r3, r3, #1
 125 0038 3B60     		str	r3, [r7]
 126              	.L4:
 201:../src/cr_startup_lpc11.c **** 	  *pulDest = 0;
 127              		.loc 1 201 0 is_stmt 0 discriminator 1
 128 003a 3A68     		ldr	r2, [r7]
 129 003c 094B     		ldr	r3, .L8+16
 130 003e 9A42     		cmp	r2, r3
 131 0040 F5D3     		bcc	.L5
 203:../src/cr_startup_lpc11.c **** 
 204:../src/cr_startup_lpc11.c **** #ifdef __USE_CMSIS
 205:../src/cr_startup_lpc11.c **** 	SystemInit();
 206:../src/cr_startup_lpc11.c **** #endif
 207:../src/cr_startup_lpc11.c **** 	//
 208:../src/cr_startup_lpc11.c **** 	// Call the application's entry point.
 209:../src/cr_startup_lpc11.c **** 	// __main() is the entry point for redlib based applications (which calls main())
 210:../src/cr_startup_lpc11.c **** 	// main() is the entry point for newlib based applications
 211:../src/cr_startup_lpc11.c **** 	//
 212:../src/cr_startup_lpc11.c **** 	if (__main)
 132              		.loc 1 212 0 is_stmt 1
 133 0042 094B     		ldr	r3, .L8+20
 134 0044 002B     		cmp	r3, #0
 135 0046 02D0     		beq	.L6
 213:../src/cr_startup_lpc11.c **** 		__main() ;
 136              		.loc 1 213 0
 137 0048 FFF7FEFF 		bl	__main
 138 004c 01E0     		b	.L7
 139              	.L6:
 214:../src/cr_startup_lpc11.c **** 	else
 215:../src/cr_startup_lpc11.c **** 		main() ;
 140              		.loc 1 215 0
 141 004e FFF7FEFF 		bl	main
 142              	.L7:
 216:../src/cr_startup_lpc11.c **** 
 217:../src/cr_startup_lpc11.c **** 	//
 218:../src/cr_startup_lpc11.c **** 	// main() shouldn't return, but if it does, we'll just enter an infinite loop 
 219:../src/cr_startup_lpc11.c **** 	//
 220:../src/cr_startup_lpc11.c **** 	while (1) {
 221:../src/cr_startup_lpc11.c **** 		;
 222:../src/cr_startup_lpc11.c **** 	}
 143              		.loc 1 222 0 discriminator 1
 144 0052 FEE7     		b	.L7
 145              	.L9:
 146              		.align	2
 147              	.L8:
 148 0054 00000000 		.word	_etext
 149 0058 00000000 		.word	_data
 150 005c 00000000 		.word	_edata
 151 0060 00000000 		.word	_bss
 152 0064 00000000 		.word	_ebss
 153 0068 00000000 		.word	__main
 154              		.cfi_endproc
 155              	.LFE0:
 157              		.weak	ResetISR
 158              		.thumb_set ResetISR,Reset_Handler
 159              		.section	.text.NMI_Handler,"ax",%progbits
 160              		.align	2
 161              		.weak	NMI_Handler
 162              		.code	16
 163              		.thumb_func
 165              	NMI_Handler:
 166              	.LFB1:
 223:../src/cr_startup_lpc11.c **** }
 224:../src/cr_startup_lpc11.c **** 
 225:../src/cr_startup_lpc11.c **** //*****************************************************************************
 226:../src/cr_startup_lpc11.c **** //
 227:../src/cr_startup_lpc11.c **** // This is the code that gets called when the processor receives a NMI.  This
 228:../src/cr_startup_lpc11.c **** // simply enters an infinite loop, preserving the system state for examination
 229:../src/cr_startup_lpc11.c **** // by a debugger.
 230:../src/cr_startup_lpc11.c **** //
 231:../src/cr_startup_lpc11.c **** //*****************************************************************************
 232:../src/cr_startup_lpc11.c **** void NMI_Handler(void)
 233:../src/cr_startup_lpc11.c **** {
 167              		.loc 1 233 0
 168              		.cfi_startproc
 169 0000 80B5     		push	{r7, lr}
 170              		.cfi_def_cfa_offset 8
 171              		.cfi_offset 7, -8
 172              		.cfi_offset 14, -4
 173 0002 00AF     		add	r7, sp, #0
 174              		.cfi_def_cfa_register 7
 175              	.L11:
 234:../src/cr_startup_lpc11.c ****     //
 235:../src/cr_startup_lpc11.c ****     // Enter an infinite loop.
 236:../src/cr_startup_lpc11.c ****     //
 237:../src/cr_startup_lpc11.c ****     while(1)
 238:../src/cr_startup_lpc11.c ****     {
 239:../src/cr_startup_lpc11.c ****     }
 176              		.loc 1 239 0 discriminator 1
 177 0004 FEE7     		b	.L11
 178              		.cfi_endproc
 179              	.LFE1:
 181 0006 C046     		.section	.text.HardFault_Handler,"ax",%progbits
 182              		.align	2
 183              		.weak	HardFault_Handler
 184              		.code	16
 185              		.thumb_func
 187              	HardFault_Handler:
 188              	.LFB2:
 240:../src/cr_startup_lpc11.c **** }
 241:../src/cr_startup_lpc11.c **** 
 242:../src/cr_startup_lpc11.c **** //*****************************************************************************
 243:../src/cr_startup_lpc11.c **** //
 244:../src/cr_startup_lpc11.c **** // This is the code that gets called when the processor receives a fault
 245:../src/cr_startup_lpc11.c **** // interrupt.  This simply enters an infinite loop, preserving the system state
 246:../src/cr_startup_lpc11.c **** // for examination by a debugger.
 247:../src/cr_startup_lpc11.c **** //
 248:../src/cr_startup_lpc11.c **** //*****************************************************************************
 249:../src/cr_startup_lpc11.c **** void HardFault_Handler(void)
 250:../src/cr_startup_lpc11.c **** {
 189              		.loc 1 250 0
 190              		.cfi_startproc
 191 0000 80B5     		push	{r7, lr}
 192              		.cfi_def_cfa_offset 8
 193              		.cfi_offset 7, -8
 194              		.cfi_offset 14, -4
 195 0002 00AF     		add	r7, sp, #0
 196              		.cfi_def_cfa_register 7
 197              	.L13:
 251:../src/cr_startup_lpc11.c ****     //
 252:../src/cr_startup_lpc11.c ****     // Enter an infinite loop.
 253:../src/cr_startup_lpc11.c ****     //
 254:../src/cr_startup_lpc11.c ****     while(1)
 255:../src/cr_startup_lpc11.c ****     {
 256:../src/cr_startup_lpc11.c ****     }
 198              		.loc 1 256 0 discriminator 1
 199 0004 FEE7     		b	.L13
 200              		.cfi_endproc
 201              	.LFE2:
 203 0006 C046     		.section	.text.SVCall_Handler,"ax",%progbits
 204              		.align	2
 205              		.weak	SVCall_Handler
 206              		.code	16
 207              		.thumb_func
 209              	SVCall_Handler:
 210              	.LFB3:
 257:../src/cr_startup_lpc11.c **** }
 258:../src/cr_startup_lpc11.c **** 
 259:../src/cr_startup_lpc11.c **** void SVCall_Handler(void)
 260:../src/cr_startup_lpc11.c **** {
 211              		.loc 1 260 0
 212              		.cfi_startproc
 213 0000 80B5     		push	{r7, lr}
 214              		.cfi_def_cfa_offset 8
 215              		.cfi_offset 7, -8
 216              		.cfi_offset 14, -4
 217 0002 00AF     		add	r7, sp, #0
 218              		.cfi_def_cfa_register 7
 219              	.L15:
 261:../src/cr_startup_lpc11.c ****     while(1)
 262:../src/cr_startup_lpc11.c ****     {
 263:../src/cr_startup_lpc11.c ****     }
 220              		.loc 1 263 0 discriminator 1
 221 0004 FEE7     		b	.L15
 222              		.cfi_endproc
 223              	.LFE3:
 225 0006 C046     		.section	.text.PendSV_Handler,"ax",%progbits
 226              		.align	2
 227              		.weak	PendSV_Handler
 228              		.code	16
 229              		.thumb_func
 231              	PendSV_Handler:
 232              	.LFB4:
 264:../src/cr_startup_lpc11.c **** }
 265:../src/cr_startup_lpc11.c **** 
 266:../src/cr_startup_lpc11.c **** void PendSV_Handler(void)
 267:../src/cr_startup_lpc11.c **** {
 233              		.loc 1 267 0
 234              		.cfi_startproc
 235 0000 80B5     		push	{r7, lr}
 236              		.cfi_def_cfa_offset 8
 237              		.cfi_offset 7, -8
 238              		.cfi_offset 14, -4
 239 0002 00AF     		add	r7, sp, #0
 240              		.cfi_def_cfa_register 7
 241              	.L17:
 268:../src/cr_startup_lpc11.c ****     while(1)
 269:../src/cr_startup_lpc11.c ****     {
 270:../src/cr_startup_lpc11.c ****     }
 242              		.loc 1 270 0 discriminator 1
 243 0004 FEE7     		b	.L17
 244              		.cfi_endproc
 245              	.LFE4:
 247 0006 C046     		.section	.text.SysTick_Handler,"ax",%progbits
 248              		.align	2
 249              		.weak	SysTick_Handler
 250              		.code	16
 251              		.thumb_func
 253              	SysTick_Handler:
 254              	.LFB5:
 271:../src/cr_startup_lpc11.c **** }
 272:../src/cr_startup_lpc11.c **** 
 273:../src/cr_startup_lpc11.c **** void SysTick_Handler(void)
 274:../src/cr_startup_lpc11.c **** {
 255              		.loc 1 274 0
 256              		.cfi_startproc
 257 0000 80B5     		push	{r7, lr}
 258              		.cfi_def_cfa_offset 8
 259              		.cfi_offset 7, -8
 260              		.cfi_offset 14, -4
 261 0002 00AF     		add	r7, sp, #0
 262              		.cfi_def_cfa_register 7
 263              	.L19:
 275:../src/cr_startup_lpc11.c ****     while(1)
 276:../src/cr_startup_lpc11.c ****     {
 277:../src/cr_startup_lpc11.c ****     }
 264              		.loc 1 277 0 discriminator 1
 265 0004 FEE7     		b	.L19
 266              		.cfi_endproc
 267              	.LFE5:
 269 0006 C046     		.section	.text.IntDefaultHandler,"ax",%progbits
 270              		.align	2
 271              		.global	IntDefaultHandler
 272              		.code	16
 273              		.thumb_func
 275              	IntDefaultHandler:
 276              	.LFB6:
 278:../src/cr_startup_lpc11.c **** }
 279:../src/cr_startup_lpc11.c **** 
 280:../src/cr_startup_lpc11.c **** 
 281:../src/cr_startup_lpc11.c **** 
 282:../src/cr_startup_lpc11.c **** //*****************************************************************************
 283:../src/cr_startup_lpc11.c **** //
 284:../src/cr_startup_lpc11.c **** // This is the code that gets called when the processor receives an unexpected
 285:../src/cr_startup_lpc11.c **** // interrupt.  This simply enters an infinite loop, preserving the system state
 286:../src/cr_startup_lpc11.c **** // for examination by a debugger.
 287:../src/cr_startup_lpc11.c **** //
 288:../src/cr_startup_lpc11.c **** //*****************************************************************************
 289:../src/cr_startup_lpc11.c **** void IntDefaultHandler(void)
 290:../src/cr_startup_lpc11.c **** {
 277              		.loc 1 290 0
 278              		.cfi_startproc
 279 0000 80B5     		push	{r7, lr}
 280              		.cfi_def_cfa_offset 8
 281              		.cfi_offset 7, -8
 282              		.cfi_offset 14, -4
 283 0002 00AF     		add	r7, sp, #0
 284              		.cfi_def_cfa_register 7
 285              	.L21:
 291:../src/cr_startup_lpc11.c ****     //
 292:../src/cr_startup_lpc11.c ****     // Go into an infinite loop.
 293:../src/cr_startup_lpc11.c ****     //
 294:../src/cr_startup_lpc11.c ****     while(1)
 295:../src/cr_startup_lpc11.c ****     {
 296:../src/cr_startup_lpc11.c ****     }
 286              		.loc 1 296 0 discriminator 1
 287 0004 FEE7     		b	.L21
 288              		.cfi_endproc
 289              	.LFE6:
 291              		.weak	I2C_IRQHandler
 292              		.thumb_set I2C_IRQHandler,IntDefaultHandler
 293              		.weak	TIMER16_0_IRQHandler
 294              		.thumb_set TIMER16_0_IRQHandler,IntDefaultHandler
 295              		.weak	TIMER16_1_IRQHandler
 296              		.thumb_set TIMER16_1_IRQHandler,IntDefaultHandler
 297              		.weak	TIMER32_0_IRQHandler
 298              		.thumb_set TIMER32_0_IRQHandler,IntDefaultHandler
 299              		.weak	TIMER32_1_IRQHandler
 300              		.thumb_set TIMER32_1_IRQHandler,IntDefaultHandler
 301              		.weak	SSP_IRQHandler
 302              		.thumb_set SSP_IRQHandler,IntDefaultHandler
 303              		.weak	UART_IRQHandler
 304              		.thumb_set UART_IRQHandler,IntDefaultHandler
 305              		.weak	USB_IRQHandler
 306              		.thumb_set USB_IRQHandler,IntDefaultHandler
 307              		.weak	USB_FIQHandler
 308              		.thumb_set USB_FIQHandler,IntDefaultHandler
 309              		.weak	ADC_IRQHandler
 310              		.thumb_set ADC_IRQHandler,IntDefaultHandler
 311              		.weak	WDT_IRQHandler
 312              		.thumb_set WDT_IRQHandler,IntDefaultHandler
 313              		.weak	BOD_IRQHandler
 314              		.thumb_set BOD_IRQHandler,IntDefaultHandler
 315              		.weak	FMC_IRQHandler
 316              		.thumb_set FMC_IRQHandler,IntDefaultHandler
 317              		.weak	PIOINT3_IRQHandler
 318              		.thumb_set PIOINT3_IRQHandler,IntDefaultHandler
 319              		.weak	PIOINT2_IRQHandler
 320              		.thumb_set PIOINT2_IRQHandler,IntDefaultHandler
 321              		.weak	PIOINT1_IRQHandler
 322              		.thumb_set PIOINT1_IRQHandler,IntDefaultHandler
 323              		.weak	PIOINT0_IRQHandler
 324              		.thumb_set PIOINT0_IRQHandler,IntDefaultHandler
 325              		.weak	WAKEUP_IRQHandler
 326              		.thumb_set WAKEUP_IRQHandler,IntDefaultHandler
 327              		.weak	main
 328              		.weak	__main
 329 0006 C046     		.text
 330              	.Letext0:
DEFINED SYMBOLS
                            *ABS*:0000000000000000 cr_startup_lpc11.c
/var/folders/f1/yf6vpc4d7rv1qk99nz_3kyd00000gn/T//ccQ0MlPv.s:22     .isr_vector:0000000000000000 g_pfnVectors
/var/folders/f1/yf6vpc4d7rv1qk99nz_3kyd00000gn/T//ccQ0MlPv.s:19     .isr_vector:0000000000000000 $d
/var/folders/f1/yf6vpc4d7rv1qk99nz_3kyd00000gn/T//ccQ0MlPv.s:77     .text.Reset_Handler:0000000000000000 ResetISR
/var/folders/f1/yf6vpc4d7rv1qk99nz_3kyd00000gn/T//ccQ0MlPv.s:165    .text.NMI_Handler:0000000000000000 NMI_Handler
/var/folders/f1/yf6vpc4d7rv1qk99nz_3kyd00000gn/T//ccQ0MlPv.s:187    .text.HardFault_Handler:0000000000000000 HardFault_Handler
/var/folders/f1/yf6vpc4d7rv1qk99nz_3kyd00000gn/T//ccQ0MlPv.s:209    .text.SVCall_Handler:0000000000000000 SVCall_Handler
/var/folders/f1/yf6vpc4d7rv1qk99nz_3kyd00000gn/T//ccQ0MlPv.s:231    .text.PendSV_Handler:0000000000000000 PendSV_Handler
/var/folders/f1/yf6vpc4d7rv1qk99nz_3kyd00000gn/T//ccQ0MlPv.s:253    .text.SysTick_Handler:0000000000000000 SysTick_Handler
/var/folders/f1/yf6vpc4d7rv1qk99nz_3kyd00000gn/T//ccQ0MlPv.s:275    .text.IntDefaultHandler:0000000000000000 WAKEUP_IRQHandler
/var/folders/f1/yf6vpc4d7rv1qk99nz_3kyd00000gn/T//ccQ0MlPv.s:275    .text.IntDefaultHandler:0000000000000000 I2C_IRQHandler
/var/folders/f1/yf6vpc4d7rv1qk99nz_3kyd00000gn/T//ccQ0MlPv.s:275    .text.IntDefaultHandler:0000000000000000 TIMER16_0_IRQHandler
/var/folders/f1/yf6vpc4d7rv1qk99nz_3kyd00000gn/T//ccQ0MlPv.s:275    .text.IntDefaultHandler:0000000000000000 TIMER16_1_IRQHandler
/var/folders/f1/yf6vpc4d7rv1qk99nz_3kyd00000gn/T//ccQ0MlPv.s:275    .text.IntDefaultHandler:0000000000000000 TIMER32_0_IRQHandler
/var/folders/f1/yf6vpc4d7rv1qk99nz_3kyd00000gn/T//ccQ0MlPv.s:275    .text.IntDefaultHandler:0000000000000000 TIMER32_1_IRQHandler
/var/folders/f1/yf6vpc4d7rv1qk99nz_3kyd00000gn/T//ccQ0MlPv.s:275    .text.IntDefaultHandler:0000000000000000 SSP_IRQHandler
/var/folders/f1/yf6vpc4d7rv1qk99nz_3kyd00000gn/T//ccQ0MlPv.s:275    .text.IntDefaultHandler:0000000000000000 UART_IRQHandler
/var/folders/f1/yf6vpc4d7rv1qk99nz_3kyd00000gn/T//ccQ0MlPv.s:275    .text.IntDefaultHandler:0000000000000000 USB_IRQHandler
/var/folders/f1/yf6vpc4d7rv1qk99nz_3kyd00000gn/T//ccQ0MlPv.s:275    .text.IntDefaultHandler:0000000000000000 USB_FIQHandler
/var/folders/f1/yf6vpc4d7rv1qk99nz_3kyd00000gn/T//ccQ0MlPv.s:275    .text.IntDefaultHandler:0000000000000000 ADC_IRQHandler
/var/folders/f1/yf6vpc4d7rv1qk99nz_3kyd00000gn/T//ccQ0MlPv.s:275    .text.IntDefaultHandler:0000000000000000 WDT_IRQHandler
/var/folders/f1/yf6vpc4d7rv1qk99nz_3kyd00000gn/T//ccQ0MlPv.s:275    .text.IntDefaultHandler:0000000000000000 BOD_IRQHandler
/var/folders/f1/yf6vpc4d7rv1qk99nz_3kyd00000gn/T//ccQ0MlPv.s:275    .text.IntDefaultHandler:0000000000000000 FMC_IRQHandler
/var/folders/f1/yf6vpc4d7rv1qk99nz_3kyd00000gn/T//ccQ0MlPv.s:275    .text.IntDefaultHandler:0000000000000000 PIOINT3_IRQHandler
/var/folders/f1/yf6vpc4d7rv1qk99nz_3kyd00000gn/T//ccQ0MlPv.s:275    .text.IntDefaultHandler:0000000000000000 PIOINT2_IRQHandler
/var/folders/f1/yf6vpc4d7rv1qk99nz_3kyd00000gn/T//ccQ0MlPv.s:275    .text.IntDefaultHandler:0000000000000000 PIOINT1_IRQHandler
/var/folders/f1/yf6vpc4d7rv1qk99nz_3kyd00000gn/T//ccQ0MlPv.s:275    .text.IntDefaultHandler:0000000000000000 PIOINT0_IRQHandler
/var/folders/f1/yf6vpc4d7rv1qk99nz_3kyd00000gn/T//ccQ0MlPv.s:72     .text.Reset_Handler:0000000000000000 $t
/var/folders/f1/yf6vpc4d7rv1qk99nz_3kyd00000gn/T//ccQ0MlPv.s:77     .text.Reset_Handler:0000000000000000 Reset_Handler
/var/folders/f1/yf6vpc4d7rv1qk99nz_3kyd00000gn/T//ccQ0MlPv.s:148    .text.Reset_Handler:0000000000000054 $d
/var/folders/f1/yf6vpc4d7rv1qk99nz_3kyd00000gn/T//ccQ0MlPv.s:160    .text.NMI_Handler:0000000000000000 $t
/var/folders/f1/yf6vpc4d7rv1qk99nz_3kyd00000gn/T//ccQ0MlPv.s:182    .text.HardFault_Handler:0000000000000000 $t
/var/folders/f1/yf6vpc4d7rv1qk99nz_3kyd00000gn/T//ccQ0MlPv.s:204    .text.SVCall_Handler:0000000000000000 $t
/var/folders/f1/yf6vpc4d7rv1qk99nz_3kyd00000gn/T//ccQ0MlPv.s:226    .text.PendSV_Handler:0000000000000000 $t
/var/folders/f1/yf6vpc4d7rv1qk99nz_3kyd00000gn/T//ccQ0MlPv.s:248    .text.SysTick_Handler:0000000000000000 $t
/var/folders/f1/yf6vpc4d7rv1qk99nz_3kyd00000gn/T//ccQ0MlPv.s:270    .text.IntDefaultHandler:0000000000000000 $t
/var/folders/f1/yf6vpc4d7rv1qk99nz_3kyd00000gn/T//ccQ0MlPv.s:275    .text.IntDefaultHandler:0000000000000000 IntDefaultHandler
                     .debug_frame:0000000000000010 $d
                           .group:0000000000000000 wm4.0.550acd0550274b7e527f4d3bce81d4f2

UNDEFINED SYMBOLS
_vStackTop
__main
main
_etext
_data
_edata
_bss
_ebss
