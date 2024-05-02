################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/SSD1351/fonts.c \
../Drivers/SSD1351/ssd1351.c \
../Drivers/SSD1351/testimg.c 

OBJS += \
./Drivers/SSD1351/fonts.o \
./Drivers/SSD1351/ssd1351.o \
./Drivers/SSD1351/testimg.o 

C_DEPS += \
./Drivers/SSD1351/fonts.d \
./Drivers/SSD1351/ssd1351.d \
./Drivers/SSD1351/testimg.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/SSD1351/%.o Drivers/SSD1351/%.su Drivers/SSD1351/%.cyclo: ../Drivers/SSD1351/%.c Drivers/SSD1351/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F405xx -DUSBD_CMPSIT_ACTIVATE_MSC=1 -DUSBD_CMPSIT_ACTIVATE_CDC=1 -DUSBD_COMPOSITE_USE_IAD=1 -c -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../System/Inc -I../Shell/Inc -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CompositeBuilder/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/MSC/Inc -I../Drivers/SSD1351 -I../Drivers/lvgl -I../Drivers -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-SSD1351

clean-Drivers-2f-SSD1351:
	-$(RM) ./Drivers/SSD1351/fonts.cyclo ./Drivers/SSD1351/fonts.d ./Drivers/SSD1351/fonts.o ./Drivers/SSD1351/fonts.su ./Drivers/SSD1351/ssd1351.cyclo ./Drivers/SSD1351/ssd1351.d ./Drivers/SSD1351/ssd1351.o ./Drivers/SSD1351/ssd1351.su ./Drivers/SSD1351/testimg.cyclo ./Drivers/SSD1351/testimg.d ./Drivers/SSD1351/testimg.o ./Drivers/SSD1351/testimg.su

.PHONY: clean-Drivers-2f-SSD1351

