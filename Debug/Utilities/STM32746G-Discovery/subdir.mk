################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Utilities/STM32746G-Discovery/stm32746g_discovery.c \
../Utilities/STM32746G-Discovery/stm32746g_discovery_audio.c \
../Utilities/STM32746G-Discovery/stm32746g_discovery_camera.c \
../Utilities/STM32746G-Discovery/stm32746g_discovery_eeprom.c \
../Utilities/STM32746G-Discovery/stm32746g_discovery_lcd.c \
../Utilities/STM32746G-Discovery/stm32746g_discovery_qspi.c \
../Utilities/STM32746G-Discovery/stm32746g_discovery_sd.c \
../Utilities/STM32746G-Discovery/stm32746g_discovery_sdram.c \
../Utilities/STM32746G-Discovery/stm32746g_discovery_ts.c 

OBJS += \
./Utilities/STM32746G-Discovery/stm32746g_discovery.o \
./Utilities/STM32746G-Discovery/stm32746g_discovery_audio.o \
./Utilities/STM32746G-Discovery/stm32746g_discovery_camera.o \
./Utilities/STM32746G-Discovery/stm32746g_discovery_eeprom.o \
./Utilities/STM32746G-Discovery/stm32746g_discovery_lcd.o \
./Utilities/STM32746G-Discovery/stm32746g_discovery_qspi.o \
./Utilities/STM32746G-Discovery/stm32746g_discovery_sd.o \
./Utilities/STM32746G-Discovery/stm32746g_discovery_sdram.o \
./Utilities/STM32746G-Discovery/stm32746g_discovery_ts.o 

C_DEPS += \
./Utilities/STM32746G-Discovery/stm32746g_discovery.d \
./Utilities/STM32746G-Discovery/stm32746g_discovery_audio.d \
./Utilities/STM32746G-Discovery/stm32746g_discovery_camera.d \
./Utilities/STM32746G-Discovery/stm32746g_discovery_eeprom.d \
./Utilities/STM32746G-Discovery/stm32746g_discovery_lcd.d \
./Utilities/STM32746G-Discovery/stm32746g_discovery_qspi.d \
./Utilities/STM32746G-Discovery/stm32746g_discovery_sd.d \
./Utilities/STM32746G-Discovery/stm32746g_discovery_sdram.d \
./Utilities/STM32746G-Discovery/stm32746g_discovery_ts.d 


# Each subdirectory must supply rules for building sources it contributes
Utilities/STM32746G-Discovery/%.o: ../Utilities/STM32746G-Discovery/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo %cd%
	arm-none-eabi-gcc -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-sp-d16 -DSTM32F7 -DSTM32F746G_DISCO -DSTM32 -DSTM32F746NGHx -DDEBUG -DUSE_HAL_DRIVER -DSTM32F746xx -I"C:/Users/Ruven/OneDrive/SW-Projekt/OpenStm32/workspace/SmartTreeHome/inc" -I"C:/Users/Ruven/OneDrive/SW-Projekt/OpenStm32/workspace/SmartTreeHome/CMSIS/core" -I"C:/Users/Ruven/OneDrive/SW-Projekt/OpenStm32/workspace/SmartTreeHome/CMSIS/device" -I"C:/Users/Ruven/OneDrive/SW-Projekt/OpenStm32/workspace/SmartTreeHome/HAL_Driver/Inc/Legacy" -I"C:/Users/Ruven/OneDrive/SW-Projekt/OpenStm32/workspace/SmartTreeHome/HAL_Driver/Inc" -I"C:/Users/Ruven/OneDrive/SW-Projekt/OpenStm32/workspace/SmartTreeHome/Utilities/Components/ampire480272" -I"C:/Users/Ruven/OneDrive/SW-Projekt/OpenStm32/workspace/SmartTreeHome/Utilities/Components/ampire640480" -I"C:/Users/Ruven/OneDrive/SW-Projekt/OpenStm32/workspace/SmartTreeHome/Utilities/Components/Common" -I"C:/Users/Ruven/OneDrive/SW-Projekt/OpenStm32/workspace/SmartTreeHome/Utilities/Components/exc7200" -I"C:/Users/Ruven/OneDrive/SW-Projekt/OpenStm32/workspace/SmartTreeHome/Utilities/Components/ft5336" -I"C:/Users/Ruven/OneDrive/SW-Projekt/OpenStm32/workspace/SmartTreeHome/Utilities/Components/mfxstm32l152" -I"C:/Users/Ruven/OneDrive/SW-Projekt/OpenStm32/workspace/SmartTreeHome/Utilities/Components/n25q128a" -I"C:/Users/Ruven/OneDrive/SW-Projekt/OpenStm32/workspace/SmartTreeHome/Utilities/Components/n25q512a" -I"C:/Users/Ruven/OneDrive/SW-Projekt/OpenStm32/workspace/SmartTreeHome/Utilities/Components/ov9655" -I"C:/Users/Ruven/OneDrive/SW-Projekt/OpenStm32/workspace/SmartTreeHome/Utilities/Components/rk043fn48h" -I"C:/Users/Ruven/OneDrive/SW-Projekt/OpenStm32/workspace/SmartTreeHome/Utilities/Components/s5k5cag" -I"C:/Users/Ruven/OneDrive/SW-Projekt/OpenStm32/workspace/SmartTreeHome/Utilities/Components/st7735" -I"C:/Users/Ruven/OneDrive/SW-Projekt/OpenStm32/workspace/SmartTreeHome/Utilities/Components/stmpe811" -I"C:/Users/Ruven/OneDrive/SW-Projekt/OpenStm32/workspace/SmartTreeHome/Utilities/Components/ts3510" -I"C:/Users/Ruven/OneDrive/SW-Projekt/OpenStm32/workspace/SmartTreeHome/Utilities/Components/wm8994" -I"C:/Users/Ruven/OneDrive/SW-Projekt/OpenStm32/workspace/SmartTreeHome/Utilities/Fonts" -I"C:/Users/Ruven/OneDrive/SW-Projekt/OpenStm32/workspace/SmartTreeHome/Utilities/Log" -I"C:/Users/Ruven/OneDrive/SW-Projekt/OpenStm32/workspace/SmartTreeHome/Utilities" -I"C:/Users/Ruven/OneDrive/SW-Projekt/OpenStm32/workspace/SmartTreeHome/Utilities/STM32746G-Discovery" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


