#include "pico/stdlib.h"
#include <stdio.h>

#include "infrared.h"
#include "lcd.h"
#include "relay.h"
#include "servo.h"
#include "touch.h"
#include "ultrasonic.h"

#include "hardware/adc.h"
#include "hardware/pwm.h"

uint trigPin = 4;
uint echoPin = 3;

int servo_pin_out = 26;
int touch_pin = 16;
int relay_pin = 14;

int servo_init_pos = 400;

int main() {
    stdio_init_all();

    setupUltrasonicPins(trigPin, echoPin);
    infrared_init();
    relay_init(relay_pin);
    touch_init(touch_pin);
    servo_init(servo_pin_out, servo_init_pos);

    //LCD block workung
    lcdSetup(0, 1, 2, 3, 4, 5);
    lcdInit();
    lcdSetCursor(0, 0);
    lcdString("Hello, World!");
    lcdSetCursor(1, 0);
    lcdString("LCD Initialized");

    //For debugging
    gpio_init(6);
    gpio_set_dir(6, GPIO_OUT);

    while (1) {
        // LCD block working
        lcdSetCursor(2, 0);
        lcdString("Blinking Text!  ");
        sleep_ms(500);
        lcdSetCursor(2, 0);
        lcdString("                "); //clear
        sleep_ms(500);

        //Ultrasonic block working
        uint64_t distance=getCm( trigPin, echoPin);
        if(distance<20){
            gpio_put(6,true);
        }
        else{
            gpio_put(6,false);
        }

        //Servo block working
        sweep();

        //IR block working: clockwise menawar, anticlockwise mesh menawar, fel nos tamam: el ir el adeem abo 3 pins wel gedid abo 4 pins
        bool irRead = infrared_read_digital();
        if(irRead){
            gpio_put(6, false);  // Set the LED pin high
            //sleep_ms(200);      // Short delay for visual clarity
        } else{
            gpio_put(6, true);  // Set the LED pin high
            //sleep_ms(200);      // Short delay for visual clarity
        }

        //Touch block working
        bool touchRead = touch_is_pressed(touch_pin);
        if(touchRead){
            gpio_put(6, true);  // Set the LED pin high
            //sleep_ms(200);      // Short delay for visual clarity
        } else{
            gpio_put(6, false);  // Set the LED pin high
            //sleep_ms(200);      // Short delay for visual clarity
        }

        //Relay block working
        relay_start(relay_pin);
        sleep_ms(2000);
        relay_stop(relay_pin);

        sleep_ms(1000);
    }

    return 0;
}