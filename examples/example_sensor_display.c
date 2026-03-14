/**
 * example_sensor_display.c
 * Sensor Data Display Example
 */

#include "HT66F0021.h"
#include "Arduino.h"
#include "ht66f0021_liquidcrystal_software_i2c.h"

unsigned int read_temperature(void) {
    static unsigned int temp = 20;
    temp++;
    if (temp > 50) temp = 20;
    return temp;
}

int main(void) {
    unsigned int temperature;
    
    _clrwdt();
    
    LCD_INIT(0x27);
    delay(500);
    
    LCD_CLEAR();
    LCD_SET_CURSOR(0, 0);
    LCD_PRINT_STRING("Temp:   C");
    
    while (1) {
        _clrwdt();
        
        temperature = read_temperature();
        
        LCD_SET_CURSOR(0, 5);
        LCD_WRITE_NUMBER(temperature);
        if (temperature < 100) LCD_PRINT_STRING(" ");
        if (temperature < 10)  LCD_PRINT_STRING(" ");
        
        delay(500);
    }
    
    return 0;
}
