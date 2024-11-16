// #include <stdio.h>
// #include "pico/stdlib.h"
// #include "ultrasonic.c"

// void ultrasonic_init(void);
// void ultrasonic_trigger(void);


// int main() {

//     // Initialize the LED pins
//     gpio_init(6);
//     gpio_set_dir(6,GPIO_OUT);

//     stdio_init_all();
//     ultrasonic_init();

//     while (true) {

//         ultrasonic_trigger();                  // Trigger the ultrasonic sensor
//         sleep_ms(10);     
//         gpio_put(6, 1);
//         sleep_ms(500);                     // Delay to allow for measurement processing
//         float distance = ultrasonic_calculate_distance_cm(); // Get the distance in cm
//         printf("Distance:  cm\n" ); // Print the distance*/

        // gpio_put(6, 0);
        // sleep_ms(500);
//     }


// }

// #include <stdio.h>
// #include "ultrasonic.h"
// #include "hardware/uart.h"


// // uint trigPin = 2;
// // uint echoPin = 3;
// void ultrasonic_init(void);
// void ultrasonic_trigger(void);


// int main()
// {
// stdio_init_all();
// // setupUltrasonicPins(trigPin, echoPin);
//     gpio_init(6);
//     gpio_set_dir(6,GPIO_OUT);

//     stdio_init_all();
//     while (true) {
//         gpio_put(6, 1);
//         sleep_ms(500);  
//         // getCm(trigPin, echoPin);
//         gpio_put(6, 0);
//         sleep_ms(500);
//         sleep_us (10000);
//     }
// }

//This example uses the ultrasonic script to get centimeters and writes it to UART

#include "pico/stdlib.h"
#include <stdio.h>
// #include "ultrasonic.h"
// #include "hardware/uart.h"

// uint trigPin = 2;
// uint echoPin = 3;

// int main()
// {
//     stdio_init_all();
//     // setupUltrasonicPins(trigPin, echoPin);

//     gpio_init(6);
//     gpio_set_dir(6,1);

//     while (true) { 
//         gpio_put(6, 1);
//         sleep_ms(500);  
//         // printf("\n %d cm", getCm(trigPin, echoPin)); 
//         gpio_put(6, 0);
//         sleep_ms(500);  
//         sleep_ms(100);
//     }
// }
#include "pico/stdlib.h"
#include <stdio.h>
#include "ultrasonic.h"
#include "infrared.h"
#include "servo.h"
#include "touch.h"
#include "hardware/adc.h"
#include "hardware/pwm.h"

uint trigPin = 4;
uint echoPin = 3;
int servo_pin_out = 26;
int touch_pin = 16;

int servo_init_pos = 400;

int main()
{
    stdio_init_all();


    //inits
    setupUltrasonicPins(trigPin, echoPin);
    infrared_init();
    touch_init(touch_pin);
    servo_init(servo_pin_out, servo_init_pos);

    //green led
    gpio_init(6);
    gpio_set_dir(6, GPIO_OUT);


    while (true) {
        //ultrasonic block working
        /*uint64_t distance=getCm( trigPin, echoPin);
        if(distance<20){
            gpio_put(6,true);
        }
        else{
            gpio_put(6,false);
        }*/

        //servo block working
        //sweep();

        //ir block working: clockwise menawar, anticlockwise mesh menawar, fel nos tamam: el ir el adeem abo 3 pins wel gedid abo 4 pins
        // bool irRead = infrared_read_digital();
        // if(irRead){
        //     gpio_put(6, false);  // Set the LED pin high
        //     //sleep_ms(200);      // Short delay for visual clarity
        // } else{
        //     gpio_put(6, true);  // Set the LED pin high
        //     //sleep_ms(200);      // Short delay for visual clarity
        // }

        //touch block working
        // bool touchRead = touch_is_pressed(touch_pin);
        // if(touchRead){
        //     gpio_put(6, true);  // Set the LED pin high
        //     //sleep_ms(200);      // Short delay for visual clarity
        // } else{
        //     gpio_put(6, false);  // Set the LED pin high
        //     //sleep_ms(200);      // Short delay for visual clarity
        // }

        //mesh shaghalaaaa analog ya3
        /*uint16_t isRead = infrared_read_analog();
        if(isRead < 200) {
            gpio_put(6, true);  // Set the LED pin high
            //sleep_ms(200);      // Short delay for visual clarity
        } else{
            gpio_put(6, false);  // Set the LED pin high
            //sleep_ms(200);      // Short delay for visual clarity
        }*/

        // sleep_ms(500);  
        sleep_ms(200);
    }
}
