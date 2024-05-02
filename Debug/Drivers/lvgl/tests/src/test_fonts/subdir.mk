################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/lvgl/tests/src/test_fonts/font_1.c \
../Drivers/lvgl/tests/src/test_fonts/font_2.c \
../Drivers/lvgl/tests/src/test_fonts/font_3.c 

OBJS += \
./Drivers/lvgl/tests/src/test_fonts/font_1.o \
./Drivers/lvgl/tests/src/test_fonts/font_2.o \
./Drivers/lvgl/tests/src/test_fonts/font_3.o 

C_DEPS += \
./Drivers/lvgl/tests/src/test_fonts/font_1.d \
./Drivers/lvgl/tests/src/test_fonts/font_2.d \
./Drivers/lvgl/tests/src/test_fonts/font_3.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/lvgl/tests/src/test_fonts/%.o Drivers/lvgl/tests/src/test_fonts/%.su Drivers/lvgl/tests/src/test_fonts/%.cyclo: ../Drivers/lvgl/tests/src/test_fonts/%.c Drivers/lvgl/tests/src/test_fonts/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F405xx -DUSBD_CMPSIT_ACTIVATE_MSC=1 -DUSBD_CMPSIT_ACTIVATE_CDC=1 -DUSBD_COMPOSITE_USE_IAD=1 -c -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../System/Inc -I../Shell/Inc -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CompositeBuilder/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/MSC/Inc -I../Drivers/SSD1351 -I../Drivers/lvgl -I../Drivers -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-lvgl-2f-tests-2f-src-2f-test_fonts

clean-Drivers-2f-lvgl-2f-tests-2f-src-2f-test_fonts:
	-$(RM) ./Drivers/lvgl/tests/src/test_fonts/font_1.cyclo ./Drivers/lvgl/tests/src/test_fonts/font_1.d ./Drivers/lvgl/tests/src/test_fonts/font_1.o ./Drivers/lvgl/tests/src/test_fonts/font_1.su ./Drivers/lvgl/tests/src/test_fonts/font_2.cyclo ./Drivers/lvgl/tests/src/test_fonts/font_2.d ./Drivers/lvgl/tests/src/test_fonts/font_2.o ./Drivers/lvgl/tests/src/test_fonts/font_2.su ./Drivers/lvgl/tests/src/test_fonts/font_3.cyclo ./Drivers/lvgl/tests/src/test_fonts/font_3.d ./Drivers/lvgl/tests/src/test_fonts/font_3.o ./Drivers/lvgl/tests/src/test_fonts/font_3.su

.PHONY: clean-Drivers-2f-lvgl-2f-tests-2f-src-2f-test_fonts

