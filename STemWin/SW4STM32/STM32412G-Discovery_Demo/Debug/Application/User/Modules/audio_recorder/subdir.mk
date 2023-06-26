################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/Users/terence_kim/STM32CubeIDE/workspace_1.12.1/STemWin/Modules/audio_recorder/audio_recorder_app.c \
/Users/terence_kim/STM32CubeIDE/workspace_1.12.1/STemWin/Gui/Core/audio_recorder/audio_recorder_win.c 

OBJS += \
./Application/User/Modules/audio_recorder/audio_recorder_app.o \
./Application/User/Modules/audio_recorder/audio_recorder_win.o 

C_DEPS += \
./Application/User/Modules/audio_recorder/audio_recorder_app.d \
./Application/User/Modules/audio_recorder/audio_recorder_win.d 


# Each subdirectory must supply rules for building sources it contributes
Application/User/Modules/audio_recorder/audio_recorder_app.o: /Users/terence_kim/STM32CubeIDE/workspace_1.12.1/STemWin/Modules/audio_recorder/audio_recorder_app.c Application/User/Modules/audio_recorder/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F412Zx -DUSE_STM32412G_DISCOVERY -c -I../../../Gui/STemWin_Addons -I../../../Gui/Target -I../../../Config -I../../../Core/Inc -I../../../Utilities/CPU -I../../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../../Drivers/BSP/STM32412G-Discovery -I../../../Drivers/BSP/Components -I../../../Drivers/BSP/Components/ls016b8uy -I../../../Drivers/BSP/Components/ft6x06 -I../../../Drivers/BSP/Components/Common -I../../../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../../../Middlewares/ST/STM32_USB_Device_Library/Class/MSC/Inc -I../../../Middlewares/ST/STemWin/inc -I../../../Middlewares/Third_Party/FatFs/src -I../../../Middlewares/Third_Party/FatFs/src/drivers -I../../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../../../Modules/audio_player -I../../../Modules/audio_recorder -I../../../Modules/Common -I../../../Modules/usb_storage -I../../../Modules/videoplayer -I../../../Drivers/CMSIS/Include -Os -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/Modules/audio_recorder/audio_recorder_win.o: /Users/terence_kim/STM32CubeIDE/workspace_1.12.1/STemWin/Gui/Core/audio_recorder/audio_recorder_win.c Application/User/Modules/audio_recorder/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F412Zx -DUSE_STM32412G_DISCOVERY -c -I../../../Gui/STemWin_Addons -I../../../Gui/Target -I../../../Config -I../../../Core/Inc -I../../../Utilities/CPU -I../../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../../Drivers/BSP/STM32412G-Discovery -I../../../Drivers/BSP/Components -I../../../Drivers/BSP/Components/ls016b8uy -I../../../Drivers/BSP/Components/ft6x06 -I../../../Drivers/BSP/Components/Common -I../../../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../../../Middlewares/ST/STM32_USB_Device_Library/Class/MSC/Inc -I../../../Middlewares/ST/STemWin/inc -I../../../Middlewares/Third_Party/FatFs/src -I../../../Middlewares/Third_Party/FatFs/src/drivers -I../../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../../../Modules/audio_player -I../../../Modules/audio_recorder -I../../../Modules/Common -I../../../Modules/usb_storage -I../../../Modules/videoplayer -I../../../Drivers/CMSIS/Include -Os -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Application-2f-User-2f-Modules-2f-audio_recorder

clean-Application-2f-User-2f-Modules-2f-audio_recorder:
	-$(RM) ./Application/User/Modules/audio_recorder/audio_recorder_app.cyclo ./Application/User/Modules/audio_recorder/audio_recorder_app.d ./Application/User/Modules/audio_recorder/audio_recorder_app.o ./Application/User/Modules/audio_recorder/audio_recorder_app.su ./Application/User/Modules/audio_recorder/audio_recorder_win.cyclo ./Application/User/Modules/audio_recorder/audio_recorder_win.d ./Application/User/Modules/audio_recorder/audio_recorder_win.o ./Application/User/Modules/audio_recorder/audio_recorder_win.su

.PHONY: clean-Application-2f-User-2f-Modules-2f-audio_recorder

