# Troubleshooting Guide

## Issue 1: LCD Display is Blank

### Problem
- Power is on (LED may be on or off)
- No text appears on display
- Display initialized without errors

### Solutions

**Solution 1: Wrong I2C Address**

Try all possible addresses:
\\\c
for (unsigned char addr = 0x20; addr <= 0x27; addr++) {
    LCD_INIT(addr);
    LCD_SET_CURSOR(0, 0);
    LCD_PRINT_STRING("Test");
    delay(2000);
    LCD_CLEAR();
}
\\\

**Solution 2: Missing Pull-up Resistors**

Check:
- 10kΩ resistor on PA0 to VCC
- 10kΩ resistor on PA1 to VCC

Verify with multimeter:
- PA0 idle voltage: ~5V
- PA1 idle voltage: ~5V

**Solution 3: Power Supply Issue**

Measure voltages:
- HT66F0021 VCC: ~5V (or 3.3V)
- PCF8574 VCC: ~5V (or 3.3V)
- LCD VCC: ~5V
- All GND: 0V

**Solution 4: Increase Initialization Time**

\\\c
LCD_INIT(0x27);
delay(1000);  // Increase from 500ms
LCD_SET_CURSOR(0, 0);
LCD_PRINT_STRING("Hello");
\\\

**Solution 5: Check Wiring**

Verify all connections visually:
- SDA wire connected
- SCL wire connected
- Power connections correct
- No loose wires

---

## Issue 2: Garbled Characters

### Problem
- Text appears but characters are wrong
- Looks like random dots/lines
- Sometimes partially correct

### Solutions

**Solution 1: Add Delays**

\\\c
LCD_INIT(0x27);
delay(500);  // Increase

LCD_SET_CURSOR(0, 0);
delay(100);  // Add delay

LCD_PRINT_STRING("Hello");
delay(100);  // Add delay
\\\

**Solution 2: Check Wiring**

1. Verify each wire is secure
2. Look for frayed wires
3. Check for solder bridges
4. Reseat all connections

**Solution 3: Try Different I2C Address**

\\\c
LCD_INIT(0x26);  // Instead of 0x27
\\\

---

## Issue 3: Backlight Won't Turn On

### Problem
- Display works but backlight is dark
- Text is hard to see

### Solutions

**Solution 1: Enable Backlight in Code**

\\\c
LCD_INIT(0x27);
LCD_BACKLIGHT_ON();  // Add this!
\\\

**Solution 2: Check PCF8574 P7 Connection**

- P7 should be connected to LCD backlight
- Verify connection is secure
- Check LED polarity

**Solution 3: Backlight LED Burned Out**

- Measure voltage on P7: Should be ~5V when backlight is ON
- If voltage present but no light → LED burned out
- Replace LCD module or backlight LED

---

## Issue 4: I2C Communication Fails

### Problem
- LCD doesn't respond at all
- No initialization possible
- Hardware appears connected correctly

### Solutions

**Solution 1: Verify Pull-up Resistors**

Check:
1. 10kΩ resistors installed on PA0 and PA1
2. Resistors connected to VCC (NOT GND!)
3. Resistor value correct (measure with multimeter)

Test:
\\\
Idle voltage:
- PA0: Should be ~5V
- PA1: Should be ~5V

If 0V: Check for short circuits
\\\

**Solution 2: SDA/SCL Wires Swapped**

Correct:
- PA0 → SDA
- PA1 → SCL

Wrong (won't work):
- PA0 → SCL (swapped!)
- PA1 → SDA (swapped!)

**Solution 3: Try All I2C Addresses**

\\\c
for (unsigned char addr = 0x20; addr <= 0x27; addr++) {
    LCD_INIT(addr);
    // Test if working
}
\\\

---

## Issue 5: Cursor Not Visible

### Problem
- Text displays correctly
- Cursor should be visible but isn't

### Solutions

**Solution 1: Enable Cursor**

\\\c
LCD_CURSOR_ON();       // Make visible
LCD_BLINK_ON();        // Optional: make it blink
\\\

**Solution 2: Cursor at Edge**

\\\c
LCD_SET_CURSOR(0, 5);  // Middle of screen
LCD_CURSOR_ON();
\\\

---

## Issue 6: Custom Characters Not Working

### Problem
- Custom character creation succeeds
- But character doesn't display correctly

### Solutions

**Solution 1: Verify Pattern Data**

\\\c
// Must have exactly 8 rows
const unsigned char heart[] = {
    0b00000,  // Row 1
    0b01010,  // Row 2
    0b11111,  // Row 3
    0b11111,  // Row 4
    0b11111,  // Row 5
    0b01110,  // Row 6
    0b00100,  // Row 7
    0b00000   // Row 8
};
\\\

**Solution 2: Use Valid Location**

Valid locations: 0-7 only

\\\c
LCD_CREATE_CHAR(0, pattern1);  // OK
LCD_CREATE_CHAR(7, pattern8);  // OK
LCD_CREATE_CHAR(8, pattern);   // WRONG! Only 8 custom chars
\\\

---

## Diagnostic Procedure

If LCD still doesn't work:

### Step 1: Power Verification
\\\
Measure with multimeter:
□ HT66F0021 VCC = ~5V
□ PCF8574 VCC = ~5V
□ LCD VCC = ~5V
□ All GND = 0V
□ PA0 idle = ~5V
□ PA1 idle = ~5V
\\\

### Step 2: Hardware Check
\\\
Visual inspection:
□ All connections are tight
□ No burned components
□ 10kΩ resistors present
□ No short circuits
□ All wires to correct pins
\\\

### Step 3: Software Test
\\\c
LCD_INIT(0x27);
LCD_SET_CURSOR(0, 0);
LCD_PRINT_CHAR('A');

// If 'A' appears → System works!
// If nothing → Try different address
\\\

### Step 4: I2C Address Search
\\\c
for (unsigned char addr = 0x20; addr <= 0x27; addr++) {
    LCD_INIT(addr);
    // If this works, use that address
}
\\\

---

## When All Else Fails

1. **Reset everything**
   - Power off MCU
   - Reseat all connections
   - Power back on

2. **Try different modules**
   - Test with different PCF8574
   - Test with different LCD
   - Test with different MCU

3. **Contact support**
   - Provide full schematic
   - Include test code
   - Show error messages

---

## Quick Reference

| Issue | Check |
|-------|-------|
| Blank display | I2C address, power, pull-ups |
| Garbled text | Delays, wiring, address |
| No backlight | Backlight ON code, P7 connection |
| I2C fails | Pull-ups, SDA/SCL, address |
| Cursor hidden | CURSOR_ON() call |
| Custom char broken | 8 bytes, location 0-7 |
