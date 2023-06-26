################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/Users/terence_kim/STM32CubeIDE/workspace_1.12.1/STemWin/Gui/Core/usb_storage/usb_storage_win.c \
/Users/terence_kim/STM32CubeIDE/workspace_1.12.1/STemWin/Modules/usb_storage/usbd_app.c \
/Users/terence_kim/STM32CubeIDE/workspace_1.12.1/STemWin/Modules/usb_storage/usbd_desc.c \
/Users/terence_kim/STM32CubeIDE/workspace_1.12.1/STemWin/Modules/usb_storage/usbd_storage.c 

OBJS += \
./Application/User/Modules/USB_Storage/usb_storage_win.o \
./Application/User/Modules/USB_Storage/usbd_app.o \
./Application/User/Modules/USB_Storage/usbd_desc.o \
./Application/User/Modules/USB_Storage/usbd_storage.o 

C_DEPS += \
./Application/User/Modules/USB_Storage/usb_storage_win.d \
./Application/User/Modules/USB_Storage/usbd_app.d \
./Application/User/Modules/USB_Storage/usbd_desc.d \
./Application/User/Modules/USB_Storage/usbd_storage.d 


# Each subdirectory must supply rules for building sources it contributes
Application/User/Modules/USB_Storage/usb_storage_win.o: /Users/terence_kim/STM32CubeIDE/workspace_1.12.1/STemWin/Gui/Core/usb_storage/usb_storage_win.c Application/User/Modules/USB_Storage/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F412Zx -DUSE_STM32412G_DISCOVERY -c -I../../../Gui/STemWin_Addons -I../../../Gui/Target -I../../../Config -I../../../Core/Inc -I../../../Utilities/CPU -I../../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../../Drivers/BSP/STM32412G-Discovery -I../../../Drivers/BSP/Components -I../../../Drivers/BSP/Components/ls016b8uy -I../../../Drivers/BSP/Components/ft6x06 -I../../../Drivers/BSP/Components/Common -I../../../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../../../Middlewares/ST/STM32_USB_Device_Library/Class/MSC/Inc -I../../../Middlewares/ST/STemWin/inc -I../../../Middlewares/Third_Party/FatFs/src -I../../../Middlewares/Third_Party/FatFs/src/drivers -I../../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../../../Modules/audio_player -I../../../Modules/audio_recorder -I../../../Modules/Common -I../../../Modules/usb_storage -I../../../Modules/videoplayer -I../../../Drivers/CMSIS/Include -Os -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/Modules/USB_Storage/usbd_app.o: /Users/terence_kim/STM32CubeIDE/workspace_1.12.1/STemWin/Modules/usb_storage/usbd_app.c Application/User/Modules/USB_Storage/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F412Zx -DUSE_STM32412G_DISCOVERY -c -I../../../Gui/STemWin_Addons -I../../../Gui/Target -I../../../Config -I../../../Core/Inc -I../../../Utilities/CPU -I../../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../../Drivers/BSP/STM32412G-Discovery -I../../../Drivers/BSP/Components -I../../../Drivers/BSP/Components/ls016b8uy -I../../../Drivers/BSP/Components/ft6x06 -I../../../Drivers/BSP/Components/Common -I../../../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../../../Middlewares/ST/STM32_USB_Device_Library/Class/MSC/Inc -I../../../Middlewares/ST/STemWin/inc -I../../../Middlewares/Third_Party/FatFs/src -I../../../Middlewares/Third_Party/FatFs/src/drivers -I../../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../../../Modules/audio_player -I../../../Modules/audio_recorder -I../../../Modules/Common -I../../../Modules/usb_storage -I../../../Modules/videoplayer -I../../../Drivers/CMSIS/Include -Os -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/Modules/USB_Storage/usbd_desc.o: /Users/terence_kim/STM32CubeIDE/workspace_1.12.1/STemWin/Modules/usb_storage/usbd_desc.c Application/User/Modules/USB_Storage/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F412Zx -DUSE_STM32412G_DISCOVERY -c -I../../../Gui/STemWin_Addons -I../../../Gui/Target -I../../../Config -I../../../Core/Inc -I../../../Utilities/CPU -I../../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../../Drivers/BSP/STM32412G-Discovery -I../../../Drivers/BSP/Components -I../../../Drivers/BSP/Components/ls016b8uy -I../../../Drivers/BSP/Components/ft6x06 -I../../../Drivers/BSP/Components/Common -I../../../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../../../Middlewares/ST/STM32_USB_Device_Library/Class/MSC/Inc -I../../../Middlewares/ST/STemWin/inc -I../../../Middlewares/Third_Party/FatFs/src -I../../../Middlewares/Third_Party/FatFs/src/drivers -I../../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../../../Modules/audio_player -I../../../Modules/audio_recorder -I../../../Modules/Common -I../../../Modules/usb_storage -I../../../Modules/videoplayer -I../../../Drivers/CMSIS/Include -Os -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/Modules/USB_Storage/usbd_storage.o: /Users/terence_kim/STM32CubeIDE/workspace_1.12.1/STemWin/Modules/usb_storage/usbd_storage.c Application/User/Modules/USB_Storage/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F412Zx -DUSE_STM32412G_DISCOVERY -c -I../../../Gui/STemWin_Addons -I../../../Gui/Target -I../../../Config -I../../../Core/Inc -I../../../Utilities/CPU -I../../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../../Drivers/BSP/STM32412G-Discovery -I../../../Drivers/BSP/Components -I../../../Drivers/BSP/Components/ls016b8uy -I../../../Drivers/BSP/Components/ft6x06 -I../../../Drivers/BSP/Components/Common -I../../../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../../../Middlewares/ST/STM32_USB_Device_Library/Class/MSC/Inc -I../../../Middlewares/ST/STemWin/inc -I../../../Middlewares/Third_Party/FatFs/src -I../../../Middlewares/Third_Party/FatFs/src/drivers -I../../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../../../Modules/audio_player -I../../../Modules/audio_recorder -I../../../Modules/Common -I../../../Modules/usb_storage -I../../../Modules/videoplayer -I../../../Drivers/CMSIS/Include -Os -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Application-2f-User-2f-Modules-2f-USB_Storage

clean-Application-2f-User-2f-Modules-2f-USB_Storage:
	-$(RM) ./Application/User/Modules/USB_Storage/usb_storage_win.cyclo ./Application/User/Modules/USB_Storage/usb_storage_win.d ./Application/User/Modules/USB_Storage/usb_storage_win.o ./Application/User/Modules/USB_Storage/usb_storage_win.su ./Application/User/Modules/USB_Storage/usbd_app.cyclo ./Application/User/Modules/USB_Storage/usbd_app.d ./Application/User/Modules/USB_Storage/usbd_app.o ./Application/User/Modules/USB_Storage/usbd_app.su ./Application/User/Modules/USB_Storage/usbd_desc.cyclo ./Application/User/Modules/USB_Storage/usbd_desc.d ./Application/User/Modules/USB_Storage/usbd_desc.o ./Application/User/Modules/USB_Storage/usbd_desc.su ./Application/User/Modules/USB_Storage/usbd_storage.cyclo ./Application/User/Modules/USB_Storage/usbd_storage.d ./Application/User/Modules/USB_Storage/usbd_storage.o ./Application/User/Modules/USB_Storage/usbd_storage.su

.PHONY: clean-Application-2f-User-2f-Modules-2f-USB_Storage
