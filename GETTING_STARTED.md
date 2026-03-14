# Getting Started with HT66F0021 LiquidCrystal Software I2C

## 10-Minute Quick Start

### Step 1: Verify Hardware
- ✅ HT66F0021 MCU
- ✅ PCF8574 I2C module
- ✅ 16×2 LCD display
- ✅ 2 × 10kΩ resistors
- ✅ 5V power supply

### Step 2: Wire Hardware

\\\
HT66F0021         PCF8574            LCD Display
PA0 ──[10k]──┬──SDA
             │
PA1 ──[10k]──┼──SCL
GND ─────────┼──GND
VCC ─────────┼──VCC
             │
             ├──P0 ──→ RS
             ├──P2 ──→ E
             ├──P3-P6 ──→ D4-D7
             └──P7 ──→ Backlight
\\\

### Step 3: Include Header

\\\c
#include "HT66F0021.h"
#include "Arduino.h"
#include "ht66f0021_liquidcrystal_software_i2c.h"
\\\

### Step 4: Initialize & Test

\\\c
int main(void) {
    _clrwdt();
    
    LCD_INIT(0x27);
    delay(500);
    
    LCD_SET_CURSOR(0, 0);
    LCD_PRINT_STRING("Hello LCD!");
    
    LCD_SET_CURSOR(1, 0);
    LCD_PRINT_STRING("HT66F0021");
    
    while (1) {
        _clrwdt();
        delay(1000);
    }
    
    return 0;
}
\\\

## Finding Your I2C Address

If the LCD doesn't work, try different addresses:

\\\c
for (unsigned char addr = 0x20; addr <= 0x27; addr++) {
    LCD_INIT(addr);
    LCD_PRINT_STRING("Testing");
    delay(2000);
    LCD_CLEAR();
}
\\\

**Common addresses:**
- 0x27 (most common, default)
- 0x26, 0x25, 0x24 (if address pins are jumpered)

## API Quick Reference

### Display Control
- \LCD_CLEAR()\ - Clear display
- \LCD_HOME()\ - Move to (0,0)
- \LCD_DISPLAY_ON()\ - Display on
- \LCD_DISPLAY_OFF()\ - Display off

### Text Output
- \LCD_PRINT_STRING("Hello")\ - Print string
- \LCD_PRINT_CHAR('A')\ - Print character
- \LCD_WRITE_NUMBER(42)\ - Print number

### Cursor Control
- \LCD_SET_CURSOR(row, col)\ - Set position
- \LCD_CURSOR_ON()\ - Show cursor
- \LCD_CURSOR_OFF()\ - Hide cursor
- \LCD_BLINK_ON()\ - Cursor blinks
- \LCD_BLINK_OFF()\ - Cursor steady

### Effects
- \LCD_SCROLL_LEFT()\ - Shift left
- \LCD_SCROLL_RIGHT()\ - Shift right
- \LCD_BACKLIGHT_ON()\ - Backlight on
- \LCD_BACKLIGHT_OFF()\ - Backlight off

## Troubleshooting

### LCD Blank?
1. Try different I2C address (0x20-0x27)
2. Check power supply (should be 5V or 3.3V)
3. Verify pull-up resistors (10kΩ on SDA and SCL)

### Garbled Text?
1. Add more delays after \LCD_INIT()\
2. Check wiring connections
3. Try a different I2C address

### Backlight Off?
1. Call \LCD_BACKLIGHT_ON()\ after init

## Examples

See \examples/\ folder for working code:
- \example_counter.c\ - Counter display
- \example_scrolling.c\ - Text scrolling
- \example_cursor_effects.c\ - Cursor control
- \example_custom_chars.c\ - Custom characters
- \example_backlight_control.c\ - Backlight effects
- \example_sensor_display.c\ - Real-time data
- \example_menu.c\ - Menu system

## Next Steps

1. Check [API_REFERENCE.md](API_REFERENCE.md) for complete API
2. Review [examples/](examples/) folder for working code
3. Read [HARDWARE_SETUP.md](HARDWARE_SETUP.md) for detailed wiring
4. See [TROUBLESHOOTING.md](TROUBLESHOOTING.md) for common issues
