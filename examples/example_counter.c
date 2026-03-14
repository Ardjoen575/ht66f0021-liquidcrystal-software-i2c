/**
 * example_counter.c
 * Counter Display Example
 * 
 * Displays a counter (0-9999) that increments every 500ms
 */

#include "HT66F0021.h"
#include "Arduino.h"
#include "ht66f0021_liquidcrystal_software_i2c.h"

int main(void) {
    unsigned int count = 0;
    
    _clrwdt();
    
    LCD_INIT(0x27);
    delay(500);
    
    LCD_SET_CURSOR(0, 0);
    LCD_PRINT_STRING("Counter: ");
    
    while (1) {
        _clrwdt();
        
        LCD_SET_CURSOR(0, 9);
        LCD_WRITE_NUMBER(count);
        
        if (count < 1000) LCD_PRINT_STRING(" ");
        if (count < 100)  LCD_PRINT_STRING(" ");
        if (count < 10)   LCD_PRINT_STRING(" ");
        
        count++;
        if (count > 9999) count = 0;
        
        delay(500);
    }
    
    return 0;
}
