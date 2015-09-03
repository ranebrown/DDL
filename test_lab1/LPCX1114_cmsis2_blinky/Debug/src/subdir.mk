################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/blinky.c \
../src/cr_startup_lpc11.c \
../src/timer16_int.c 

OBJS += \
./src/blinky.o \
./src/cr_startup_lpc11.o \
./src/timer16_int.o 

C_DEPS += \
./src/blinky.d \
./src/cr_startup_lpc11.d \
./src/timer16_int.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__USE_CMSIS=CMSISv2p00_LPC11xx -DDEBUG -D__CODE_RED -D__REDLIB__ -I"/Users/Rane/LPCXpresso/Test2/CMSISv2p00_LPC11xx/inc" -I"/Users/Rane/LPCXpresso/Test2/LPC11xx_cmsis2_Lib/inc" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -mcpu=cortex-m0 -mthumb -D__REDLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/cr_startup_lpc11.o: ../src/cr_startup_lpc11.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__USE_CMSIS=CMSISv2p00_LPC11xx -DDEBUG -D__CODE_RED -D__REDLIB__ -I"/Users/Rane/LPCXpresso/Test2/CMSISv2p00_LPC11xx/inc" -I"/Users/Rane/LPCXpresso/Test2/LPC11xx_cmsis2_Lib/inc" -O0 -Os -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -mcpu=cortex-m0 -mthumb -D__REDLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"src/cr_startup_lpc11.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


