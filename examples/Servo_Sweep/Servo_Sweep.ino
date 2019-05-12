/* Servo Sweep
 by Daniel Duller 12. January 2019
 This example code is in the public domain.
*/

#include <Servo_Hardware_PWM.h>

Servo myServo1; //creating a servo object (any custom name could be used)
Servo myServo2;
Servo myServo3;
Servo myServo4;
Servo myServo5;
Servo myServo6;

unsigned int valueMicros = 0; //variable that contains the microseconds

void setup() {
  myServo1.attach(2); //attaches the servo to pin 2
  myServo2.attach(3);
  myServo3.attach(7);
  myServo4.attach(8);
  myServo5.attach(44);
  myServo6.attach(45);
}

void loop() {
  for (valueMicros = 500; valueMicros < 2500; valueMicros++){ //goes from 0° to 180° (500us to 2500us)
    myServo1.writeMicroseconds(valueMicros);	//writes the value of valueMicros to the servo
    myServo2.writeMicroseconds(valueMicros);
    myServo3.writeMicroseconds(valueMicros);
    myServo4.writeMicroseconds(valueMicros);
    myServo5.writeMicroseconds(valueMicros);
    myServo6.writeMicroseconds(valueMicros);
    delay(10);
  }
  for (valueMicros = 2500; valueMicros > 500; valueMicros--){ //goes from 180° to 0° (2500us to 500us)
    myServo1.writeMicroseconds(valueMicros);
    myServo2.writeMicroseconds(valueMicros);
    myServo3.writeMicroseconds(valueMicros);
    myServo4.writeMicroseconds(valueMicros);
    myServo5.writeMicroseconds(valueMicros);
    myServo6.writeMicroseconds(valueMicros);
    delay(10);
  }
}
