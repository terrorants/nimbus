################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/lvgl/examples/layouts/flex/lv_example_flex_1.c \
../Drivers/lvgl/examples/layouts/flex/lv_example_flex_2.c \
../Drivers/lvgl/examples/layouts/flex/lv_example_flex_3.c \
../Drivers/lvgl/examples/layouts/flex/lv_example_flex_4.c \
../Drivers/lvgl/examples/layouts/flex/lv_example_flex_5.c \
../Drivers/lvgl/examples/layouts/flex/lv_example_flex_6.c 

OBJS += \
./Drivers/lvgl/examples/layouts/flex/lv_example_flex_1.o \
./Drivers/lvgl/examples/layouts/flex/lv_example_flex_2.o \
./Drivers/lvgl/examples/layouts/flex/lv_example_flex_3.o \
./Drivers/lvgl/examples/layouts/flex/lv_example_flex_4.o \
./Drivers/lvgl/examples/layouts/flex/lv_example_flex_5.o \
./Drivers/lvgl/examples/layouts/flex/lv_example_flex_6.o 

C_DEPS += \
./Drivers/lvgl/examples/layouts/flex/lv_example_flex_1.d \
./Drivers/lvgl/examples/layouts/flex/lv_example_flex_2.d \
./Drivers/lvgl/examples/layouts/flex/lv_example_flex_3.d \
./Drivers/lvgl/examples/layouts/flex/lv_example_flex_4.d \
./Drivers/lvgl/examples/layouts/flex/lv_example_flex_5.d \
./Drivers/lvgl/examples/layouts/flex/lv_example_flex_6.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/lvgl/examples/layouts/flex/%.o Drivers/lvgl/examples/layouts/flex/%.su Drivers/lvgl/examples/layouts/flex/%.cyclo: ../Drivers/lvgl/examples/layouts/flex/%.c Drivers/lvgl/examples/layouts/flex/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F405xx -DUSBD_CMPSIT_ACTIVATE_MSC=1 -DUSBD_CMPSIT_ACTIVATE_CDC=1 -DUSBD_COMPOSITE_USE_IAD=1 -c -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../System/Inc -I../Shell/Inc -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CompositeBuilder/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/MSC/Inc -I../Drivers/SSD1351 -I../Drivers/lvgl -I../Drivers -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-lvgl-2f-examples-2f-layouts-2f-flex

clean-Drivers-2f-lvgl-2f-examples-2f-layouts-2f-flex:
	-$(RM) ./Drivers/lvgl/examples/layouts/flex/lv_example_flex_1.cyclo ./Drivers/lvgl/examples/layouts/flex/lv_example_flex_1.d ./Drivers/lvgl/examples/layouts/flex/lv_example_flex_1.o ./Drivers/lvgl/examples/layouts/flex/lv_example_flex_1.su ./Drivers/lvgl/examples/layouts/flex/lv_example_flex_2.cyclo ./Drivers/lvgl/examples/layouts/flex/lv_example_flex_2.d ./Drivers/lvgl/examples/layouts/flex/lv_example_flex_2.o ./Drivers/lvgl/examples/layouts/flex/lv_example_flex_2.su ./Drivers/lvgl/examples/layouts/flex/lv_example_flex_3.cyclo ./Drivers/lvgl/examples/layouts/flex/lv_example_flex_3.d ./Drivers/lvgl/examples/layouts/flex/lv_example_flex_3.o ./Drivers/lvgl/examples/layouts/flex/lv_example_flex_3.su ./Drivers/lvgl/examples/layouts/flex/lv_example_flex_4.cyclo ./Drivers/lvgl/examples/layouts/flex/lv_example_flex_4.d ./Drivers/lvgl/examples/layouts/flex/lv_example_flex_4.o ./Drivers/lvgl/examples/layouts/flex/lv_example_flex_4.su ./Drivers/lvgl/examples/layouts/flex/lv_example_flex_5.cyclo ./Drivers/lvgl/examples/layouts/flex/lv_example_flex_5.d ./Drivers/lvgl/examples/layouts/flex/lv_example_flex_5.o ./Drivers/lvgl/examples/layouts/flex/lv_example_flex_5.su ./Drivers/lvgl/examples/layouts/flex/lv_example_flex_6.cyclo ./Drivers/lvgl/examples/layouts/flex/lv_example_flex_6.d ./Drivers/lvgl/examples/layouts/flex/lv_example_flex_6.o ./Drivers/lvgl/examples/layouts/flex/lv_example_flex_6.su

.PHONY: clean-Drivers-2f-lvgl-2f-examples-2f-layouts-2f-flex

