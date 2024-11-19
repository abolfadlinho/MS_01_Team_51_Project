#ifndef LCD_H
#define LCD_H

#include "pico/stdlib.h"

// LCD Commands
#define LCD_CLEAR 0x01
#define LCD_HOME 0x02
#define LCD_ENTRY_MODE 0x06
#define LCD_DISPLAY_ON 0x0C
#define LCD_DISPLAY_OFF 0x08
#define LCD_CURSOR_ON 0x0E
#define LCD_CURSOR_OFF 0x0C
#define LCD_FUNCTION_SET_8BIT 0x38

// Function Prototypes
void lcd_init(void);
void lcd_command(uint8_t command);
void lcd_data(uint8_t data);
void lcd_print(const char *str);
void lcd_set_cursor(uint8_t row, uint8_t col);

#endif // LCD_H
