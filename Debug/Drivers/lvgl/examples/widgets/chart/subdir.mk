################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/lvgl/examples/widgets/chart/lv_example_chart_1.c \
../Drivers/lvgl/examples/widgets/chart/lv_example_chart_2.c \
../Drivers/lvgl/examples/widgets/chart/lv_example_chart_3.c \
../Drivers/lvgl/examples/widgets/chart/lv_example_chart_4.c \
../Drivers/lvgl/examples/widgets/chart/lv_example_chart_5.c \
../Drivers/lvgl/examples/widgets/chart/lv_example_chart_6.c \
../Drivers/lvgl/examples/widgets/chart/lv_example_chart_7.c \
../Drivers/lvgl/examples/widgets/chart/lv_example_chart_8.c \
../Drivers/lvgl/examples/widgets/chart/lv_example_chart_9.c 

OBJS += \
./Drivers/lvgl/examples/widgets/chart/lv_example_chart_1.o \
./Drivers/lvgl/examples/widgets/chart/lv_example_chart_2.o \
./Drivers/lvgl/examples/widgets/chart/lv_example_chart_3.o \
./Drivers/lvgl/examples/widgets/chart/lv_example_chart_4.o \
./Drivers/lvgl/examples/widgets/chart/lv_example_chart_5.o \
./Drivers/lvgl/examples/widgets/chart/lv_example_chart_6.o \
./Drivers/lvgl/examples/widgets/chart/lv_example_chart_7.o \
./Drivers/lvgl/examples/widgets/chart/lv_example_chart_8.o \
./Drivers/lvgl/examples/widgets/chart/lv_example_chart_9.o 

C_DEPS += \
./Drivers/lvgl/examples/widgets/chart/lv_example_chart_1.d \
./Drivers/lvgl/examples/widgets/chart/lv_example_chart_2.d \
./Drivers/lvgl/examples/widgets/chart/lv_example_chart_3.d \
./Drivers/lvgl/examples/widgets/chart/lv_example_chart_4.d \
./Drivers/lvgl/examples/widgets/chart/lv_example_chart_5.d \
./Drivers/lvgl/examples/widgets/chart/lv_example_chart_6.d \
./Drivers/lvgl/examples/widgets/chart/lv_example_chart_7.d \
./Drivers/lvgl/examples/widgets/chart/lv_example_chart_8.d \
./Drivers/lvgl/examples/widgets/chart/lv_example_chart_9.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/lvgl/examples/widgets/chart/%.o Drivers/lvgl/examples/widgets/chart/%.su Drivers/lvgl/examples/widgets/chart/%.cyclo: ../Drivers/lvgl/examples/widgets/chart/%.c Drivers/lvgl/examples/widgets/chart/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F405xx -DUSBD_CMPSIT_ACTIVATE_MSC=1 -DUSBD_CMPSIT_ACTIVATE_CDC=1 -DUSBD_COMPOSITE_USE_IAD=1 -c -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../System/Inc -I../Shell/Inc -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CompositeBuilder/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/MSC/Inc -I../Drivers/SSD1351 -I../Drivers/lvgl -I../Drivers -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-lvgl-2f-examples-2f-widgets-2f-chart

clean-Drivers-2f-lvgl-2f-examples-2f-widgets-2f-chart:
	-$(RM) ./Drivers/lvgl/examples/widgets/chart/lv_example_chart_1.cyclo ./Drivers/lvgl/examples/widgets/chart/lv_example_chart_1.d ./Drivers/lvgl/examples/widgets/chart/lv_example_chart_1.o ./Drivers/lvgl/examples/widgets/chart/lv_example_chart_1.su ./Drivers/lvgl/examples/widgets/chart/lv_example_chart_2.cyclo ./Drivers/lvgl/examples/widgets/chart/lv_example_chart_2.d ./Drivers/lvgl/examples/widgets/chart/lv_example_chart_2.o ./Drivers/lvgl/examples/widgets/chart/lv_example_chart_2.su ./Drivers/lvgl/examples/widgets/chart/lv_example_chart_3.cyclo ./Drivers/lvgl/examples/widgets/chart/lv_example_chart_3.d ./Drivers/lvgl/examples/widgets/chart/lv_example_chart_3.o ./Drivers/lvgl/examples/widgets/chart/lv_example_chart_3.su ./Drivers/lvgl/examples/widgets/chart/lv_example_chart_4.cyclo ./Drivers/lvgl/examples/widgets/chart/lv_example_chart_4.d ./Drivers/lvgl/examples/widgets/chart/lv_example_chart_4.o ./Drivers/lvgl/examples/widgets/chart/lv_example_chart_4.su ./Drivers/lvgl/examples/widgets/chart/lv_example_chart_5.cyclo ./Drivers/lvgl/examples/widgets/chart/lv_example_chart_5.d ./Drivers/lvgl/examples/widgets/chart/lv_example_chart_5.o ./Drivers/lvgl/examples/widgets/chart/lv_example_chart_5.su ./Drivers/lvgl/examples/widgets/chart/lv_example_chart_6.cyclo ./Drivers/lvgl/examples/widgets/chart/lv_example_chart_6.d ./Drivers/lvgl/examples/widgets/chart/lv_example_chart_6.o ./Drivers/lvgl/examples/widgets/chart/lv_example_chart_6.su ./Drivers/lvgl/examples/widgets/chart/lv_example_chart_7.cyclo ./Drivers/lvgl/examples/widgets/chart/lv_example_chart_7.d ./Drivers/lvgl/examples/widgets/chart/lv_example_chart_7.o ./Drivers/lvgl/examples/widgets/chart/lv_example_chart_7.su ./Drivers/lvgl/examples/widgets/chart/lv_example_chart_8.cyclo ./Drivers/lvgl/examples/widgets/chart/lv_example_chart_8.d ./Drivers/lvgl/examples/widgets/chart/lv_example_chart_8.o ./Drivers/lvgl/examples/widgets/chart/lv_example_chart_8.su ./Drivers/lvgl/examples/widgets/chart/lv_example_chart_9.cyclo ./Drivers/lvgl/examples/widgets/chart/lv_example_chart_9.d ./Drivers/lvgl/examples/widgets/chart/lv_example_chart_9.o ./Drivers/lvgl/examples/widgets/chart/lv_example_chart_9.su

.PHONY: clean-Drivers-2f-lvgl-2f-examples-2f-widgets-2f-chart

