# API Reference

## Overview

The HT66F0021 LiquidCrystal Software I2C library provides 18 public functions for controlling LCD displays.

## Initialization

### LCD_INIT(i2c_addr)

Initialize the LCD display on specified I2C address.

**Parameters:**
- \i2c_addr\ (unsigned char): PCF8574 I2C address (0x20-0x27, typically 0x27)

**Returns:** None

**Example:**
\\\c
LCD_INIT(0x27);
delay(500);
\\\

---

## Display Control

### LCD_CLEAR()

Clear the entire display and return cursor to home position (0,0).

**Example:**
\\\c
LCD_CLEAR();
delay(2);
\\\

### LCD_HOME()

Move cursor to home position (row 0, column 0).

**Example:**
\\\c
LCD_HOME();
\\\

### LCD_DISPLAY_ON()

Turn on the LCD display (characters become visible).

**Example:**
\\\c
LCD_DISPLAY_ON();
\\\

### LCD_DISPLAY_OFF()

Turn off the LCD display (characters become invisible).

**Example:**
\\\c
LCD_DISPLAY_OFF();
delay(1000);
LCD_DISPLAY_ON();
\\\

---

## Cursor Control

### LCD_SET_CURSOR(row, col)

Set cursor position to specified row and column.

**Parameters:**
- \ow\ (unsigned char): Row number (0 or 1 for 16×2 display)
- \col\ (unsigned char): Column number (0-15 for 16×2 display)

**Example:**
\\\c
LCD_SET_CURSOR(0, 0);
LCD_PRINT_STRING("Hello");

LCD_SET_CURSOR(1, 0);
LCD_PRINT_STRING("World");
\\\

### LCD_CURSOR_ON()

Make cursor visible (appears as underline).

**Example:**
\\\c
LCD_CURSOR_ON();
LCD_BLINK_ON();
\\\

### LCD_CURSOR_OFF()

Hide cursor (cursor becomes invisible).

**Example:**
\\\c
LCD_CURSOR_OFF();
\\\

### LCD_BLINK_ON()

Enable cursor blinking.

**Example:**
\\\c
LCD_CURSOR_ON();
LCD_BLINK_ON();
\\\

### LCD_BLINK_OFF()

Disable cursor blinking (steady cursor).

**Example:**
\\\c
LCD_BLINK_OFF();
\\\

---

## Text Output

### LCD_PRINT_CHAR(character)

Print a single character at current cursor position.

**Parameters:**
- \character\ (unsigned char): ASCII character code

**Example:**
\\\c
LCD_PRINT_CHAR('A');
LCD_PRINT_CHAR('1');
\\\

### LCD_PRINT_STRING(string)

Print a null-terminated string at current cursor position.

**Parameters:**
- \string\ (const char *): Pointer to string

**Example:**
\\\c
LCD_PRINT_STRING("Hello World");
\\\

### LCD_WRITE_NUMBER(number)

Print an unsigned integer in decimal format.

**Parameters:**
- \
umber\ (unsigned int): Number to print (0-65535)

**Example:**
\\\c
LCD_WRITE_NUMBER(42);
LCD_WRITE_NUMBER(1234);
\\\

---

## Display Effects

### LCD_SCROLL_LEFT()

Shift the entire display one position to the left.

**Example:**
\\\c
for (int i = 0; i < 5; i++) {
    LCD_SCROLL_LEFT();
    delay(200);
}
\\\

### LCD_SCROLL_RIGHT()

Shift the entire display one position to the right.

**Example:**
\\\c
for (int i = 0; i < 5; i++) {
    LCD_SCROLL_RIGHT();
    delay(200);
}
\\\

---

## Backlight Control

### LCD_BACKLIGHT_ON()

Turn on the LCD backlight LED.

**Example:**
\\\c
LCD_BACKLIGHT_ON();
\\\

### LCD_BACKLIGHT_OFF()

Turn off the LCD backlight LED.

**Example:**
\\\c
LCD_BACKLIGHT_OFF();
delay(1000);
LCD_BACKLIGHT_ON();
\\\

---

## Custom Characters

### LCD_CREATE_CHAR(location, charmap)

Define a custom character pattern.

**Parameters:**
- \location\ (unsigned char): Character location (0-7)
- \charmap\ (const unsigned char *): Pointer to 8-byte array

**Example:**
\\\c
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

LCD_CREATE_CHAR(0, heart);
LCD_PRINT_CHAR(0);  // Display heart
\\\

---

## Summary Table

| Function | Parameters | Purpose |
|----------|-----------|---------|
| LCD_INIT | addr | Initialize LCD |
| LCD_CLEAR | - | Clear display |
| LCD_HOME | - | Cursor to home |
| LCD_SET_CURSOR | row, col | Set cursor position |
| LCD_PRINT_CHAR | ch | Print character |
| LCD_PRINT_STRING | str | Print string |
| LCD_WRITE_NUMBER | num | Print number |
| LCD_CURSOR_ON | - | Show cursor |
| LCD_CURSOR_OFF | - | Hide cursor |
| LCD_BLINK_ON | - | Enable blink |
| LCD_BLINK_OFF | - | Disable blink |
| LCD_DISPLAY_ON | - | Display on |
| LCD_DISPLAY_OFF | - | Display off |
| LCD_SCROLL_LEFT | - | Scroll left |
| LCD_SCROLL_RIGHT | - | Scroll right |
| LCD_BACKLIGHT_ON | - | Backlight on |
| LCD_BACKLIGHT_OFF | - | Backlight off |
| LCD_CREATE_CHAR | loc, map | Custom character |
