MAX_JOBS		:= $(shell sysctl -n hw.ncpu)

.PHONY: all flash erase-and-flash

all:
	make -j $(MAX_JOBS) -C Debug all

flash: Debug/nimbus.bin
	dfu-util -a 0 --dfuse-address 0x08000000:leave -D $<

erase-and-flash: Debug/nimbus.bin
	dfu-util -a 0 --dfuse-address 0x08000000:mass-erase:force:leave -D $<

Debug/nimbus.bin: Debug/nimbus.elf
	arm-none-eabi-objcopy -O binary $< $@

Debug/nimbus.elf:
	make -j $(MAX_JOBS) -C Debug all

%:
	make -j $(MAX_JOBS) -C Debug $*
