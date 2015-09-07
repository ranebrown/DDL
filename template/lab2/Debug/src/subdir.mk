################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/cr_startup_lpc11.c \
../src/fibonacci.c 

OBJS += \
./src/cr_startup_lpc11.o \
./src/fibonacci.o 

C_DEPS += \
./src/cr_startup_lpc11.d \
./src/fibonacci.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -DTARGET_SHORTCHIP=lpc11 -DTARGET_CHIP=LPC11U14/201 -D__USE_CMSIS=1 -D__REDLIB__ -I"/Users/Rane/LPCXpresso/template/lab2/cmsis" -I"/Users/Rane/LPCXpresso/template/lab2/config" -I"/Users/Rane/LPCXpresso/template/lab2/driver" -I"/Users/Rane/LPCXpresso/template/lib_small_printf_m0/inc" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m0 -mthumb -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


