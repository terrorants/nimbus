################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/lvgl/src/widgets/lv_arc.c \
../Drivers/lvgl/src/widgets/lv_bar.c \
../Drivers/lvgl/src/widgets/lv_btn.c \
../Drivers/lvgl/src/widgets/lv_btnmatrix.c \
../Drivers/lvgl/src/widgets/lv_canvas.c \
../Drivers/lvgl/src/widgets/lv_checkbox.c \
../Drivers/lvgl/src/widgets/lv_dropdown.c \
../Drivers/lvgl/src/widgets/lv_img.c \
../Drivers/lvgl/src/widgets/lv_label.c \
../Drivers/lvgl/src/widgets/lv_line.c \
../Drivers/lvgl/src/widgets/lv_objx_templ.c \
../Drivers/lvgl/src/widgets/lv_roller.c \
../Drivers/lvgl/src/widgets/lv_slider.c \
../Drivers/lvgl/src/widgets/lv_switch.c \
../Drivers/lvgl/src/widgets/lv_table.c \
../Drivers/lvgl/src/widgets/lv_textarea.c 

OBJS += \
./Drivers/lvgl/src/widgets/lv_arc.o \
./Drivers/lvgl/src/widgets/lv_bar.o \
./Drivers/lvgl/src/widgets/lv_btn.o \
./Drivers/lvgl/src/widgets/lv_btnmatrix.o \
./Drivers/lvgl/src/widgets/lv_canvas.o \
./Drivers/lvgl/src/widgets/lv_checkbox.o \
./Drivers/lvgl/src/widgets/lv_dropdown.o \
./Drivers/lvgl/src/widgets/lv_img.o \
./Drivers/lvgl/src/widgets/lv_label.o \
./Drivers/lvgl/src/widgets/lv_line.o \
./Drivers/lvgl/src/widgets/lv_objx_templ.o \
./Drivers/lvgl/src/widgets/lv_roller.o \
./Drivers/lvgl/src/widgets/lv_slider.o \
./Drivers/lvgl/src/widgets/lv_switch.o \
./Drivers/lvgl/src/widgets/lv_table.o \
./Drivers/lvgl/src/widgets/lv_textarea.o 

C_DEPS += \
./Drivers/lvgl/src/widgets/lv_arc.d \
./Drivers/lvgl/src/widgets/lv_bar.d \
./Drivers/lvgl/src/widgets/lv_btn.d \
./Drivers/lvgl/src/widgets/lv_btnmatrix.d \
./Drivers/lvgl/src/widgets/lv_canvas.d \
./Drivers/lvgl/src/widgets/lv_checkbox.d \
./Drivers/lvgl/src/widgets/lv_dropdown.d \
./Drivers/lvgl/src/widgets/lv_img.d \
./Drivers/lvgl/src/widgets/lv_label.d \
./Drivers/lvgl/src/widgets/lv_line.d \
./Drivers/lvgl/src/widgets/lv_objx_templ.d \
./Drivers/lvgl/src/widgets/lv_roller.d \
./Drivers/lvgl/src/widgets/lv_slider.d \
./Drivers/lvgl/src/widgets/lv_switch.d \
./Drivers/lvgl/src/widgets/lv_table.d \
./Drivers/lvgl/src/widgets/lv_textarea.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/lvgl/src/widgets/%.o Drivers/lvgl/src/widgets/%.su Drivers/lvgl/src/widgets/%.cyclo: ../Drivers/lvgl/src/widgets/%.c Drivers/lvgl/src/widgets/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F405xx -DUSBD_CMPSIT_ACTIVATE_MSC=1 -DUSBD_CMPSIT_ACTIVATE_CDC=1 -DUSBD_COMPOSITE_USE_IAD=1 -c -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../System/Inc -I../Shell/Inc -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CompositeBuilder/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/MSC/Inc -I../Drivers/SSD1351 -I../Drivers/lvgl -I../Drivers -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-lvgl-2f-src-2f-widgets

