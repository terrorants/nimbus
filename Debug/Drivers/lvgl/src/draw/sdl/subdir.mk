################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/lvgl/src/draw/sdl/lv_draw_sdl.c \
../Drivers/lvgl/src/draw/sdl/lv_draw_sdl_arc.c \
../Drivers/lvgl/src/draw/sdl/lv_draw_sdl_bg.c \
../Drivers/lvgl/src/draw/sdl/lv_draw_sdl_composite.c \
../Drivers/lvgl/src/draw/sdl/lv_draw_sdl_img.c \
../Drivers/lvgl/src/draw/sdl/lv_draw_sdl_label.c \
../Drivers/lvgl/src/draw/sdl/lv_draw_sdl_layer.c \
../Drivers/lvgl/src/draw/sdl/lv_draw_sdl_line.c \
../Drivers/lvgl/src/draw/sdl/lv_draw_sdl_mask.c \
../Drivers/lvgl/src/draw/sdl/lv_draw_sdl_polygon.c \
../Drivers/lvgl/src/draw/sdl/lv_draw_sdl_rect.c \
../Drivers/lvgl/src/draw/sdl/lv_draw_sdl_stack_blur.c \
../Drivers/lvgl/src/draw/sdl/lv_draw_sdl_texture_cache.c \
../Drivers/lvgl/src/draw/sdl/lv_draw_sdl_utils.c 

OBJS += \
./Drivers/lvgl/src/draw/sdl/lv_draw_sdl.o \
./Drivers/lvgl/src/draw/sdl/lv_draw_sdl_arc.o \
./Drivers/lvgl/src/draw/sdl/lv_draw_sdl_bg.o \
./Drivers/lvgl/src/draw/sdl/lv_draw_sdl_composite.o \
./Drivers/lvgl/src/draw/sdl/lv_draw_sdl_img.o \
./Drivers/lvgl/src/draw/sdl/lv_draw_sdl_label.o \
./Drivers/lvgl/src/draw/sdl/lv_draw_sdl_layer.o \
./Drivers/lvgl/src/draw/sdl/lv_draw_sdl_line.o \
./Drivers/lvgl/src/draw/sdl/lv_draw_sdl_mask.o \
./Drivers/lvgl/src/draw/sdl/lv_draw_sdl_polygon.o \
./Drivers/lvgl/src/draw/sdl/lv_draw_sdl_rect.o \
./Drivers/lvgl/src/draw/sdl/lv_draw_sdl_stack_blur.o \
./Drivers/lvgl/src/draw/sdl/lv_draw_sdl_texture_cache.o \
./Drivers/lvgl/src/draw/sdl/lv_draw_sdl_utils.o 

C_DEPS += \
./Drivers/lvgl/src/draw/sdl/lv_draw_sdl.d \
./Drivers/lvgl/src/draw/sdl/lv_draw_sdl_arc.d \
./Drivers/lvgl/src/draw/sdl/lv_draw_sdl_bg.d \
./Drivers/lvgl/src/draw/sdl/lv_draw_sdl_composite.d \
./Drivers/lvgl/src/draw/sdl/lv_draw_sdl_img.d \
./Drivers/lvgl/src/draw/sdl/lv_draw_sdl_label.d \
./Drivers/lvgl/src/draw/sdl/lv_draw_sdl_layer.d \
./Drivers/lvgl/src/draw/sdl/lv_draw_sdl_line.d \
./Drivers/lvgl/src/draw/sdl/lv_draw_sdl_mask.d \
./Drivers/lvgl/src/draw/sdl/lv_draw_sdl_polygon.d \
./Drivers/lvgl/src/draw/sdl/lv_draw_sdl_rect.d \
./Drivers/lvgl/src/draw/sdl/lv_draw_sdl_stack_blur.d \
./Drivers/lvgl/src/draw/sdl/lv_draw_sdl_texture_cache.d \
./Drivers/lvgl/src/draw/sdl/lv_draw_sdl_utils.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/lvgl/src/draw/sdl/%.o Drivers/lvgl/src/draw/sdl/%.su Drivers/lvgl/src/draw/sdl/%.cyclo: ../Drivers/lvgl/src/draw/sdl/%.c Drivers/lvgl/src/draw/sdl/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F405xx -DUSBD_CMPSIT_ACTIVATE_MSC=1 -DUSBD_CMPSIT_ACTIVATE_CDC=1 -DUSBD_COMPOSITE_USE_IAD=1 -c -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../System/Inc -I../Shell/Inc -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CompositeBuilder/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/MSC/Inc -I../Drivers/SSD1351 -I../Drivers/lvgl -I../Drivers -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-lvgl-2f-src-2f-draw-2f-sdl

