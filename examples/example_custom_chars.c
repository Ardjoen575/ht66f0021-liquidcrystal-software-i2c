/**
 * example_custom_chars.c
 * Custom Character Creation
 */

#include "HT66F0021.h"
#include "Arduino.h"
#include "ht66f0021_liquidcrystal_software_i2c.h"

int main(void) {
    const unsigned char heart[] = {
        0b00000,
        0b01010,
        0b11111,
        0b11111,
        0b11111,
        0b01110,
        0b00100,
        0b00000
    };
    
    _clrwdt();
    
    LCD_INIT(0x27);
    delay(500);
    
    LCD_CREATE_CHAR(0, heart);
    
    LCD_CLEAR();
    LCD_SET_CURSOR(0, 0);
    LCD_PRINT_STRING("Custom Chars:");
    
    LCD_SET_CURSOR(1, 0);
    LCD_PRINT_CHAR(0);
    LCD_PRINT_STRING(" Love LCD ");
    LCD_PRINT_CHAR(0);
    
    delay(3000);
    
    LCD_CLEAR();
    
    for (unsigned char i = 0; i < 5; i++) {
        LCD_SET_CURSOR(0, 5 + i);
        LCD_PRINT_CHAR(0);
        delay(300);
        LCD_CLEAR();
        _clrwdt();
    }
    
    LCD_CLEAR();
    LCD_SET_CURSOR(0, 0);
    LCD_PRINT_STRING("Demo Complete!");
    
    while (1) {
        _clrwdt();
        delay(1000);
    }
    
    return 0;
}
