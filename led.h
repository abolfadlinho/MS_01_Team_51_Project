#ifndef LED_H
#define LED_H
#include <stdio.h>
#include "pico/stdlib.h"

// Function prototypes
void init_led(uint red_pin, uint green_pin, uint blue_pin);
void red_on(uint red_pin, uint green_pin, uint blue_pin);
void green_on(uint red_pin, uint green_pin, uint blue_pin);
void blue_on(uint red_pin, uint green_pin, uint blue_pin);
void all_off(uint red_pin, uint green_pin, uint blue_pin);
void all_on(uint red_pin, uint green_pin, uint blue_pin);

#endif
