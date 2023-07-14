nimbus
==========

A pedal for ambient pad playback, controlled via footswitches and equipped with an OLED display.

---
## Build Environment (macOS)

Install the following:
1. Xcode for Make
```zsh
$ xcode-select install
```
2. ARM cross compiler
```zsh
$ brew install homebrew/cask/gcc-arm-embedded
```
3. DFU utility
```zsh
$ brew install dfu-util
```
 
## How to build
Run `make` from top-level Makefile
```zsh
$ make [all]
```

## How to flash hardware

Reset board while holding down the BOOT0 button. Then run one of the following commands:

### Flashing bin file
```zsh
$ dfu-util -a 0 --dfuse-address 0x08000000 -D firmware.bin
```

### Flashing dfu file
```zsh
$ dfu-util -a 0 -D firmware.dfu
```

