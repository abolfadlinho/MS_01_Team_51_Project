#include "pico/stdlib.h"
#include <stdio.h>
#include <string.h>

#include "infrared.h"
#include "lcd.h"
#include "relay.h"
#include "servo.h"
#include "touch.h"
#include "ultrasonic.h"

#include "hardware/adc.h"
#include "hardware/pwm.h"

uint trigPin = 18;
uint echoPin = 19;

int servo_pin_out = 26;
int touch_pin = 16;
int relay_pin = 17;

int servo_init_pos = 400;

bool motorOn = false;

int count = 0;

char str[9] = "Count: ";
char numStr[2];


    

int main() {
    stdio_init_all();

    //setupUltrasonicPins(trigPin, echoPin);
    infrared_init();
    relay_init(relay_pin);
    touch_init(touch_pin);
    // servo_init(servo_pin_out, servo_init_pos);

    //LCD block working
    lcdSetup(0, 1, 2, 3, 4, 5);
    lcdInit();
    lcdSetCursor(0, 0);
    lcdString("Welcome To EMBEDDED");
    lcdSetCursor(1, 0);
    lcdString("Team 51");

    

    // //For debugging
    // gpio_init(17);
    // gpio_set_dir(17, GPIO_OUT);
    // gpio_put(17, true);

    while (1) {
        // // Every loop we display count
        // lcdSetCursor(2, 0);
        // size_t len = strlen(str);
        // if (len > 8) { //is string already has two digits remove them before concat
        //     str[len - 2] = '\0';
        // } else if (len > 7) { //is string already has 1 digit remove it before concat
        //     str[len - 1] = '\0';
        // }
        // sprintf(numStr, "%d", count);
        // strcat(str, numStr);
        // lcdString(str);
        // sleep_ms(1500);

        // lcdSetCursor(2, 0);
        // lcdString("                "); //clear
        // sleep_ms(500);

        //Ultrasonic block working
        // uint64_t distance=getCm( trigPin, echoPin);
        // if(distance<20){
        //     gpio_put(6,true);
        // }
        // else{
        //     gpio_put(6,false);
        // }

        //Servo block working
        //sweep();

        //IR block working: clockwise menawar, anticlockwise mesh menawar, fel nos tamam: el ir el adeem abo 3 pins wel gedid abo 4 pins
        // bool irRead = infrared_read_digital();
        // if(irRead){
        //     gpio_put(6, false);  // Set the LED pin high
        //     //sleep_ms(200);      // Short delay for visual clarity
        // } else{
        //     gpio_put(6, true);  // Set the LED pin high
        //     //sleep_ms(200);      // Short delay for visual clarity
        // }

        //Touch Motor LCD subsystem working
        // bool touchRead = touch_is_pressed(touch_pin);
        // if(touchRead){
        //     gpio_put(6, true);  // Set the LED pin high
        //     //sleep_ms(200);      // Short delay for visual clarity
        // } else{
        //     gpio_put(6, false);  // Set the LED pin high
        //     //sleep_ms(200);      // Short delay for visual clarity
        // }

        // //Relay block working
        // relay_start(relay_pin);
        // sleep_ms(2000);
        // relay_stop(relay_pin);

        //_____________________________________
        //Subsystem LED IR relay touch working
        //_____________________________________
        lcdSetCursor(2, 0);
        size_t len = strlen(str);
        if (len > 8) { //is string already has two digits remove them before concat
            str[len - 2] = '\0';
        } else if (len > 7) { //is string already has 1 digit remove it before concat
            str[len - 1] = '\0';
        }
        sprintf(numStr, "%d", count);
        strcat(str, numStr);
        lcdString(str);
        sleep_ms(1500);
        bool irRead = infrared_read_digital();
        if(!irRead){ //remember IR is negative logic
            count++; //increment count whenever ir senses object
        }
        bool touchRead = touch_is_pressed(touch_pin);
        if(touchRead && !motorOn){
            relay_start(relay_pin); //start the motor
            motorOn = true;
            lcdSetCursor(2, 0);
            lcdString("                "); //clear
            count = 0; //reset count
            sleep_ms(2000);
        } else if(touchRead && motorOn) {
            relay_stop(relay_pin);  //stop the motor
            motorOn = false;
            sleep_ms(2000);
        }

        sleep_ms(100);
    }

    return 0;
}