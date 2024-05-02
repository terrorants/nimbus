################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/lvgl/src/core/lv_disp.c \
../Drivers/lvgl/src/core/lv_event.c \
../Drivers/lvgl/src/core/lv_group.c \
../Drivers/lvgl/src/core/lv_indev.c \
../Drivers/lvgl/src/core/lv_indev_scroll.c \
../Drivers/lvgl/src/core/lv_obj.c \
../Drivers/lvgl/src/core/lv_obj_class.c \
../Drivers/lvgl/src/core/lv_obj_draw.c \
../Drivers/lvgl/src/core/lv_obj_pos.c \
../Drivers/lvgl/src/core/lv_obj_scroll.c \
../Drivers/lvgl/src/core/lv_obj_style.c \
../Drivers/lvgl/src/core/lv_obj_style_gen.c \
../Drivers/lvgl/src/core/lv_obj_tree.c \
../Drivers/lvgl/src/core/lv_refr.c \
../Drivers/lvgl/src/core/lv_theme.c 

OBJS += \
./Drivers/lvgl/src/core/lv_disp.o \
./Drivers/lvgl/src/core/lv_event.o \
./Drivers/lvgl/src/core/lv_group.o \
./Drivers/lvgl/src/core/lv_indev.o \
./Drivers/lvgl/src/core/lv_indev_scroll.o \
./Drivers/lvgl/src/core/lv_obj.o \
./Drivers/lvgl/src/core/lv_obj_class.o \
./Drivers/lvgl/src/core/lv_obj_draw.o \
./Drivers/lvgl/src/core/lv_obj_pos.o \
./Drivers/lvgl/src/core/lv_obj_scroll.o \
./Drivers/lvgl/src/core/lv_obj_style.o \
./Drivers/lvgl/src/core/lv_obj_style_gen.o \
./Drivers/lvgl/src/core/lv_obj_tree.o \
./Drivers/lvgl/src/core/lv_refr.o \
./Drivers/lvgl/src/core/lv_theme.o 

C_DEPS += \
./Drivers/lvgl/src/core/lv_disp.d \
./Drivers/lvgl/src/core/lv_event.d \
./Drivers/lvgl/src/core/lv_group.d \
./Drivers/lvgl/src/core/lv_indev.d \
./Drivers/lvgl/src/core/lv_indev_scroll.d \
./Drivers/lvgl/src/core/lv_obj.d \
./Drivers/lvgl/src/core/lv_obj_class.d \
./Drivers/lvgl/src/core/lv_obj_draw.d \
./Drivers/lvgl/src/core/lv_obj_pos.d \
./Drivers/lvgl/src/core/lv_obj_scroll.d \
./Drivers/lvgl/src/core/lv_obj_style.d \
./Drivers/lvgl/src/core/lv_obj_style_gen.d \
./Drivers/lvgl/src/core/lv_obj_tree.d \
./Drivers/lvgl/src/core/lv_refr.d \
./Drivers/lvgl/src/core/lv_theme.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/lvgl/src/core/%.o Drivers/lvgl/src/core/%.su Drivers/lvgl/src/core/%.cyclo: ../Drivers/lvgl/src/core/%.c Drivers/lvgl/src/core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F405xx -DUSBD_CMPSIT_ACTIVATE_MSC=1 -DUSBD_CMPSIT_ACTIVATE_CDC=1 -DUSBD_COMPOSITE_USE_IAD=1 -c -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../System/Inc -I../Shell/Inc -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CompositeBuilder/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/MSC/Inc -I../Drivers/SSD1351 -I../Drivers/lvgl -I../Drivers -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-lvgl-2f-src-2f-core

clean-Drivers-2f-lvgl-2f-src-2f-core:
	-$(RM) ./Drivers/lvgl/src/core/lv_disp.cyclo ./Drivers/lvgl/src/core/lv_disp.d ./Drivers/lvgl/src/core/lv_disp.o ./Drivers/lvgl/src/core/lv_disp.su ./Drivers/lvgl/src/core/lv_event.cyclo ./Drivers/lvgl/src/core/lv_event.d ./Drivers/lvgl/src/core/lv_event.o ./Drivers/lvgl/src/core/lv_event.su ./Drivers/lvgl/src/core/lv_group.cyclo ./Drivers/lvgl/src/core/lv_group.d ./Drivers/lvgl/src/core/lv_group.o ./Drivers/lvgl/src/core/lv_group.su ./Drivers/lvgl/src/core/lv_indev.cyclo ./Drivers/lvgl/src/core/lv_indev.d ./Drivers/lvgl/src/core/lv_indev.o ./Drivers/lvgl/src/core/lv_indev.su ./Drivers/lvgl/src/core/lv_indev_scroll.cyclo ./Drivers/lvgl/src/core/lv_indev_scroll.d ./Drivers/lvgl/src/core/lv_indev_scroll.o ./Drivers/lvgl/src/core/lv_indev_scroll.su ./Drivers/lvgl/src/core/lv_obj.cyclo ./Drivers/lvgl/src/core/lv_obj.d ./Drivers/lvgl/src/core/lv_obj.o ./Drivers/lvgl/src/core/lv_obj.su ./Drivers/lvgl/src/core/lv_obj_class.cyclo ./Drivers/lvgl/src/core/lv_obj_class.d ./Drivers/lvgl/src/core/lv_obj_class.o ./Drivers/lvgl/src/core/lv_obj_class.su ./Drivers/lvgl/src/core/lv_obj_draw.cyclo ./Drivers/lvgl/src/core/lv_obj_draw.d ./Drivers/lvgl/src/core/lv_obj_draw.o ./Drivers/lvgl/src/core/lv_obj_draw.su ./Drivers/lvgl/src/core/lv_obj_pos.cyclo ./Drivers/lvgl/src/core/lv_obj_pos.d ./Drivers/lvgl/src/core/lv_obj_pos.o ./Drivers/lvgl/src/core/lv_obj_pos.su ./Drivers/lvgl/src/core/lv_obj_scroll.cyclo ./Drivers/lvgl/src/core/lv_obj_scroll.d ./Drivers/lvgl/src/core/lv_obj_scroll.o ./Drivers/lvgl/src/core/lv_obj_scroll.su ./Drivers/lvgl/src/core/lv_obj_style.cyclo ./Drivers/lvgl/src/core/lv_obj_style.d ./Drivers/lvgl/src/core/lv_obj_style.o ./Drivers/lvgl/src/core/lv_obj_style.su ./Drivers/lvgl/src/core/lv_obj_style_gen.cyclo ./Drivers/lvgl/src/core/lv_obj_style_gen.d ./Drivers/lvgl/src/core/lv_obj_style_gen.o ./Drivers/lvgl/src/core/lv_obj_style_gen.su ./Drivers/lvgl/src/core/lv_obj_tree.cyclo ./Drivers/lvgl/src/core/lv_obj_tree.d ./Drivers/lvgl/src/core/lv_obj_tree.o ./Drivers/lvgl/src/core/lv_obj_tree.su ./Drivers/lvgl/src/core/lv_refr.cyclo ./Drivers/lvgl/src/core/lv_refr.d ./Drivers/lvgl/src/core/lv_refr.o ./Drivers/lvgl/src/core/lv_refr.su ./Drivers/lvgl/src/core/lv_theme.cyclo ./Drivers/lvgl/src/core/lv_theme.d ./Drivers/lvgl/src/core/lv_theme.o ./Drivers/lvgl/src/core/lv_theme.su

.PHONY: clean-Drivers-2f-lvgl-2f-src-2f-core

