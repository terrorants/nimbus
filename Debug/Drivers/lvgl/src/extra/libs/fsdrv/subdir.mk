################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/lvgl/src/extra/libs/fsdrv/lv_fs_fatfs.c \
../Drivers/lvgl/src/extra/libs/fsdrv/lv_fs_posix.c \
../Drivers/lvgl/src/extra/libs/fsdrv/lv_fs_stdio.c \
../Drivers/lvgl/src/extra/libs/fsdrv/lv_fs_win32.c 

OBJS += \
./Drivers/lvgl/src/extra/libs/fsdrv/lv_fs_fatfs.o \
./Drivers/lvgl/src/extra/libs/fsdrv/lv_fs_posix.o \
./Drivers/lvgl/src/extra/libs/fsdrv/lv_fs_stdio.o \
./Drivers/lvgl/src/extra/libs/fsdrv/lv_fs_win32.o 

C_DEPS += \
./Drivers/lvgl/src/extra/libs/fsdrv/lv_fs_fatfs.d \
./Drivers/lvgl/src/extra/libs/fsdrv/lv_fs_posix.d \
./Drivers/lvgl/src/extra/libs/fsdrv/lv_fs_stdio.d \
./Drivers/lvgl/src/extra/libs/fsdrv/lv_fs_win32.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/lvgl/src/extra/libs/fsdrv/%.o Drivers/lvgl/src/extra/libs/fsdrv/%.su Drivers/lvgl/src/extra/libs/fsdrv/%.cyclo: ../Drivers/lvgl/src/extra/libs/fsdrv/%.c Drivers/lvgl/src/extra/libs/fsdrv/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F405xx -DUSBD_CMPSIT_ACTIVATE_MSC=1 -DUSBD_CMPSIT_ACTIVATE_CDC=1 -DUSBD_COMPOSITE_USE_IAD=1 -c -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../System/Inc -I../Shell/Inc -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CompositeBuilder/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/MSC/Inc -I../Drivers/SSD1351 -I../Drivers/lvgl -I../Drivers -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-lvgl-2f-src-2f-extra-2f-libs-2f-fsdrv

clean-Drivers-2f-lvgl-2f-src-2f-extra-2f-libs-2f-fsdrv:
	-$(RM) ./Drivers/lvgl/src/extra/libs/fsdrv/lv_fs_fatfs.cyclo ./Drivers/lvgl/src/extra/libs/fsdrv/lv_fs_fatfs.d ./Drivers/lvgl/src/extra/libs/fsdrv/lv_fs_fatfs.o ./Drivers/lvgl/src/extra/libs/fsdrv/lv_fs_fatfs.su ./Drivers/lvgl/src/extra/libs/fsdrv/lv_fs_posix.cyclo ./Drivers/lvgl/src/extra/libs/fsdrv/lv_fs_posix.d ./Drivers/lvgl/src/extra/libs/fsdrv/lv_fs_posix.o ./Drivers/lvgl/src/extra/libs/fsdrv/lv_fs_posix.su ./Drivers/lvgl/src/extra/libs/fsdrv/lv_fs_stdio.cyclo ./Drivers/lvgl/src/extra/libs/fsdrv/lv_fs_stdio.d ./Drivers/lvgl/src/extra/libs/fsdrv/lv_fs_stdio.o ./Drivers/lvgl/src/extra/libs/fsdrv/lv_fs_stdio.su ./Drivers/lvgl/src/extra/libs/fsdrv/lv_fs_win32.cyclo ./Drivers/lvgl/src/extra/libs/fsdrv/lv_fs_win32.d ./Drivers/lvgl/src/extra/libs/fsdrv/lv_fs_win32.o ./Drivers/lvgl/src/extra/libs/fsdrv/lv_fs_win32.su

.PHONY: clean-Drivers-2f-lvgl-2f-src-2f-extra-2f-libs-2f-fsdrv

