/**
 * example_backlight_control.c
 * Backlight Control Effects
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
    LCD_PRINT_STRING("Backlight Demo");
    
    LCD_SET_CURSOR(1, 0);
    LCD_PRINT_STRING("HT66F0021");
    
    delay(2000);
    
    // Test 1: Backlight toggle
    LCD_CLEAR();
    LCD_SET_CURSOR(0, 0);
    LCD_PRINT_STRING("Backlight On");
    
    for (i = 0; i < 3; i++) {
        LCD_BACKLIGHT_ON();
        delay(1000);
        
        LCD_BACKLIGHT_OFF();
        delay(1000);
        
        _clrwdt();
    }
    
    LCD_BACKLIGHT_ON();
    
    // Test 2: Power saving mode
    LCD_CLEAR();
    LCD_SET_CURSOR(0, 0);
    LCD_PRINT_STRING("Power Saving Mode");
    
    delay(2000);
    
    LCD_DISPLAY_OFF();
    LCD_BACKLIGHT_OFF();
    delay(2000);
    
    LCD_DISPLAY_ON();
    LCD_BACKLIGHT_ON();
    delay(1000);
    
    _clrwdt();
    
    LCD_CLEAR();
    LCD_SET_CURSOR(0, 0);
    LCD_PRINT_STRING("Demo Complete!");
    
    while (1) {
        _clrwdt();
        delay(1000);
    }
    
    return 0;
}
