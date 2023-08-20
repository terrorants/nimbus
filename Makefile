.PHONY: all flash

all:
	make -j7 -C Debug all

flash: Debug/nimbus.bin
	dfu-util -a 0 --dfuse-address 0x08000000:leave -D $<

Debug/nimbus.bin: Debug/nimbus.elf
	arm-none-eabi-objcopy -O binary $< $@

Debug/nimbus.elf:
	make -j7 -C Debug all

%:
	make -j7 -C Debug $*
