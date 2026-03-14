# Hardware Setup Guide

## Wiring Diagram

\\\
HT66F0021 (PA0/PA1) ──→ PCF8574 (SDA/SCL) ──→ LCD Display

Detailed Connections:
HT66F0021      PCF8574        LCD Display
PA0 ──[10k]───SDA
PA1 ──[10k]───SCL
GND ──────────GND
VCC ──────────VCC
               P0 ──────────→ RS (Register Select)
               P2 ──────────→ E (Enable)
               P3 ──────────→ D4 (Data 4)
               P4 ──────────→ D5 (Data 5)
               P5 ──────────→ D6 (Data 6)
               P6 ──────────→ D7 (Data 7)
               P7 ──────────→ BL (Backlight)
\\\

## Pin Assignments

### HT66F0021 MCU Pins
- **PA0 (SDA)**: I2C Data line
- **PA1 (SCL)**: I2C Clock line
- **GND**: Ground
- **VCC**: Power supply (5V or 3.3V)

### PCF8574 I2C Expander Pins
- **P0**: LCD RS (Register Select)
- **P1**: LCD RW (Read/Write) - not used, tied to GND
- **P2**: LCD E (Enable)
- **P3-P6**: LCD D4-D7 (Data lines 4-7)
- **P7**: LCD Backlight LED
- **SDA**: To HT66F0021 PA0 (with pull-up)
- **SCL**: To HT66F0021 PA1 (with pull-up)
- **VCC**: Power supply
- **GND**: Ground

### LCD Display Pins
- **VSS**: Ground
- **VDD**: +5V
- **V0**: Contrast (to GND or variable resistor)
- **RS**: Register Select (from PCF8574 P0)
- **RW**: Read/Write (tied to GND - write only)
- **E**: Enable (from PCF8574 P2)
- **D0-D3**: Not used (4-bit mode)
- **D4-D7**: Data lines (from PCF8574 P3-P6)
- **A**: Backlight anode (connected through resistor)
- **K**: Backlight cathode (to GND or PCF8574 P7)

## Pull-up Resistors

**REQUIRED for I2C to work properly:**

- **10kΩ resistor on SDA (PA0)**
  - One end: PA0
  - Other end: VCC (5V or 3.3V)

- **10kΩ resistor on SCL (PA1)**
  - One end: PA1
  - Other end: VCC (5V or 3.3V)

**Why needed?** I2C is open-drain. Pull-ups pull the lines high when idle.

## PCF8574 I2C Addresses

Selectable via address pins A0, A1, A2:

\\\
All pins low:    0x20
A0 high:         0x21
A1 high:         0x22
A0+A1 high:      0x23
A2 high:         0x24
A0+A2 high:      0x25
A1+A2 high:      0x26
All high:        0x27 (default on most modules)
\\\

Most PCF8574 modules come with **0x27** as default.

## Testing Procedure

### Step 1: Power Verification
\\\
Measure with multimeter:
□ HT66F0021 VCC = ~5V (or 3.3V)
□ PCF8574 VCC = ~5V (or 3.3V)
□ LCD VCC = ~5V
□ All GND = 0V (reference)
□ PA0 idle = ~5V (pulled up)
□ PA1 idle = ~5V (pulled up)
\\\

### Step 2: Visual Inspection
\\\
□ All connections are tight
□ No burned components
□ 10kΩ resistors present and correct value
□ No short circuits or solder bridges
□ All wires go to correct pins
\\\

### Step 3: I2C Communication Test
\\\c
LCD_INIT(0x27);
LCD_SET_CURSOR(0, 0);
LCD_PRINT_CHAR('A');

// If 'A' appears → System works!
// If nothing → Try different address (0x20-0x27)
\\\

### Step 4: Find Correct I2C Address
\\\c
unsigned char addr;
for (addr = 0x20; addr <= 0x27; addr++) {
    LCD_INIT(addr);
    LCD_PRINT_STRING("Addr: ");
    LCD_WRITE_NUMBER(addr);
    delay(2000);
    LCD_CLEAR();
}
\\\

## Troubleshooting

### LCD is blank
1. Check I2C address (try all 0x20-0x27)
2. Verify power supply voltage
3. Check pull-up resistors are present and 10kΩ
4. Verify wiring connections

### Garbled characters
1. Add delays after LCD_INIT()
2. Check I2C clock speed (may need to reduce)
3. Verify all connections are secure

### Backlight doesn't work
1. Call LCD_BACKLIGHT_ON() in code
2. Check backlight LED polarity
3. Verify PCF8574 P7 connection
4. Check LED current limiting resistor

### I2C not responding
1. Verify 10kΩ pull-ups on SDA and SCL
2. Check SDA/SCL wires aren't swapped
3. Measure PA0 and PA1 with multimeter (should be ~5V idle)
4. Try different PCF8574 module

## Bill of Materials (BOM)

\\\
Item                   Qty   Notes
Holtek HT66F0021       1     MCU
PCF8574 Module         1     I2C 8-bit I/O expander
16×2 LCD Display       1     HD44780 compatible
Resistor 10kΩ          2     Pull-ups for SDA/SCL
Power Supply           1     5V (can use 3.3V with adapter)
Breadboard            1     For prototyping
Jumper Wires          20     Various lengths
\\\

## Common Mistakes

❌ **Don't:**
- Connect pull-ups to GND (they go to VCC!)
- Swap SDA and SCL
- Forget pull-up resistors
- Use wrong I2C address without testing all 8
- Connect backlight without current limiting resistor

✅ **Do:**
- Verify power supply before plugging in
- Test each connection with multimeter
- Use proper I2C protocol
- Add delays between operations
- Check all connections are tight
