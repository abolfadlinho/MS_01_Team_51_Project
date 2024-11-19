#ifndef relay_h
#define relay_h

#define RELAY_PIN 14

#include "pico/stdlib.h"

void relay_init(int relay_pin);

void relay_start(int relay_pin);

void relay_stop(int relay_pin);


#endif