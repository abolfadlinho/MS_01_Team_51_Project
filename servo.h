#ifndef servo_h
#define servo_h

#define SERVO_PIN 26

void setMillis(int servoPin, float millis);
void servo_init(int servoPin, float startMillis);
void sweep();

#endif