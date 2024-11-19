#include "pico/stdlib.h"
#include "lcd.h"

int main() {
    stdio_init_all();
    lcd_init();

    lcd_set_cursor(0, 0);
    lcd_print("Test LCD");

    while (true) {
        // Do nothing
    }
}
