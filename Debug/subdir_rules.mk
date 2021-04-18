################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
build-1856735825: ../fatsdraw.syscfg
	@echo 'Building file: "$<"'
	@echo 'Invoking: SysConfig'
	"C:/ti/sysconfig_1.5.0/sysconfig_cli.bat" -s "C:/ti/simplelink_msp432e4_sdk_4_20_00_12/.metadata/product.json" -o "syscfg" --compiler gcc "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

syscfg/ti_drivers_config.c: build-1856735825 ../fatsdraw.syscfg
syscfg/ti_drivers_config.h: build-1856735825
syscfg/ti_utils_build_linker.cmd.exp: build-1856735825
syscfg/syscfg_c.rov.xs: build-1856735825
syscfg/: build-1856735825

syscfg/%.o: ./syscfg/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: GNU Compiler'
	"C:/ti/ccs1020/ccs/tools/compiler/gcc-arm-none-eabi-9-2019-q4-major/bin/arm-none-eabi-gcc-9.2.1.exe" -c -mcpu=cortex-m4 -march=armv7e-m -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -I"C:/Users/David/Documents/CCS_workspace/fatsdraw_MSP_EXP432E401Y_nortos_gcc" -I"C:/Users/David/Documents/CCS_workspace/fatsdraw_MSP_EXP432E401Y_nortos_gcc/Debug" -I"C:/ti/simplelink_msp432e4_sdk_4_20_00_12/source" -I"C:/ti/simplelink_msp432e4_sdk_4_20_00_12/source/third_party/CMSIS/Include" -I"C:/ti/simplelink_msp432e4_sdk_4_20_00_12/kernel/nortos" -I"C:/ti/simplelink_msp432e4_sdk_4_20_00_12/kernel/nortos/posix" -I"C:/ti/ccs1020/ccs/tools/compiler/gcc-arm-none-eabi-9-2019-q4-major/arm-none-eabi/include/newlib-nano" -I"C:/ti/ccs1020/ccs/tools/compiler/gcc-arm-none-eabi-9-2019-q4-major/arm-none-eabi/include" -ffunction-sections -fdata-sections -g -gdwarf-3 -gstrict-dwarf -Wall -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -I"C:/Users/David/Documents/CCS_workspace/fatsdraw_MSP_EXP432E401Y_nortos_gcc/Debug/syscfg" -std=c99 $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

%.o: ../%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: GNU Compiler'
	"C:/ti/ccs1020/ccs/tools/compiler/gcc-arm-none-eabi-9-2019-q4-major/bin/arm-none-eabi-gcc-9.2.1.exe" -c -mcpu=cortex-m4 -march=armv7e-m -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -I"C:/Users/David/Documents/CCS_workspace/fatsdraw_MSP_EXP432E401Y_nortos_gcc" -I"C:/Users/David/Documents/CCS_workspace/fatsdraw_MSP_EXP432E401Y_nortos_gcc/Debug" -I"C:/ti/simplelink_msp432e4_sdk_4_20_00_12/source" -I"C:/ti/simplelink_msp432e4_sdk_4_20_00_12/source/third_party/CMSIS/Include" -I"C:/ti/simplelink_msp432e4_sdk_4_20_00_12/kernel/nortos" -I"C:/ti/simplelink_msp432e4_sdk_4_20_00_12/kernel/nortos/posix" -I"C:/ti/ccs1020/ccs/tools/compiler/gcc-arm-none-eabi-9-2019-q4-major/arm-none-eabi/include/newlib-nano" -I"C:/ti/ccs1020/ccs/tools/compiler/gcc-arm-none-eabi-9-2019-q4-major/arm-none-eabi/include" -ffunction-sections -fdata-sections -g -gdwarf-3 -gstrict-dwarf -Wall -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -I"C:/Users/David/Documents/CCS_workspace/fatsdraw_MSP_EXP432E401Y_nortos_gcc/Debug/syscfg" -std=c99 $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


