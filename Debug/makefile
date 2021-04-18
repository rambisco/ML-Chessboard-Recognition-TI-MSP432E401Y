################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := C:/ti/ccs1020/ccs/tools/compiler/gcc-arm-none-eabi-9-2019-q4-major

GEN_OPTS__FLAG := 
GEN_CMDS__FLAG := 

ORDERED_OBJS += \
"./syscfg/ti_drivers_config.o" \
"./fatsdraw_nortos.o" \
"./geometric_transform.o" \
"./image_processing.o" \
"./main_nortos.o" \
-Wl,-T"../MSP_EXP432E401Y_NoRTOS.lds" \
$(GEN_CMDS__FLAG) \
"C:/Users/David/Documents/Arm/Packs/ARM/CMSIS/5.7.0/CMSIS/DSP/Lib/GCC/libarm_cortexM4lf_math.a" \
-l:"ti/display/lib/display.am4fg" \
-l:"ti/grlib/lib/gcc/m4f/grlib.a" \
-l:"third_party/spiffs/lib/gcc/m4f/spiffs.a" \
-l:"ti/drivers/lib/drivers_msp432e4.am4fg" \
-l:"third_party/fatfs/lib/gcc/m4f/fatfs.a" \
-l:"lib/nortos_msp432e4.am4fg" \
-l:"ti/devices/msp432e4/driverlib/lib/gcc/m4f/msp432e4_driverlib.a" \
-lgcc \
-lc \
-lm \
-lnosys \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(SV7A_DEPS)),)
-include $(SV7A_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
fatsdraw_MSP_EXP432E401Y_nortos_gcc.out \

EXE_OUTPUTS__QUOTED += \
"fatsdraw_MSP_EXP432E401Y_nortos_gcc.out" \

BIN_OUTPUTS += \
fatsdraw_MSP_EXP432E401Y_nortos_gcc.hex \

BIN_OUTPUTS__QUOTED += \
"fatsdraw_MSP_EXP432E401Y_nortos_gcc.hex" \


# All Target
all: $(OBJS) $(LDS_SRCS) $(GEN_CMDS)
	@$(MAKE) --no-print-directory -Onone "fatsdraw_MSP_EXP432E401Y_nortos_gcc.out"

# Tool invocations
fatsdraw_MSP_EXP432E401Y_nortos_gcc.out: $(OBJS) $(LDS_SRCS) $(GEN_CMDS)
	@echo 'Building target: "$@"'
	@echo 'Invoking: GNU Linker'
	"C:/ti/ccs1020/ccs/tools/compiler/gcc-arm-none-eabi-9-2019-q4-major/bin/arm-none-eabi-gcc-9.2.1.exe" -mfpu=fpv4-sp-d16 -ffunction-sections -fdata-sections -g -gdwarf-3 -gstrict-dwarf -Wall -mcpu=cortex-m4 -Wl,-Map,"fatsdraw_MSP_EXP432E401Y_nortos_gcc.map" --entry resetISR -nostartfiles -static -Wl,--gc-sections -L"C:/ti/simplelink_msp432e4_sdk_4_20_00_12/source" -L"C:/ti/simplelink_msp432e4_sdk_4_20_00_12/kernel/nortos" -L"C:/ti/ccs1020/ccs/tools/compiler/gcc-arm-none-eabi-9-2019-q4-major/arm-none-eabi/lib/thumb/v7e-m/hard" -march=armv7e-m -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 --specs=nano.specs -o"fatsdraw_MSP_EXP432E401Y_nortos_gcc.out" $(ORDERED_OBJS)
	@echo 'Finished building target: "$@"'
	@echo ' '

fatsdraw_MSP_EXP432E401Y_nortos_gcc.hex: $(EXE_OUTPUTS)
	@echo 'Building files: $(strip $(EXE_OUTPUTS__QUOTED))'
	@echo 'Invoking: GNU Objcopy Utility'
	"C:/ti/ccs1020/ccs/tools/compiler/gcc-arm-none-eabi-9-2019-q4-major/bin/arm-none-eabi-objcopy.exe"  $(EXE_OUTPUTS__QUOTED) "fatsdraw_MSP_EXP432E401Y_nortos_gcc.hex"
	@echo 'Finished building: $(strip $(EXE_OUTPUTS__QUOTED))'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(GEN_MISC_FILES__QUOTED)$(BIN_OUTPUTS__QUOTED)$(GEN_FILES__QUOTED)$(EXE_OUTPUTS__QUOTED)
	-$(RM) "syscfg\ti_drivers_config.o" "fatsdraw_nortos.o" "geometric_transform.o" "image_processing.o" "main_nortos.o" 
	-$(RM) "syscfg\ti_drivers_config.d" "fatsdraw_nortos.d" "geometric_transform.d" "image_processing.d" "main_nortos.d" 
	-$(RMDIR) $(GEN_MISC_DIRS__QUOTED)
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