clean-Drivers-2f-lvgl-2f-src-2f-widgets:
	-$(RM) ./Drivers/lvgl/src/widgets/lv_arc.cyclo ./Drivers/lvgl/src/widgets/lv_arc.d ./Drivers/lvgl/src/widgets/lv_arc.o ./Drivers/lvgl/src/widgets/lv_arc.su ./Drivers/lvgl/src/widgets/lv_bar.cyclo ./Drivers/lvgl/src/widgets/lv_bar.d ./Drivers/lvgl/src/widgets/lv_bar.o ./Drivers/lvgl/src/widgets/lv_bar.su ./Drivers/lvgl/src/widgets/lv_btn.cyclo ./Drivers/lvgl/src/widgets/lv_btn.d ./Drivers/lvgl/src/widgets/lv_btn.o ./Drivers/lvgl/src/widgets/lv_btn.su ./Drivers/lvgl/src/widgets/lv_btnmatrix.cyclo ./Drivers/lvgl/src/widgets/lv_btnmatrix.d ./Drivers/lvgl/src/widgets/lv_btnmatrix.o ./Drivers/lvgl/src/widgets/lv_btnmatrix.su ./Drivers/lvgl/src/widgets/lv_canvas.cyclo ./Drivers/lvgl/src/widgets/lv_canvas.d ./Drivers/lvgl/src/widgets/lv_canvas.o ./Drivers/lvgl/src/widgets/lv_canvas.su ./Drivers/lvgl/src/widgets/lv_checkbox.cyclo ./Drivers/lvgl/src/widgets/lv_checkbox.d ./Drivers/lvgl/src/widgets/lv_checkbox.o ./Drivers/lvgl/src/widgets/lv_checkbox.su ./Drivers/lvgl/src/widgets/lv_dropdown.cyclo ./Drivers/lvgl/src/widgets/lv_dropdown.d ./Drivers/lvgl/src/widgets/lv_dropdown.o ./Drivers/lvgl/src/widgets/lv_dropdown.su ./Drivers/lvgl/src/widgets/lv_img.cyclo ./Drivers/lvgl/src/widgets/lv_img.d ./Drivers/lvgl/src/widgets/lv_img.o ./Drivers/lvgl/src/widgets/lv_img.su ./Drivers/lvgl/src/widgets/lv_label.cyclo ./Drivers/lvgl/src/widgets/lv_label.d ./Drivers/lvgl/src/widgets/lv_label.o ./Drivers/lvgl/src/widgets/lv_label.su ./Drivers/lvgl/src/widgets/lv_line.cyclo ./Drivers/lvgl/src/widgets/lv_line.d ./Drivers/lvgl/src/widgets/lv_line.o ./Drivers/lvgl/src/widgets/lv_line.su ./Drivers/lvgl/src/widgets/lv_objx_templ.cyclo ./Drivers/lvgl/src/widgets/lv_objx_templ.d ./Drivers/lvgl/src/widgets/lv_objx_templ.o ./Drivers/lvgl/src/widgets/lv_objx_templ.su ./Drivers/lvgl/src/widgets/lv_roller.cyclo ./Drivers/lvgl/src/widgets/lv_roller.d ./Drivers/lvgl/src/widgets/lv_roller.o ./Drivers/lvgl/src/widgets/lv_roller.su ./Drivers/lvgl/src/widgets/lv_slider.cyclo ./Drivers/lvgl/src/widgets/lv_slider.d ./Drivers/lvgl/src/widgets/lv_slider.o ./Drivers/lvgl/src/widgets/lv_slider.su ./Drivers/lvgl/src/widgets/lv_switch.cyclo ./Drivers/lvgl/src/widgets/lv_switch.d ./Drivers/lvgl/src/widgets/lv_switch.o ./Drivers/lvgl/src/widgets/lv_switch.su ./Drivers/lvgl/src/widgets/lv_table.cyclo ./Drivers/lvgl/src/widgets/lv_table.d ./Drivers/lvgl/src/widgets/lv_table.o ./Drivers/lvgl/src/widgets/lv_table.su ./Drivers/lvgl/src/widgets/lv_textarea.cyclo ./Drivers/lvgl/src/widgets/lv_textarea.d ./Drivers/lvgl/src/widgets/lv_textarea.o ./Drivers/lvgl/src/widgets/lv_textarea.su

.PHONY: clean-Drivers-2f-lvgl-2f-src-2f-widgets

