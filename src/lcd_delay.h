// --------------------------------------------------------------------------
// HD44780 library for PIC microcontrollers
//
// Declaration of delay-functions
//
// Author: Bernhard Bablok
//
// https://github.com/bablokb/pic-hd44780_lcd
//
// --------------------------------------------------------------------------

#ifndef __DELAY_H
#define __DELAY_H

#include <stdint.h>

void delay_10(void);
void delay_150(void);
void delay_1000(void);
void delay_ms(uint8_t count);

#endif
