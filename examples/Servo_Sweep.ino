/* Servo Sweep
 by Daniel Duller 12. January 2019
 This example code is in the public domain.
*/

#include <Servo_Hardware_PWM.h>

Servo myServo1;
Servo myServo2;
Servo myServo3;
Servo myServo4;
Servo myServo5;
Servo myServo6;

unsigned int index = 0;

void setup() {
  myServo1.attach(2);
  myServo2.attach(3);
  myServo3.attach(7);
  myServo4.attach(8);
  myServo5.attach(44);
  myServo6.attach(45);
}

void loop() {
  for (index = 500; index < 2500; index++){
    myServo1.writeMicroseconds(index);
    myServo2.writeMicroseconds(index);
    myServo3.writeMicroseconds(index);
    myServo4.writeMicroseconds(index);
    myServo5.writeMicroseconds(index);
    myServo6.writeMicroseconds(index);
    delay(10);
  }
  for (index = 2500; index > 500; index--){
    myServo1.writeMicroseconds(index);
    myServo2.writeMicroseconds(index);
    myServo3.writeMicroseconds(index);
    myServo4.writeMicroseconds(index);
    myServo5.writeMicroseconds(index);
    myServo6.writeMicroseconds(index);
    delay(10);
  }
}
