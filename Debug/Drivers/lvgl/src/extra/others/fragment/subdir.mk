################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/lvgl/src/extra/others/fragment/lv_fragment.c \
../Drivers/lvgl/src/extra/others/fragment/lv_fragment_manager.c 

OBJS += \
./Drivers/lvgl/src/extra/others/fragment/lv_fragment.o \
./Drivers/lvgl/src/extra/others/fragment/lv_fragment_manager.o 

C_DEPS += \
./Drivers/lvgl/src/extra/others/fragment/lv_fragment.d \
./Drivers/lvgl/src/extra/others/fragment/lv_fragment_manager.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/lvgl/src/extra/others/fragment/%.o Drivers/lvgl/src/extra/others/fragment/%.su Drivers/lvgl/src/extra/others/fragment/%.cyclo: ../Drivers/lvgl/src/extra/others/fragment/%.c Drivers/lvgl/src/extra/others/fragment/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F405xx -DUSBD_CMPSIT_ACTIVATE_MSC=1 -DUSBD_CMPSIT_ACTIVATE_CDC=1 -DUSBD_COMPOSITE_USE_IAD=1 -c -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../System/Inc -I../Shell/Inc -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CompositeBuilder/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/MSC/Inc -I../Drivers/SSD1351 -I../Drivers/lvgl -I../Drivers -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-lvgl-2f-src-2f-extra-2f-others-2f-fragment

clean-Drivers-2f-lvgl-2f-src-2f-extra-2f-others-2f-fragment:
	-$(RM) ./Drivers/lvgl/src/extra/others/fragment/lv_fragment.cyclo ./Drivers/lvgl/src/extra/others/fragment/lv_fragment.d ./Drivers/lvgl/src/extra/others/fragment/lv_fragment.o ./Drivers/lvgl/src/extra/others/fragment/lv_fragment.su ./Drivers/lvgl/src/extra/others/fragment/lv_fragment_manager.cyclo ./Drivers/lvgl/src/extra/others/fragment/lv_fragment_manager.d ./Drivers/lvgl/src/extra/others/fragment/lv_fragment_manager.o ./Drivers/lvgl/src/extra/others/fragment/lv_fragment_manager.su

.PHONY: clean-Drivers-2f-lvgl-2f-src-2f-extra-2f-others-2f-fragment

