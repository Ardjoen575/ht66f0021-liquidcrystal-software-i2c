# HT66F0021 LiquidCrystal Software I2C

Complete, production-ready Software I2C LCD driver library for Holtek HT66F0021 microcontroller.

## Features

✅ **Software I2C (Bit-Banged)**
- No hardware I2C peripheral needed
- PA0 (SDA) and PA1 (SCL) GPIO control
- ~40 kHz I2C clock speed

✅ **PCF8574 I2C Expander Support**
- 8-bit I/O expander (address 0x20-0x27)
- Full read/write capability

✅ **HD44780 LCD Compatibility**
- 16×2 LCD support
- 4-bit mode operation
- Full command set

✅ **Rich API (18 Functions)**
- Display control (on/off, clear, home)
- Cursor control (on/off, blink, position)
- Text output (string, character, number)
- Scrolling (left/right)
- Backlight control
- Custom characters (8 custom chars)

## Hardware Requirements

- Holtek HT66F0021 MCU
- PCF8574 I2C Expander
- 16×2 LCD Display
- 2 × 10kΩ Pull-up resistors (SDA, SCL)

## Quick Start

\\\c
#include "ht66f0021_liquidcrystal_software_i2c.h"

int main(void) {
    LCD_INIT(0x27);
    LCD_SET_CURSOR(0, 0);
    LCD_PRINT_STRING("Hello World!");
    
    while(1) {
        _clrwdt();
        delay(1000);
    }
}
\\\

## Wiring

\\\
HT66F0021      PCF8574        LCD
PA0 ──[10k]───SDA
PA1 ──[10k]───SCL
GND ──────────GND
VCC ──────────VCC
               P0-P7 ─→ LCD pins
\\\

## API Functions

### Initialization
- \LCD_INIT(addr)\ - Initialize LCD

### Display Control
- \LCD_CLEAR()\ - Clear display
- \LCD_HOME()\ - Cursor to home
- \LCD_DISPLAY_ON()\ / \LCD_DISPLAY_OFF()\

### Cursor Control
- \LCD_SET_CURSOR(row, col)\ - Set position
- \LCD_CURSOR_ON()\ / \LCD_CURSOR_OFF()\
- \LCD_BLINK_ON()\ / \LCD_BLINK_OFF()\

### Text Output
- \LCD_PRINT_STRING(str)\ - Print string
- \LCD_PRINT_CHAR(ch)\ - Print character
- \LCD_WRITE_NUMBER(num)\ - Print number

### Effects
- \LCD_SCROLL_LEFT()\ / \LCD_SCROLL_RIGHT()\
- \LCD_BACKLIGHT_ON()\ / \LCD_BACKLIGHT_OFF()\
- \LCD_CREATE_CHAR(loc, pattern)\ - Custom character

## Documentation

- [Getting Started](GETTING_STARTED.md) - Quick start guide
- [API Reference](API_REFERENCE.md) - Complete API
- [Hardware Setup](HARDWARE_SETUP.md) - Wiring guide
- [Troubleshooting](TROUBLESHOOTING.md) - Problem solving
- [Examples](examples/) - Working code examples

## Status

✅ Production Ready
✅ Fully Documented
✅ Tested on Hardware
✅ 18 API Functions
✅ 7 Example Programs

## License

MIT License - Open Source

## Author

Ardjoen575
