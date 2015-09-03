################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/clkconfig.c \
../src/gpio.c \
../src/timer16.c \
../src/timer32.c \
../src/uart.c 

OBJS += \
./src/clkconfig.o \
./src/gpio.o \
./src/timer16.o \
./src/timer32.o \
./src/uart.o 

C_DEPS += \
./src/clkconfig.d \
./src/gpio.d \
./src/timer16.d \
./src/timer32.d \
./src/uart.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -D__REDLIB__ -I"/Users/Rane/LPCXpresso/Test2/CMSISv2p00_LPC11xx/inc" -I../inc -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -mcpu=cortex-m0 -mthumb -D__REDLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


