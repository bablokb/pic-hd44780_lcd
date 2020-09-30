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

#define NO_BIT_DEFINES
#include <pic14regs.h>
#include <stdint.h> 

#include "lcd_lib.h"
#include "lcd_delay.h"

// build with:
// make build

// MCLR on, Power on Timer, no WDT, int-oscillator, 
// no brown out

#ifdef __SDCC_PIC12F675
#elif __SDCC_PIC12F683
  #define CMCON      CMCON0
  #define _BODEN_OFF _BOD_OFF
#elif __SDCC_PIC12F1840
  #define CMCON    CM1CON0
  #define ANSEL    ANSELA
  #define TRISIO   TRISA
  #define GPIO     PORTA
 #endif

#ifdef __SDCC_PIC12F675
__code uint16_t __at (_CONFIG) __configword = 
  _MCLRE_ON & _PWRTE_ON & _WDT_OFF & _INTRC_OSC_NOCLKOUT & _BODEN_OFF;
#elif __SDCC_PIC12F1840
__code uint16_t __at (_CONFIG1) __configword1 =
  _MCLRE_ON & _PWRTE_ON & _WDTE_OFF & _CLKOUTEN_OFF & _BOREN_OFF & _FOSC_INTOSC;
__code uint16_t __at (_CONFIG2) __configword2 = _LVP_OFF & _DEBUG_OFF;
#endif

////////////////////////////////////////////////////////////////////////
// Intialize registers

static void init(void) {
  // configure registers

  __asm__ ("CLRWDT");            // clear WDT even if WDT is disabled
  ANSEL  = 0;                    // no analog input
  TRISIO = 0;                    // no input pins
  CMCON  = 0x07;                 // disable comparator for GP0-GP2

#ifdef __SDCC_PIC12F683
  OSCCONbits.IRCF = 0b110;
#elif __SDCC_PIC12F1840
  OSCCONbits.IRCF = 0b1101;
#endif

  INTCON                 = 0;    // clear interrupt flag bits
}

// --- main program   --------------------------------------------------------

void main(void) {
#ifdef LCD_PRINT_X
  uint8_t  counter=0;
  uint16_t addr=0;
#endif

#ifdef __SDCC_PIC12F675
  // Load calibration
  __asm
    bsf  STATUS, RP0
    call 0x3ff    ; read value
    movwf OSCCAL  ; set  value
    bcf  STATUS, RP0
  __endasm;
#endif

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
