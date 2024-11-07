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
#include "ultrasonic.h"  // Include the header for ultrasonic sensor functions
#include "infrared.h"
//#include "servo.h"

uint trigPin = 4;
uint echoPin = 3;

int main()
{
    stdio_init_all();  // Initialize standard I/O

    setupUltrasonicPins(trigPin, echoPin);  // Initialize the sensor pins
    infrared_init();
    servo_init();
    gpio_init(6);
    gpio_set_dir(6, GPIO_OUT);


    while (true) {
        /*uint64_t distance=getCm( trigPin, echoPin);
        if(distance<20){
            gpio_put(6,true);
        }
        else{
            gpio_put(6,false);
        }*/
        /*bool irRead = infrared_read_digital();

         if(irRead){
              gpio_put(6, false);  // Set the LED pin high
             sleep_ms(200);      // Short delay for visual clarity
         }
        else{
            gpio_put(6, true);  // Set the LED pin high
            sleep_ms(200);      // Short delay for visual clarity

         }*/
        
        // sleep_ms(500);  

        // // Get the distance in cm from the ultrasonic sensor
        // int distance = getCm(trigPin, echoPin);
        // printf("Distance: %d cm\n", distance);  // Print the distance

        // bool irRead = infrared_read_digital()

        // gpio_put(6, 0);  // Set the LED pin low
        // sleep_ms(500);  
        sleep_ms(500);
    }
}
