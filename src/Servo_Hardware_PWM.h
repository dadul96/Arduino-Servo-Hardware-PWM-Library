/*
  Servo_Hardware_PWM.h - This Library allows Arduino/Genuino Mega boards to control up to 6 servos with the integrated 16-bit hardware PWM timer/counter.
  Created by Daniel Duller, 11. January, 2019.
  Changed by Daniel Duller, 14. January, 2019.

  ###############################################################################
  MIT License

  Copyright (c) 2019 Daniel Duller

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
  SOFTWARE.
  ###############################################################################

  
  #########################################################
  Only works on pin 2, 3, 7, 8, 44, and 45 on Arduino Mega!
  #########################################################
			Tested on Arduino Mega 2560 R3.
  #########################################################

  
  The methods are:

	Servo 				--- Class for manipulating servo motors connected to Arduino pins. (max. 6 elements)

	attach(pin)  		--- Attaches a servo motor to an i/o pin. (only pin 2, 3, 7, 8, 44, and 45)

	writeMicroseconds() --- Sets the servo pulse width in microseconds. (usable range between 500us and 2500us)

	detach()    		--- Clears the used registers and stops the output of the attached pin. (no pin number needed)
*/

#ifndef Servo_Hardware_PWM_h
#define Servo_Hardware_PWM_h

#if !defined(ARDUINO_ARCH_AVR)
#error "This library only supports boards with an AVR processor."
#endif

#define Servo_VERSION       1.0.0	//software version of this library

#define MIN_PULSE_WIDTH       500	//the shortest pulse sent to a servo  
#define MAX_PULSE_WIDTH      2500	//the longest pulse sent to a servo 
#define DEFAULT_PULSE_WIDTH     0	//default pulse width when servo is attached
#define MAX_TIMER_COUNT		40000	//the timer TOP value (for creating 50Hz)

#define MAX_SERVOS				6	//6 Servos can be attached

class Servo
{
public:
	Servo();
	void attach(int pin);				//attach the given pin
	void detach();						//detach the used pin
	void writeMicroseconds(int value);	//write pulse width in microseconds 
private:
	int servoIndex = 0;					//number of attached Servos
	int servoPin = 0;					//pin number of the attached Servo
};

#endif
