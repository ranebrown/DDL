################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../driver/can.c \
../driver/crp.c \
../driver/debug_printf.c \
../driver/small_gpio.c 

OBJS += \
./driver/can.o \
./driver/crp.o \
./driver/debug_printf.o \
./driver/small_gpio.o 

C_DEPS += \
./driver/can.d \
./driver/crp.d \
./driver/debug_printf.d \
./driver/small_gpio.d 


# Each subdirectory must supply rules for building sources it contributes
driver/%.o: ../driver/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -D__USE_CMSIS -DDEBUG -D__CODE_RED -I"D:\projects\lpcxpresso\samples\2011-01-26-lpc11xx-202\freertos\freertos\inc" -I"D:\projects\lpcxpresso\samples\2011-01-26-lpc11xx-202\lib_small_printf_m0\inc" -I"D:\projects\lpcxpresso\samples\2011-01-26-lpc11xx-202\freertos\cmsis" -I"D:\projects\lpcxpresso\samples\2011-01-26-lpc11xx-202\freertos\freertos\port\lpcxpresso\m0" -I"D:\projects\lpcxpresso\samples\2011-01-26-lpc11xx-202\freertos\config" -I"D:\projects\lpcxpresso\samples\2011-01-26-lpc11xx-202\freertos\driver" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m0 -mthumb -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


