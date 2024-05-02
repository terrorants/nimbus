################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/lvgl/src/draw/lv_draw.c \
../Drivers/lvgl/src/draw/lv_draw_arc.c \
../Drivers/lvgl/src/draw/lv_draw_img.c \
../Drivers/lvgl/src/draw/lv_draw_label.c \
../Drivers/lvgl/src/draw/lv_draw_layer.c \
../Drivers/lvgl/src/draw/lv_draw_line.c \
../Drivers/lvgl/src/draw/lv_draw_mask.c \
../Drivers/lvgl/src/draw/lv_draw_rect.c \
../Drivers/lvgl/src/draw/lv_draw_transform.c \
../Drivers/lvgl/src/draw/lv_draw_triangle.c \
../Drivers/lvgl/src/draw/lv_img_buf.c \
../Drivers/lvgl/src/draw/lv_img_cache.c \
../Drivers/lvgl/src/draw/lv_img_decoder.c 

OBJS += \
./Drivers/lvgl/src/draw/lv_draw.o \
./Drivers/lvgl/src/draw/lv_draw_arc.o \
./Drivers/lvgl/src/draw/lv_draw_img.o \
./Drivers/lvgl/src/draw/lv_draw_label.o \
./Drivers/lvgl/src/draw/lv_draw_layer.o \
./Drivers/lvgl/src/draw/lv_draw_line.o \
./Drivers/lvgl/src/draw/lv_draw_mask.o \
./Drivers/lvgl/src/draw/lv_draw_rect.o \
./Drivers/lvgl/src/draw/lv_draw_transform.o \
./Drivers/lvgl/src/draw/lv_draw_triangle.o \
./Drivers/lvgl/src/draw/lv_img_buf.o \
./Drivers/lvgl/src/draw/lv_img_cache.o \
./Drivers/lvgl/src/draw/lv_img_decoder.o 

C_DEPS += \
./Drivers/lvgl/src/draw/lv_draw.d \
./Drivers/lvgl/src/draw/lv_draw_arc.d \
./Drivers/lvgl/src/draw/lv_draw_img.d \
./Drivers/lvgl/src/draw/lv_draw_label.d \
./Drivers/lvgl/src/draw/lv_draw_layer.d \
./Drivers/lvgl/src/draw/lv_draw_line.d \
./Drivers/lvgl/src/draw/lv_draw_mask.d \
./Drivers/lvgl/src/draw/lv_draw_rect.d \
./Drivers/lvgl/src/draw/lv_draw_transform.d \
./Drivers/lvgl/src/draw/lv_draw_triangle.d \
./Drivers/lvgl/src/draw/lv_img_buf.d \
./Drivers/lvgl/src/draw/lv_img_cache.d \
./Drivers/lvgl/src/draw/lv_img_decoder.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/lvgl/src/draw/%.o Drivers/lvgl/src/draw/%.su Drivers/lvgl/src/draw/%.cyclo: ../Drivers/lvgl/src/draw/%.c Drivers/lvgl/src/draw/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F405xx -DUSBD_CMPSIT_ACTIVATE_MSC=1 -DUSBD_CMPSIT_ACTIVATE_CDC=1 -DUSBD_COMPOSITE_USE_IAD=1 -c -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../System/Inc -I../Shell/Inc -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CompositeBuilder/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/MSC/Inc -I../Drivers/SSD1351 -I../Drivers/lvgl -I../Drivers -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-lvgl-2f-src-2f-draw

clean-Drivers-2f-lvgl-2f-src-2f-draw:
	-$(RM) ./Drivers/lvgl/src/draw/lv_draw.cyclo ./Drivers/lvgl/src/draw/lv_draw.d ./Drivers/lvgl/src/draw/lv_draw.o ./Drivers/lvgl/src/draw/lv_draw.su ./Drivers/lvgl/src/draw/lv_draw_arc.cyclo ./Drivers/lvgl/src/draw/lv_draw_arc.d ./Drivers/lvgl/src/draw/lv_draw_arc.o ./Drivers/lvgl/src/draw/lv_draw_arc.su ./Drivers/lvgl/src/draw/lv_draw_img.cyclo ./Drivers/lvgl/src/draw/lv_draw_img.d ./Drivers/lvgl/src/draw/lv_draw_img.o ./Drivers/lvgl/src/draw/lv_draw_img.su ./Drivers/lvgl/src/draw/lv_draw_label.cyclo ./Drivers/lvgl/src/draw/lv_draw_label.d ./Drivers/lvgl/src/draw/lv_draw_label.o ./Drivers/lvgl/src/draw/lv_draw_label.su ./Drivers/lvgl/src/draw/lv_draw_layer.cyclo ./Drivers/lvgl/src/draw/lv_draw_layer.d ./Drivers/lvgl/src/draw/lv_draw_layer.o ./Drivers/lvgl/src/draw/lv_draw_layer.su ./Drivers/lvgl/src/draw/lv_draw_line.cyclo ./Drivers/lvgl/src/draw/lv_draw_line.d ./Drivers/lvgl/src/draw/lv_draw_line.o ./Drivers/lvgl/src/draw/lv_draw_line.su ./Drivers/lvgl/src/draw/lv_draw_mask.cyclo ./Drivers/lvgl/src/draw/lv_draw_mask.d ./Drivers/lvgl/src/draw/lv_draw_mask.o ./Drivers/lvgl/src/draw/lv_draw_mask.su ./Drivers/lvgl/src/draw/lv_draw_rect.cyclo ./Drivers/lvgl/src/draw/lv_draw_rect.d ./Drivers/lvgl/src/draw/lv_draw_rect.o ./Drivers/lvgl/src/draw/lv_draw_rect.su ./Drivers/lvgl/src/draw/lv_draw_transform.cyclo ./Drivers/lvgl/src/draw/lv_draw_transform.d ./Drivers/lvgl/src/draw/lv_draw_transform.o ./Drivers/lvgl/src/draw/lv_draw_transform.su ./Drivers/lvgl/src/draw/lv_draw_triangle.cyclo ./Drivers/lvgl/src/draw/lv_draw_triangle.d ./Drivers/lvgl/src/draw/lv_draw_triangle.o ./Drivers/lvgl/src/draw/lv_draw_triangle.su ./Drivers/lvgl/src/draw/lv_img_buf.cyclo ./Drivers/lvgl/src/draw/lv_img_buf.d ./Drivers/lvgl/src/draw/lv_img_buf.o ./Drivers/lvgl/src/draw/lv_img_buf.su ./Drivers/lvgl/src/draw/lv_img_cache.cyclo ./Drivers/lvgl/src/draw/lv_img_cache.d ./Drivers/lvgl/src/draw/lv_img_cache.o ./Drivers/lvgl/src/draw/lv_img_cache.su ./Drivers/lvgl/src/draw/lv_img_decoder.cyclo ./Drivers/lvgl/src/draw/lv_img_decoder.d ./Drivers/lvgl/src/draw/lv_img_decoder.o ./Drivers/lvgl/src/draw/lv_img_decoder.su

.PHONY: clean-Drivers-2f-lvgl-2f-src-2f-draw

