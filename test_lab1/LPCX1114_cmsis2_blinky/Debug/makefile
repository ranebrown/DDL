################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: LPCX1114_cmsis2_blinky.axf

# Tool invocations
LPCX1114_cmsis2_blinky.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU Linker'
	arm-none-eabi-gcc -nostdlib -L"/Users/Rane/LPCXpresso/Test2/CMSISv2p00_LPC11xx/Debug" -L"/Users/Rane/LPCXpresso/Test2/LPC11xx_cmsis2_Lib/Debug" -Xlinker -Map=LPCX1114_cmsis2_blinky.map -Xlinker --gc-sections -mcpu=cortex-m0 -mthumb -T "LPCX1114_cmsis2_blinky_Debug.ld" -o "LPCX1114_cmsis2_blinky.axf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(EXECUTABLES) LPCX1114_cmsis2_blinky.axf
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size LPCX1114_cmsis2_blinky.axf; # arm-none-eabi-objcopy -O ihex LPCX1114_cmsis2_blinky.axf LPCX1114_cmsis2_blinky.hex ;
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
