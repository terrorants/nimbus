################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Shell/Src/tk_shell.c \
../Shell/Src/tk_shell_disp.c \
../Shell/Src/tk_shell_gpio.c \
../Shell/Src/tk_shell_i2c.c \
../Shell/Src/tk_shell_log.c \
../Shell/Src/tk_shell_nv.c \
../Shell/Src/tk_shell_sd.c \
../Shell/Src/tk_shell_sys.c 

OBJS += \
./Shell/Src/tk_shell.o \
./Shell/Src/tk_shell_disp.o \
./Shell/Src/tk_shell_gpio.o \
./Shell/Src/tk_shell_i2c.o \
./Shell/Src/tk_shell_log.o \
./Shell/Src/tk_shell_nv.o \
./Shell/Src/tk_shell_sd.o \
./Shell/Src/tk_shell_sys.o 

C_DEPS += \
./Shell/Src/tk_shell.d \
./Shell/Src/tk_shell_disp.d \
./Shell/Src/tk_shell_gpio.d \
./Shell/Src/tk_shell_i2c.d \
./Shell/Src/tk_shell_log.d \
./Shell/Src/tk_shell_nv.d \
./Shell/Src/tk_shell_sd.d \
./Shell/Src/tk_shell_sys.d 


# Each subdirectory must supply rules for building sources it contributes
Shell/Src/%.o Shell/Src/%.su Shell/Src/%.cyclo: ../Shell/Src/%.c Shell/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F405xx -DUSBD_CMPSIT_ACTIVATE_MSC=1 -DUSBD_CMPSIT_ACTIVATE_CDC=1 -DUSBD_COMPOSITE_USE_IAD=1 -c -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../System/Inc -I../Shell/Inc -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CompositeBuilder/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/MSC/Inc -I../Drivers/SSD1351 -I../Drivers/lvgl -I../Drivers -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Shell-2f-Src

clean-Shell-2f-Src:
	-$(RM) ./Shell/Src/tk_shell.cyclo ./Shell/Src/tk_shell.d ./Shell/Src/tk_shell.o ./Shell/Src/tk_shell.su ./Shell/Src/tk_shell_disp.cyclo ./Shell/Src/tk_shell_disp.d ./Shell/Src/tk_shell_disp.o ./Shell/Src/tk_shell_disp.su ./Shell/Src/tk_shell_gpio.cyclo ./Shell/Src/tk_shell_gpio.d ./Shell/Src/tk_shell_gpio.o ./Shell/Src/tk_shell_gpio.su ./Shell/Src/tk_shell_i2c.cyclo ./Shell/Src/tk_shell_i2c.d ./Shell/Src/tk_shell_i2c.o ./Shell/Src/tk_shell_i2c.su ./Shell/Src/tk_shell_log.cyclo ./Shell/Src/tk_shell_log.d ./Shell/Src/tk_shell_log.o ./Shell/Src/tk_shell_log.su ./Shell/Src/tk_shell_nv.cyclo ./Shell/Src/tk_shell_nv.d ./Shell/Src/tk_shell_nv.o ./Shell/Src/tk_shell_nv.su ./Shell/Src/tk_shell_sd.cyclo ./Shell/Src/tk_shell_sd.d ./Shell/Src/tk_shell_sd.o ./Shell/Src/tk_shell_sd.su ./Shell/Src/tk_shell_sys.cyclo ./Shell/Src/tk_shell_sys.d ./Shell/Src/tk_shell_sys.o ./Shell/Src/tk_shell_sys.su

.PHONY: clean-Shell-2f-Src

