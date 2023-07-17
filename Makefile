.PHONY: all flash

all:
	make -C Debug all

flash: Debug/nimbus.bin
	dfu-util -a 0 --dfuse-address 0x08000000 -D $<

Debug/nimbus.bin: Debug/nimbus.elf
	arm-none-eabi-objcopy -O binary $< $@

Debug/nimbus.elf:
	make -C Debug all

%:
	make -C Debug $*
