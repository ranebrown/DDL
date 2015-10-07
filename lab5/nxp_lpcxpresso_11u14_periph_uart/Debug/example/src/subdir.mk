################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../example/src/cr_startup_lpc11xx.c \
../example/src/sysinit.c \
../example/src/uart.c 

OBJS += \
./example/src/cr_startup_lpc11xx.o \
./example/src/sysinit.o \
./example/src/uart.o 

C_DEPS += \
./example/src/cr_startup_lpc11xx.d \
./example/src/sysinit.d \
./example/src/uart.d 


# Each subdirectory must supply rules for building sources it contributes
example/src/cr_startup_lpc11xx.o: ../example/src/cr_startup_lpc11xx.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DDEBUG -D__CODE_RED -D__USE_LPCOPEN -DCORE_M0 -I"/Users/Rane/LPCXpresso/lab5/nxp_lpcxpresso_11u14_periph_uart/example/inc" -I"/Users/Rane/LPCXpresso/lab5/lpc_chip_11uxx_lib/inc" -I"/Users/Rane/LPCXpresso/lab5/nxp_lpcxpresso_11u14_board_lib/inc" -Os -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m0 -mthumb -D__REDLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"example/src/cr_startup_lpc11xx.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

example/src/%.o: ../example/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DDEBUG -D__CODE_RED -D__USE_LPCOPEN -DCORE_M0 -I"/Users/Rane/LPCXpresso/lab5/nxp_lpcxpresso_11u14_periph_uart/example/inc" -I"/Users/Rane/LPCXpresso/lab5/lpc_chip_11uxx_lib/inc" -I"/Users/Rane/LPCXpresso/lab5/nxp_lpcxpresso_11u14_board_lib/inc" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m0 -mthumb -D__REDLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


