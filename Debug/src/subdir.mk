################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/graphics.c \
../src/main.c \
../src/setup.c \
../src/stm32f7xx_it.c \
../src/syscalls.c \
../src/system_stm32f7xx.c 

OBJS += \
./src/graphics.o \
./src/main.o \
./src/setup.o \
./src/stm32f7xx_it.o \
./src/syscalls.o \
./src/system_stm32f7xx.o 

C_DEPS += \
./src/graphics.d \
./src/main.d \
./src/setup.d \
./src/stm32f7xx_it.d \
./src/syscalls.d \
./src/system_stm32f7xx.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo %cd%
	arm-none-eabi-gcc -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-sp-d16 -DSTM32F7 -DSTM32F746G_DISCO -DSTM32 -DSTM32F746NGHx -DDEBUG -DUSE_HAL_DRIVER -DSTM32F746xx -I"C:/Users/Ruven/OneDrive/SW-Projekt/OpenStm32/workspace/SmartTreeHome/inc" -I"C:/Users/Ruven/OneDrive/SW-Projekt/OpenStm32/workspace/SmartTreeHome/CMSIS/core" -I"C:/Users/Ruven/OneDrive/SW-Projekt/OpenStm32/workspace/SmartTreeHome/CMSIS/device" -I"C:/Users/Ruven/OneDrive/SW-Projekt/OpenStm32/workspace/SmartTreeHome/HAL_Driver/Inc/Legacy" -I"C:/Users/Ruven/OneDrive/SW-Projekt/OpenStm32/workspace/SmartTreeHome/HAL_Driver/Inc" -I"C:/Users/Ruven/OneDrive/SW-Projekt/OpenStm32/workspace/SmartTreeHome/Utilities/Components/ampire480272" -I"C:/Users/Ruven/OneDrive/SW-Projekt/OpenStm32/workspace/SmartTreeHome/Utilities/Components/ampire640480" -I"C:/Users/Ruven/OneDrive/SW-Projekt/OpenStm32/workspace/SmartTreeHome/Utilities/Components/Common" -I"C:/Users/Ruven/OneDrive/SW-Projekt/OpenStm32/workspace/SmartTreeHome/Utilities/Components/exc7200" -I"C:/Users/Ruven/OneDrive/SW-Projekt/OpenStm32/workspace/SmartTreeHome/Utilities/Components/ft5336" -I"C:/Users/Ruven/OneDrive/SW-Projekt/OpenStm32/workspace/SmartTreeHome/Utilities/Components/mfxstm32l152" -I"C:/Users/Ruven/OneDrive/SW-Projekt/OpenStm32/workspace/SmartTreeHome/Utilities/Components/n25q128a" -I"C:/Users/Ruven/OneDrive/SW-Projekt/OpenStm32/workspace/SmartTreeHome/Utilities/Components/n25q512a" -I"C:/Users/Ruven/OneDrive/SW-Projekt/OpenStm32/workspace/SmartTreeHome/Utilities/Components/ov9655" -I"C:/Users/Ruven/OneDrive/SW-Projekt/OpenStm32/workspace/SmartTreeHome/Utilities/Components/rk043fn48h" -I"C:/Users/Ruven/OneDrive/SW-Projekt/OpenStm32/workspace/SmartTreeHome/Utilities/Components/s5k5cag" -I"C:/Users/Ruven/OneDrive/SW-Projekt/OpenStm32/workspace/SmartTreeHome/Utilities/Components/st7735" -I"C:/Users/Ruven/OneDrive/SW-Projekt/OpenStm32/workspace/SmartTreeHome/Utilities/Components/stmpe811" -I"C:/Users/Ruven/OneDrive/SW-Projekt/OpenStm32/workspace/SmartTreeHome/Utilities/Components/ts3510" -I"C:/Users/Ruven/OneDrive/SW-Projekt/OpenStm32/workspace/SmartTreeHome/Utilities/Components/wm8994" -I"C:/Users/Ruven/OneDrive/SW-Projekt/OpenStm32/workspace/SmartTreeHome/Utilities/Fonts" -I"C:/Users/Ruven/OneDrive/SW-Projekt/OpenStm32/workspace/SmartTreeHome/Utilities/Log" -I"C:/Users/Ruven/OneDrive/SW-Projekt/OpenStm32/workspace/SmartTreeHome/Utilities" -I"C:/Users/Ruven/OneDrive/SW-Projekt/OpenStm32/workspace/SmartTreeHome/Utilities/STM32746G-Discovery" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


