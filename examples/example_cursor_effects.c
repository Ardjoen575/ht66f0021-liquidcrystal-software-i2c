/**
 * example_cursor_effects.c
 * Cursor Control Effects
 */

#include "HT66F0021.h"
#include "Arduino.h"
#include "ht66f0021_liquidcrystal_software_i2c.h"

int main(void) {
    unsigned char i;
    
    _clrwdt();
    
    LCD_INIT(0x27);
    delay(500);
    
    // Test 1: Steady cursor
    LCD_CLEAR();
    LCD_SET_CURSOR(0, 0);
    LCD_PRINT_STRING("Steady Cursor");
    LCD_CURSOR_ON();
    LCD_BLINK_OFF();
    delay(3000);
    _clrwdt();
    
    // Test 2: Blinking cursor
    LCD_CLEAR();
    LCD_SET_CURSOR(0, 0);
    LCD_PRINT_STRING("Blinking");
    LCD_CURSOR_ON();
    LCD_BLINK_ON();
    delay(3000);
    _clrwdt();
    
    // Test 3: Hidden cursor
    LCD_CLEAR();
    LCD_SET_CURSOR(0, 0);
    LCD_PRINT_STRING("Cursor Hidden");
    LCD_CURSOR_OFF();
    delay(3000);
    _clrwdt();
    
    // Test 4: Cursor movement
    LCD_CLEAR();
    LCD_CURSOR_ON();
    LCD_BLINK_OFF();
    
    for (i = 0; i < 16; i++) {
        LCD_SET_CURSOR(0, i);
        LCD_PRINT_CHAR('*');
        delay(200);
        _clrwdt();
    }
    
    delay(1000);
    
    // Test 5: Display on/off effect
    LCD_CLEAR();
    LCD_SET_CURSOR(0, 0);
    LCD_PRINT_STRING("Blinking Display");
    
    for (i = 0; i < 3; i++) {
        LCD_DISPLAY_OFF();
        delay(500);
        LCD_DISPLAY_ON();
        delay(500);
        _clrwdt();
    }
    
    delay(1000);
    
    LCD_CLEAR();
    LCD_SET_CURSOR(0, 0);
    LCD_PRINT_STRING("Demo Complete!");
    
    while (1) {
        _clrwdt();
        delay(1000);
    }
    
    return 0;
}
