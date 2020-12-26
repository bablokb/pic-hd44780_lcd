// --------------------------------------------------------------------------
// HD44780 library for PIC microcontrollers
//
// Write to LCD-display with a HD44780-controller (e.g. 2x16). The display
// is used in 4-bit mode. Between the PIC and the display the project
// uses a shift-register (74HC595).
//
// Author: Bernhard Bablok
// https://github.com/bablokb/pic-hd44780_lcd
//
// --------------------------------------------------------------------------

#include "picconfig.h"
#include <stdint.h> 

#include "lcd_lib.h"
#include "lcd_delay.h"

CONFIG_WORDS

////////////////////////////////////////////////////////////////////////
// Intialize registers

static void init(void) {
  // configure registers

  __asm__ ("CLRWDT");            // clear WDT even if WDT is disabled
  ANSEL  = 0;                    // no analog input
  TRISIO = 0;                    // no input pins
  INTCON = 0;                    // clear interrupt flag bits
  CLOCK_4MHZ;
}

// --- main program   --------------------------------------------------------

void main(void) {
#ifdef LCD_PRINT_X
  uint8_t  counter=0;
  uint16_t addr=0;
#endif

  INIT_SPECIAL;
  init();
  lcd_init();
  lcd_pos(1,4);
  lcd_print("Hello");
  lcd_pos(2,4);
  lcd_print("world!");
#ifdef LCD_PRINT_X
  while (1) {
    lcd_pos(2,15);
    lcd_print_x(counter++);

    lcd_pos(1,13);
    addr = ~counter;
    addr <<= 8;
    lcd_print_x16(addr);
    delay_ms(250);
  }
#else
  while (1) {
    __asm__("SLEEP");
  }
#endif
}