clean-Drivers-2f-lvgl-2f-src-2f-draw-2f-sdl:
	-$(RM) ./Drivers/lvgl/src/draw/sdl/lv_draw_sdl.cyclo ./Drivers/lvgl/src/draw/sdl/lv_draw_sdl.d ./Drivers/lvgl/src/draw/sdl/lv_draw_sdl.o ./Drivers/lvgl/src/draw/sdl/lv_draw_sdl.su ./Drivers/lvgl/src/draw/sdl/lv_draw_sdl_arc.cyclo ./Drivers/lvgl/src/draw/sdl/lv_draw_sdl_arc.d ./Drivers/lvgl/src/draw/sdl/lv_draw_sdl_arc.o ./Drivers/lvgl/src/draw/sdl/lv_draw_sdl_arc.su ./Drivers/lvgl/src/draw/sdl/lv_draw_sdl_bg.cyclo ./Drivers/lvgl/src/draw/sdl/lv_draw_sdl_bg.d ./Drivers/lvgl/src/draw/sdl/lv_draw_sdl_bg.o ./Drivers/lvgl/src/draw/sdl/lv_draw_sdl_bg.su ./Drivers/lvgl/src/draw/sdl/lv_draw_sdl_composite.cyclo ./Drivers/lvgl/src/draw/sdl/lv_draw_sdl_composite.d ./Drivers/lvgl/src/draw/sdl/lv_draw_sdl_composite.o ./Drivers/lvgl/src/draw/sdl/lv_draw_sdl_composite.su ./Drivers/lvgl/src/draw/sdl/lv_draw_sdl_img.cyclo ./Drivers/lvgl/src/draw/sdl/lv_draw_sdl_img.d ./Drivers/lvgl/src/draw/sdl/lv_draw_sdl_img.o ./Drivers/lvgl/src/draw/sdl/lv_draw_sdl_img.su ./Drivers/lvgl/src/draw/sdl/lv_draw_sdl_label.cyclo ./Drivers/lvgl/src/draw/sdl/lv_draw_sdl_label.d ./Drivers/lvgl/src/draw/sdl/lv_draw_sdl_label.o ./Drivers/lvgl/src/draw/sdl/lv_draw_sdl_label.su ./Drivers/lvgl/src/draw/sdl/lv_draw_sdl_layer.cyclo ./Drivers/lvgl/src/draw/sdl/lv_draw_sdl_layer.d ./Drivers/lvgl/src/draw/sdl/lv_draw_sdl_layer.o ./Drivers/lvgl/src/draw/sdl/lv_draw_sdl_layer.su ./Drivers/lvgl/src/draw/sdl/lv_draw_sdl_line.cyclo ./Drivers/lvgl/src/draw/sdl/lv_draw_sdl_line.d ./Drivers/lvgl/src/draw/sdl/lv_draw_sdl_line.o ./Drivers/lvgl/src/draw/sdl/lv_draw_sdl_line.su ./Drivers/lvgl/src/draw/sdl/lv_draw_sdl_mask.cyclo ./Drivers/lvgl/src/draw/sdl/lv_draw_sdl_mask.d ./Drivers/lvgl/src/draw/sdl/lv_draw_sdl_mask.o ./Drivers/lvgl/src/draw/sdl/lv_draw_sdl_mask.su ./Drivers/lvgl/src/draw/sdl/lv_draw_sdl_polygon.cyclo ./Drivers/lvgl/src/draw/sdl/lv_draw_sdl_polygon.d ./Drivers/lvgl/src/draw/sdl/lv_draw_sdl_polygon.o ./Drivers/lvgl/src/draw/sdl/lv_draw_sdl_polygon.su ./Drivers/lvgl/src/draw/sdl/lv_draw_sdl_rect.cyclo ./Drivers/lvgl/src/draw/sdl/lv_draw_sdl_rect.d ./Drivers/lvgl/src/draw/sdl/lv_draw_sdl_rect.o ./Drivers/lvgl/src/draw/sdl/lv_draw_sdl_rect.su ./Drivers/lvgl/src/draw/sdl/lv_draw_sdl_stack_blur.cyclo ./Drivers/lvgl/src/draw/sdl/lv_draw_sdl_stack_blur.d ./Drivers/lvgl/src/draw/sdl/lv_draw_sdl_stack_blur.o ./Drivers/lvgl/src/draw/sdl/lv_draw_sdl_stack_blur.su ./Drivers/lvgl/src/draw/sdl/lv_draw_sdl_texture_cache.cyclo ./Drivers/lvgl/src/draw/sdl/lv_draw_sdl_texture_cache.d ./Drivers/lvgl/src/draw/sdl/lv_draw_sdl_texture_cache.o ./Drivers/lvgl/src/draw/sdl/lv_draw_sdl_texture_cache.su ./Drivers/lvgl/src/draw/sdl/lv_draw_sdl_utils.cyclo ./Drivers/lvgl/src/draw/sdl/lv_draw_sdl_utils.d ./Drivers/lvgl/src/draw/sdl/lv_draw_sdl_utils.o ./Drivers/lvgl/src/draw/sdl/lv_draw_sdl_utils.su

.PHONY: clean-Drivers-2f-lvgl-2f-src-2f-draw-2f-sdl

