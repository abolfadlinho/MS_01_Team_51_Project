#include <stdio.h>
#include "led.h"

void init_led(uint red_pin, uint green_pin, uint blue_pin) {
    // Initialize the GPIO pins for the Red, Green, and Blue LEDs
    gpio_init(red_pin);
    gpio_set_dir(red_pin, GPIO_OUT);
    gpio_init(green_pin);
    gpio_set_dir(green_pin, GPIO_OUT);
    gpio_init(blue_pin);
    gpio_set_dir(blue_pin, GPIO_OUT);
}

void red_on(uint red_pin, uint green_pin, uint blue_pin) {
    // Turn on the Red LED and turn off the others
    gpio_put(red_pin, true);
    gpio_put(green_pin, false);
    gpio_put(blue_pin, true);  // Negative logic for blue LED
}

void green_on(uint red_pin, uint green_pin, uint blue_pin) {
    // Turn on the Green LED and turn off the others
    gpio_put(red_pin, false);
    gpio_put(green_pin, true);
    gpio_put(blue_pin, true);  // Negative logic for blue LED
}

void blue_on(uint red_pin, uint green_pin, uint blue_pin) {
    // Turn on the Blue LED (negative logic = LOW) and turn off the others
    gpio_put(red_pin, false);
    gpio_put(green_pin, false);
    gpio_put(blue_pin, false);  // Negative logic for blue LED
}

void all_off(uint red_pin, uint green_pin, uint blue_pin) {
    // Turn off all LEDs
    gpio_put(red_pin, false);
    gpio_put(green_pin, false);
    gpio_put(blue_pin, true);  // Negative logic for blue LED (HIGH = off)
}

void all_on(uint red_pin, uint green_pin, uint blue_pin) {
    // Turn on all LEDs (negative logic for blue LED)
    gpio_put(red_pin, true);
    gpio_put(green_pin, true);
    gpio_put(blue_pin, false);  // Negative logic for blue LED (LOW = on)
}
