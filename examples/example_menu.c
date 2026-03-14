/**
 * example_menu.c
 * Simple Menu Navigation
 */

#include "HT66F0021.h"
#include "Arduino.h"
#include "ht66f0021_liquidcrystal_software_i2c.h"

#define MENU_ITEMS 3

const char *menu_items[] = {
    "Option 1",
    "Option 2",
    "Option 3"
};

void display_menu(unsigned char selected) {
    LCD_CLEAR();
    
    LCD_SET_CURSOR(0, 0);
    if (selected == 0) {
        LCD_PRINT_STRING("> ");
    } else {
        LCD_PRINT_STRING("  ");
    }
    LCD_PRINT_STRING(menu_items[0]);
    
    LCD_SET_CURSOR(1, 0);
    if (selected == 1) {
        LCD_PRINT_STRING("> ");
    } else {
        LCD_PRINT_STRING("  ");
    }
    LCD_PRINT_STRING(menu_items[1]);
}

int main(void) {
    unsigned char selected = 0;
    unsigned char counter = 0;
    
    _clrwdt();
    
    LCD_INIT(0x27);
    delay(500);
    
    display_menu(selected);
    
    while (1) {
        _clrwdt();
        
        counter++;
        
        if (counter > 100) {
            counter = 0;
            selected++;
            if (selected >= MENU_ITEMS) {
                selected = 0;
            }
            display_menu(selected);
        }
        
        delay(10);
    }
    
    return 0;
}
