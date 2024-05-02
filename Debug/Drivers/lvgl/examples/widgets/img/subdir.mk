################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/lvgl/examples/widgets/img/lv_example_img_1.c \
../Drivers/lvgl/examples/widgets/img/lv_example_img_2.c \
../Drivers/lvgl/examples/widgets/img/lv_example_img_3.c \
../Drivers/lvgl/examples/widgets/img/lv_example_img_4.c 

OBJS += \
./Drivers/lvgl/examples/widgets/img/lv_example_img_1.o \
./Drivers/lvgl/examples/widgets/img/lv_example_img_2.o \
./Drivers/lvgl/examples/widgets/img/lv_example_img_3.o \
./Drivers/lvgl/examples/widgets/img/lv_example_img_4.o 

C_DEPS += \
./Drivers/lvgl/examples/widgets/img/lv_example_img_1.d \
./Drivers/lvgl/examples/widgets/img/lv_example_img_2.d \
./Drivers/lvgl/examples/widgets/img/lv_example_img_3.d \
./Drivers/lvgl/examples/widgets/img/lv_example_img_4.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/lvgl/examples/widgets/img/%.o Drivers/lvgl/examples/widgets/img/%.su Drivers/lvgl/examples/widgets/img/%.cyclo: ../Drivers/lvgl/examples/widgets/img/%.c Drivers/lvgl/examples/widgets/img/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F405xx -DUSBD_CMPSIT_ACTIVATE_MSC=1 -DUSBD_CMPSIT_ACTIVATE_CDC=1 -DUSBD_COMPOSITE_USE_IAD=1 -c -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../System/Inc -I../Shell/Inc -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CompositeBuilder/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/MSC/Inc -I../Drivers/SSD1351 -I../Drivers/lvgl -I../Drivers -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-lvgl-2f-examples-2f-widgets-2f-img

clean-Drivers-2f-lvgl-2f-examples-2f-widgets-2f-img:
	-$(RM) ./Drivers/lvgl/examples/widgets/img/lv_example_img_1.cyclo ./Drivers/lvgl/examples/widgets/img/lv_example_img_1.d ./Drivers/lvgl/examples/widgets/img/lv_example_img_1.o ./Drivers/lvgl/examples/widgets/img/lv_example_img_1.su ./Drivers/lvgl/examples/widgets/img/lv_example_img_2.cyclo ./Drivers/lvgl/examples/widgets/img/lv_example_img_2.d ./Drivers/lvgl/examples/widgets/img/lv_example_img_2.o ./Drivers/lvgl/examples/widgets/img/lv_example_img_2.su ./Drivers/lvgl/examples/widgets/img/lv_example_img_3.cyclo ./Drivers/lvgl/examples/widgets/img/lv_example_img_3.d ./Drivers/lvgl/examples/widgets/img/lv_example_img_3.o ./Drivers/lvgl/examples/widgets/img/lv_example_img_3.su ./Drivers/lvgl/examples/widgets/img/lv_example_img_4.cyclo ./Drivers/lvgl/examples/widgets/img/lv_example_img_4.d ./Drivers/lvgl/examples/widgets/img/lv_example_img_4.o ./Drivers/lvgl/examples/widgets/img/lv_example_img_4.su

.PHONY: clean-Drivers-2f-lvgl-2f-examples-2f-widgets-2f-img

