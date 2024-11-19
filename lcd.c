#include "lcd.h"

// GPIO Pins for LCD
#define RS_PIN 8
#define E_PIN 9
#define DATA_PINS_START 0 // GPIO 0 to GPIO 7

// Helper function to pulse the enable pin
void lcd_enable_pulse() {
    gpio_put(E_PIN, 1);
    sleep_us(1);
    gpio_put(E_PIN, 0);
    sleep_us(100);
}

// Send a command to the LCD
void lcd_command(uint8_t command) {
    gpio_put(RS_PIN, 0); // Instruction mode
    for (int i = 0; i < 8; i++) {
        gpio_put(DATA_PINS_START + i, (command >> i) & 0x01);
    }
    lcd_enable_pulse();
    sleep_ms(2);
}

// Send data to the LCD
void lcd_data(uint8_t data) {
    gpio_put(RS_PIN, 1); // Data mode
    for (int i = 0; i < 8; i++) {
        gpio_put(DATA_PINS_START + i, (data >> i) & 0x01);
    }
    lcd_enable_pulse();
    sleep_ms(2);
}

// Initialize the LCD
void lcd_init() {
    // Set all pins as output
    gpio_init(RS_PIN);
    gpio_set_dir(RS_PIN, GPIO_OUT);
    gpio_init(E_PIN);
    gpio_set_dir(E_PIN, GPIO_OUT);
    for (int i = 0; i < 8; i++) {
        gpio_init(DATA_PINS_START + i);
        gpio_set_dir(DATA_PINS_START + i, GPIO_OUT);
    }

    // Initialization sequence
    sleep_ms(15); // Wait for LCD to power up
    lcd_command(LCD_FUNCTION_SET_8BIT); // 8-bit mode, 2 lines, 5x8 dots
    lcd_command(LCD_DISPLAY_ON);        // Display on, cursor off, blink off
    lcd_command(LCD_CLEAR);             // Clear display
    lcd_command(LCD_ENTRY_MODE);        // Increment cursor, no display shift
}

// Print a string to the LCD
void lcd_print(const char *str) {
    while (*str) {
        lcd_data(*str++);
    }
}

// Set cursor position
void lcd_set_cursor(uint8_t row, uint8_t col) {
    uint8_t address = (row == 0) ? 0x80 : 0xC0; // Line 1: 0x80, Line 2: 0xC0
    address += col;
    lcd_command(address);
}
