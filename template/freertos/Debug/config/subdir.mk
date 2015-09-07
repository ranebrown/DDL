################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../config/freertos_cr_startup_lpc11.c 

OBJS += \
./config/freertos_cr_startup_lpc11.o 

C_DEPS += \
./config/freertos_cr_startup_lpc11.d 


# Each subdirectory must supply rules for building sources it contributes
config/%.o: ../config/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -D__USE_CMSIS -DDEBUG -D__CODE_RED -I"/Users/Rane/LPCXpresso/template/freertos/freertos/inc" -I"/Users/Rane/LPCXpresso/template/lib_small_printf_m0/inc" -I"/Users/Rane/LPCXpresso/template/freertos/cmsis" -I"/Users/Rane/LPCXpresso/template/freertos/freertos/port/lpcxpresso/m0" -I"/Users/Rane/LPCXpresso/template/freertos/config" -I"/Users/Rane/LPCXpresso/template/freertos/driver" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m0 -mthumb -D__REDLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


