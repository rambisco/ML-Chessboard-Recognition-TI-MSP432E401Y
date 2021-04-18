################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Add inputs and outputs from these tool invocations to the build variables 
SYSCFG_SRCS += \
../fatsdraw.syscfg 

LDS_SRCS += \
../MSP_EXP432E401Y_NoRTOS.lds 

C_SRCS += \
./syscfg/ti_drivers_config.c \
../fatsdraw_nortos.c \
../geometric_transform.c \
../image_processing.c \
../main_nortos.c 

GEN_FILES += \
./syscfg/ti_drivers_config.c 

GEN_MISC_DIRS += \
./syscfg/ 

C_DEPS += \
./syscfg/ti_drivers_config.d \
./fatsdraw_nortos.d \
./geometric_transform.d \
./image_processing.d \
./main_nortos.d 

OBJS += \
./syscfg/ti_drivers_config.o \
./fatsdraw_nortos.o \
./geometric_transform.o \
./image_processing.o \
./main_nortos.o 

GEN_MISC_FILES += \
./syscfg/ti_drivers_config.h \
./syscfg/ti_utils_build_linker.cmd.exp \
./syscfg/syscfg_c.rov.xs 

GEN_MISC_DIRS__QUOTED += \
"syscfg\" 

OBJS__QUOTED += \
"syscfg\ti_drivers_config.o" \
"fatsdraw_nortos.o" \
"geometric_transform.o" \
"image_processing.o" \
"main_nortos.o" 

GEN_MISC_FILES__QUOTED += \
"syscfg\ti_drivers_config.h" \
"syscfg\ti_utils_build_linker.cmd.exp" \
"syscfg\syscfg_c.rov.xs" 

C_DEPS__QUOTED += \
"syscfg\ti_drivers_config.d" \
"fatsdraw_nortos.d" \
"geometric_transform.d" \
"image_processing.d" \
"main_nortos.d" 

GEN_FILES__QUOTED += \
"syscfg\ti_drivers_config.c" 

SYSCFG_SRCS__QUOTED += \
"../fatsdraw.syscfg" 

C_SRCS__QUOTED += \
"./syscfg/ti_drivers_config.c" \
"../fatsdraw_nortos.c" \
"../geometric_transform.c" \
"../image_processing.c" \
"../main_nortos.c" 


