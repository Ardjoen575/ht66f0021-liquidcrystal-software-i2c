/**
 * example_scrolling.c
 * Scrolling Text Example
 */

#include "HT66F0021.h"
#include "Arduino.h"
#include "ht66f0021_liquidcrystal_software_i2c.h"

int main(void) {
    unsigned char i;
    
    _clrwdt();
    
    LCD_INIT(0x27);
    delay(500);
    
    LCD_SET_CURSOR(0, 0);
    LCD_PRINT_STRING("Scrolling Left");
    
    delay(1000);
    
    for (i = 0; i < 5; i++) {
        LCD_SCROLL_LEFT();
        delay(300);
        _clrwdt();
    }
    
    delay(1000);
    
    for (i = 0; i < 10; i++) {
        LCD_SCROLL_RIGHT();
        delay(300);
        _clrwdt();
    }
    
    LCD_SET_CURSOR(1, 0);
    LCD_PRINT_STRING("HT66F0021");
    
    delay(2000);
    
    LCD_CLEAR();
    
    LCD_SET_CURSOR(0, 0);
    LCD_PRINT_STRING("Scrolling Done!");
    
    while (1) {
        _clrwdt();
        delay(1000);
    }
    
    return 0;
}
