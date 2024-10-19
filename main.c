#include <stdio.h>
#include "pico/stdlib.h"

int main() {
    // Define the GPIO pins for the Red, Green, and Blue LEDs
    const uint red_led_pin = 6;    // Red LED pin (positive logic)
    const uint green_led_pin = 7;  // Green LED pin (positive logic)
    const uint blue_led_pin = 8;   // Blue LED pin (negative logic)

    // Initialize the LED pins
    init_led(red_led_pin, green_led_pin, blue_led_pin);

    // Initialize chosen serial port
    stdio_init_all();

    // Main loop
    while (true) {

        all_off(red_led_pin, green_led_pin, blue_led_pin);
        printf("All LEDs OFF\n");
        sleep_ms(5000);

        red_on(red_led_pin, green_led_pin, blue_led_pin);
        printf("Red LED ON\n");
        sleep_ms(1000);

        green_on(red_led_pin, green_led_pin, blue_led_pin);
        printf("Green LED ON\n");
        sleep_ms(1000);

        blue_on(red_led_pin, green_led_pin, blue_led_pin);
        printf("Blue LED ON\n");
        sleep_ms(1000);

        all_off(red_led_pin, green_led_pin, blue_led_pin);
        printf("All LEDs OFF\n");
        sleep_ms(1000);

        all_on(red_led_pin, green_led_pin, blue_led_pin);
        printf("All LEDs ON\n");
        sleep_ms(2000);
    }
}
