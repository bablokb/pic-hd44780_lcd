// --------------------------------------------------------------------------
// HD44780 library for PIC microcontrollers
//
// Author: Bernhard Bablok
// https://github.com/bablokb/pic-hd44780_lcd
//
// --------------------------------------------------------------------------

#ifndef __LCD_H
#define __LCD_H

#include "picconfig.h"
#include <stdint.h>

// Define Pins
#ifndef PIN_LCD_ENABLE
  #define PIN_LCD_ENABLE 0
#endif
#ifndef PIN_LCD_CLK
  #define PIN_LCD_CLK 1
#endif
#ifndef PIN_LCD_DATA
  #define PIN_LCD_DATA 2
#endif

#define GP_ENABLE  _CONCAT(RA,PIN_LCD_ENABLE)   // Enable pin for LCD
#define GP_CLK     _CONCAT(RA,PIN_LCD_CLK)      // Serial clock pin
#define GP_DATA    _CONCAT(RA,PIN_LCD_DATA)     // Serial data pin

// Function Declarations
void lcd_write_cmd(uint8_t cmd);
void lcd_write_data(uint8_t data);
void lcd_init(void);
void lcd_pos(uint8_t row, uint8_t col);
void lcd_print(const unsigned char* string);
#ifdef LCD_PRINT_I
void lcd_print_i(uint8_t value);
#endif
#ifdef LCD_PRINT_X
void lcd_print_x(uint8_t value);
void lcd_print_x16(uint16_t value);
#endif
#define lcd_clear() lcd_write_cmd(0x01)

#endif
