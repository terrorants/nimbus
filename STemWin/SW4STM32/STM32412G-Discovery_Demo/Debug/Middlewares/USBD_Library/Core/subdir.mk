################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/Users/terence_kim/STM32CubeIDE/workspace_1.12.1/STemWin/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_core.c \
/Users/terence_kim/STM32CubeIDE/workspace_1.12.1/STemWin/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_ctlreq.c \
/Users/terence_kim/STM32CubeIDE/workspace_1.12.1/STemWin/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_ioreq.c 

OBJS += \
./Middlewares/USBD_Library/Core/usbd_core.o \
./Middlewares/USBD_Library/Core/usbd_ctlreq.o \
./Middlewares/USBD_Library/Core/usbd_ioreq.o 

C_DEPS += \
./Middlewares/USBD_Library/Core/usbd_core.d \
./Middlewares/USBD_Library/Core/usbd_ctlreq.d \
./Middlewares/USBD_Library/Core/usbd_ioreq.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/USBD_Library/Core/usbd_core.o: /Users/terence_kim/STM32CubeIDE/workspace_1.12.1/STemWin/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_core.c Middlewares/USBD_Library/Core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F412Zx -DUSE_STM32412G_DISCOVERY -c -I../../../Gui/STemWin_Addons -I../../../Gui/Target -I../../../Config -I../../../Core/Inc -I../../../Utilities/CPU -I../../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../../Drivers/BSP/STM32412G-Discovery -I../../../Drivers/BSP/Components -I../../../Drivers/BSP/Components/ls016b8uy -I../../../Drivers/BSP/Components/ft6x06 -I../../../Drivers/BSP/Components/Common -I../../../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../../../Middlewares/ST/STM32_USB_Device_Library/Class/MSC/Inc -I../../../Middlewares/ST/STemWin/inc -I../../../Middlewares/Third_Party/FatFs/src -I../../../Middlewares/Third_Party/FatFs/src/drivers -I../../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../../../Modules/audio_player -I../../../Modules/audio_recorder -I../../../Modules/Common -I../../../Modules/usb_storage -I../../../Modules/videoplayer -I../../../Drivers/CMSIS/Include -Os -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Middlewares/USBD_Library/Core/usbd_ctlreq.o: /Users/terence_kim/STM32CubeIDE/workspace_1.12.1/STemWin/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_ctlreq.c Middlewares/USBD_Library/Core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F412Zx -DUSE_STM32412G_DISCOVERY -c -I../../../Gui/STemWin_Addons -I../../../Gui/Target -I../../../Config -I../../../Core/Inc -I../../../Utilities/CPU -I../../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../../Drivers/BSP/STM32412G-Discovery -I../../../Drivers/BSP/Components -I../../../Drivers/BSP/Components/ls016b8uy -I../../../Drivers/BSP/Components/ft6x06 -I../../../Drivers/BSP/Components/Common -I../../../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../../../Middlewares/ST/STM32_USB_Device_Library/Class/MSC/Inc -I../../../Middlewares/ST/STemWin/inc -I../../../Middlewares/Third_Party/FatFs/src -I../../../Middlewares/Third_Party/FatFs/src/drivers -I../../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../../../Modules/audio_player -I../../../Modules/audio_recorder -I../../../Modules/Common -I../../../Modules/usb_storage -I../../../Modules/videoplayer -I../../../Drivers/CMSIS/Include -Os -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Middlewares/USBD_Library/Core/usbd_ioreq.o: /Users/terence_kim/STM32CubeIDE/workspace_1.12.1/STemWin/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_ioreq.c Middlewares/USBD_Library/Core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F412Zx -DUSE_STM32412G_DISCOVERY -c -I../../../Gui/STemWin_Addons -I../../../Gui/Target -I../../../Config -I../../../Core/Inc -I../../../Utilities/CPU -I../../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../../Drivers/BSP/STM32412G-Discovery -I../../../Drivers/BSP/Components -I../../../Drivers/BSP/Components/ls016b8uy -I../../../Drivers/BSP/Components/ft6x06 -I../../../Drivers/BSP/Components/Common -I../../../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../../../Middlewares/ST/STM32_USB_Device_Library/Class/MSC/Inc -I../../../Middlewares/ST/STemWin/inc -I../../../Middlewares/Third_Party/FatFs/src -I../../../Middlewares/Third_Party/FatFs/src/drivers -I../../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../../../Modules/audio_player -I../../../Modules/audio_recorder -I../../../Modules/Common -I../../../Modules/usb_storage -I../../../Modules/videoplayer -I../../../Drivers/CMSIS/Include -Os -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Middlewares-2f-USBD_Library-2f-Core

clean-Middlewares-2f-USBD_Library-2f-Core:
	-$(RM) ./Middlewares/USBD_Library/Core/usbd_core.cyclo ./Middlewares/USBD_Library/Core/usbd_core.d ./Middlewares/USBD_Library/Core/usbd_core.o ./Middlewares/USBD_Library/Core/usbd_core.su ./Middlewares/USBD_Library/Core/usbd_ctlreq.cyclo ./Middlewares/USBD_Library/Core/usbd_ctlreq.d ./Middlewares/USBD_Library/Core/usbd_ctlreq.o ./Middlewares/USBD_Library/Core/usbd_ctlreq.su ./Middlewares/USBD_Library/Core/usbd_ioreq.cyclo ./Middlewares/USBD_Library/Core/usbd_ioreq.d ./Middlewares/USBD_Library/Core/usbd_ioreq.o ./Middlewares/USBD_Library/Core/usbd_ioreq.su

.PHONY: clean-Middlewares-2f-USBD_Library-2f-Core

