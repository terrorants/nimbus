################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/lvgl/src/extra/libs/ffmpeg/lv_ffmpeg.c 

OBJS += \
./Drivers/lvgl/src/extra/libs/ffmpeg/lv_ffmpeg.o 

C_DEPS += \
./Drivers/lvgl/src/extra/libs/ffmpeg/lv_ffmpeg.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/lvgl/src/extra/libs/ffmpeg/%.o Drivers/lvgl/src/extra/libs/ffmpeg/%.su Drivers/lvgl/src/extra/libs/ffmpeg/%.cyclo: ../Drivers/lvgl/src/extra/libs/ffmpeg/%.c Drivers/lvgl/src/extra/libs/ffmpeg/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F405xx -DUSBD_CMPSIT_ACTIVATE_MSC=1 -DUSBD_CMPSIT_ACTIVATE_CDC=1 -DUSBD_COMPOSITE_USE_IAD=1 -c -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../System/Inc -I../Shell/Inc -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CompositeBuilder/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/MSC/Inc -I../Drivers/SSD1351 -I../Drivers/lvgl -I../Drivers -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-lvgl-2f-src-2f-extra-2f-libs-2f-ffmpeg

clean-Drivers-2f-lvgl-2f-src-2f-extra-2f-libs-2f-ffmpeg:
	-$(RM) ./Drivers/lvgl/src/extra/libs/ffmpeg/lv_ffmpeg.cyclo ./Drivers/lvgl/src/extra/libs/ffmpeg/lv_ffmpeg.d ./Drivers/lvgl/src/extra/libs/ffmpeg/lv_ffmpeg.o ./Drivers/lvgl/src/extra/libs/ffmpeg/lv_ffmpeg.su

.PHONY: clean-Drivers-2f-lvgl-2f-src-2f-extra-2f-libs-2f-ffmpeg

