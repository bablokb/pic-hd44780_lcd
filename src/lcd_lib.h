// --------------------------------------------------------------------------
// HD44780 library for PIC microcontrollers
//
// Author: Bernhard Bablok
// https://github.com/bablokb/pic-hd44780_lcd
//
// --------------------------------------------------------------------------

#include <pic14regs.h>
#include <stdint.h>

#ifndef __LCD_H
#define __LCD_H

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

#ifdef _RA0
  #define GP     RA
  #define TRISIO TRISA
#endif

#define GP_ENABLE  _CONCAT(GP,PIN_LCD_ENABLE)   // Enable pin for LCD
#define GP_CLK     _CONCAT(GP,PIN_LCD_CLK)      // Serial clock pin
#define GP_DATA    _CONCAT(GP,PIN_LCD_DATA)     // Serial data pin

// Define Pins direction registrers
#define GP_ENABLE_TRISIO _CONCAT(TRISIO,PIN_LCD_ENABLE)
#define GP_CLK_TRISIO    _CONCAT(TRISIO,PIN_LCD_CLK)
#define GP_DATA_TRISIO   _CONCAT(TRISIO,PIN_LCD_DATA)

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
