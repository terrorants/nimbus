################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../System/Src/buttons.c \
../System/Src/cbuf.c \
../System/Src/drv_vcp.c \
../System/Src/events.c \
../System/Src/flash_api.c \
../System/Src/logger.c \
../System/Src/nv.c \
../System/Src/oled_manager.c \
../System/Src/tmr.c \
../System/Src/xsnprintf.c 

OBJS += \
./System/Src/buttons.o \
./System/Src/cbuf.o \
./System/Src/drv_vcp.o \
./System/Src/events.o \
./System/Src/flash_api.o \
./System/Src/logger.o \
./System/Src/nv.o \
./System/Src/oled_manager.o \
./System/Src/tmr.o \
./System/Src/xsnprintf.o 

C_DEPS += \
./System/Src/buttons.d \
./System/Src/cbuf.d \
./System/Src/drv_vcp.d \
./System/Src/events.d \
./System/Src/flash_api.d \
./System/Src/logger.d \
./System/Src/nv.d \
./System/Src/oled_manager.d \
./System/Src/tmr.d \
./System/Src/xsnprintf.d 


# Each subdirectory must supply rules for building sources it contributes
System/Src/%.o System/Src/%.su System/Src/%.cyclo: ../System/Src/%.c System/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F405xx -DUSBD_CMPSIT_ACTIVATE_MSC=1 -DUSBD_CMPSIT_ACTIVATE_CDC=1 -DUSBD_COMPOSITE_USE_IAD=1 -c -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../System/Inc -I../Shell/Inc -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CompositeBuilder/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/MSC/Inc -I../Drivers/SSD1351 -I../Drivers/lvgl -I../Drivers -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-System-2f-Src

clean-System-2f-Src:
	-$(RM) ./System/Src/buttons.cyclo ./System/Src/buttons.d ./System/Src/buttons.o ./System/Src/buttons.su ./System/Src/cbuf.cyclo ./System/Src/cbuf.d ./System/Src/cbuf.o ./System/Src/cbuf.su ./System/Src/drv_vcp.cyclo ./System/Src/drv_vcp.d ./System/Src/drv_vcp.o ./System/Src/drv_vcp.su ./System/Src/events.cyclo ./System/Src/events.d ./System/Src/events.o ./System/Src/events.su ./System/Src/flash_api.cyclo ./System/Src/flash_api.d ./System/Src/flash_api.o ./System/Src/flash_api.su ./System/Src/logger.cyclo ./System/Src/logger.d ./System/Src/logger.o ./System/Src/logger.su ./System/Src/nv.cyclo ./System/Src/nv.d ./System/Src/nv.o ./System/Src/nv.su ./System/Src/oled_manager.cyclo ./System/Src/oled_manager.d ./System/Src/oled_manager.o ./System/Src/oled_manager.su ./System/Src/tmr.cyclo ./System/Src/tmr.d ./System/Src/tmr.o ./System/Src/tmr.su ./System/Src/xsnprintf.cyclo ./System/Src/xsnprintf.d ./System/Src/xsnprintf.o ./System/Src/xsnprintf.su

.PHONY: clean-System-2f-Src

