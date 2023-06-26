################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/Users/terence_kim/STM32CubeIDE/workspace_1.12.1/STemWin/Middlewares/ST/STemWin/OS/GUI_X_OS.c 

OBJS += \
./Middlewares/STemWin/OS/GUI_X_OS.o 

C_DEPS += \
./Middlewares/STemWin/OS/GUI_X_OS.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/STemWin/OS/GUI_X_OS.o: /Users/terence_kim/STM32CubeIDE/workspace_1.12.1/STemWin/Middlewares/ST/STemWin/OS/GUI_X_OS.c Middlewares/STemWin/OS/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F412Zx -DUSE_STM32412G_DISCOVERY -c -I../../../Gui/STemWin_Addons -I../../../Gui/Target -I../../../Config -I../../../Core/Inc -I../../../Utilities/CPU -I../../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../../Drivers/BSP/STM32412G-Discovery -I../../../Drivers/BSP/Components -I../../../Drivers/BSP/Components/ls016b8uy -I../../../Drivers/BSP/Components/ft6x06 -I../../../Drivers/BSP/Components/Common -I../../../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../../../Middlewares/ST/STM32_USB_Device_Library/Class/MSC/Inc -I../../../Middlewares/ST/STemWin/inc -I../../../Middlewares/Third_Party/FatFs/src -I../../../Middlewares/Third_Party/FatFs/src/drivers -I../../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../../../Modules/audio_player -I../../../Modules/audio_recorder -I../../../Modules/Common -I../../../Modules/usb_storage -I../../../Modules/videoplayer -I../../../Drivers/CMSIS/Include -Os -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Middlewares-2f-STemWin-2f-OS

clean-Middlewares-2f-STemWin-2f-OS:
	-$(RM) ./Middlewares/STemWin/OS/GUI_X_OS.cyclo ./Middlewares/STemWin/OS/GUI_X_OS.d ./Middlewares/STemWin/OS/GUI_X_OS.o ./Middlewares/STemWin/OS/GUI_X_OS.su

.PHONY: clean-Middlewares-2f-STemWin-2f-OS

