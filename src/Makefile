# --------------------------------------------------------------------------
# HD44780 library for PIC microcontrollers
#
# Author: Bernhard Bablok
#
# https://github.com/bablokb/pic-toolchain
# 
# --------------------------------------------------------------------------

PIN_LCD_ENABLE=0
PIN_LCD_CLK=1
PIN_LCD_DATA=2


PROJECT=hd44780_lcd
EXTRA_C=lcd_lib.c
EXTRA_ASM=lcd_delay.asm
MODEL=12f675
ARCH=pic14
SDCC_ARGS=-DLCD_PRINT_X -DPIN_LCD_ENABLE=$(PIN_LCD_ENABLE) \
                        -DPIN_LCD_CLK=$(PIN_LCD_CLK) \
                        -DPIN_LCD_DATA=$(PIN_LCD_DATA)
include rules.inc

# --------------------------------------------------------------------------
