/*
  Servo_Hardware_PWM.h - This Library allows Arduino/Genuino Mega boards to control up to 9 servos with the integrated 16-bit hardware PWM timer/counter.
  Created by Daniel Duller, 11. January, 2019.
  Changed by Daniel Duller, 16. November, 2019.

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
  Only works on pin 2, 3, 5, 6, 7, 8, 44, 45 and 46 on Arduino Mega!
  #########################################################
			Tested on Arduino Mega 2560 R3.
  #########################################################


  The methods are:

	Servo 								---		Class for manipulating servo motors connected to Arduino pins. (max. 9 elements)

	attach(pin)  						---		Attaches a servo motor to an i/o pin. (only pin 2, 3, 5, 6, 7, 8, 44, 45 and 46)

	attach(pin, min, max)  				---		Attaches a servo motor to an i/o pin with a custom lower and upper pulse width limit.

	attach(pin, min, max, defaultPos)  	---		Attaches a servo motor to an i/o pin with a custom lower and upper pulse width limit. 
												In addition, the starting pulse width of the servo can be set with the defaultPos. 
												This allows the servo to start from a user-defined angle instead of the middle position.

	detach()    						---		Clears the used registers and stops the output of the attached pin. (no pin number!)

	detachAll()    						---		Clears the used registers and stops the output of ALL attached pins. (no pin number!)

	write(degrees)						---		Sets the servo angle in degrees. (usable range between 0° and 180°)

	writeMicroseconds(us)				---		Sets the servo pulse width in microseconds. (usable range between 500us and 2500us)

	read()								---		Returns the current angle (in degrees) that gets transmitted to the servo. (return type: int)

	readMicroseconds()					---		Returns the current angle (in microseconds) that gets transmitted to the servo. (return type: int)

	attached()							---		Returns true if the servo is attached. (return type: bool)
*/

#ifndef Servo_Hardware_PWM_h
#define Servo_Hardware_PWM_h

#include <inttypes.h>

#if !defined(__AVR_ATmega1280__) && !defined(__AVR_ATmega2560__)
#error "ERROR: This library only supports boards with an ATmega1280 or ATmega2560 processor. (Arduino/Genuino Mega/Mega1280/Mega2560)"
#endif

#define Servo_VERSION       1.3.0	//software version of this library

#define MIN_PULSE_WIDTH       500	//the shortest pulse sent to a servo  
#define MAX_PULSE_WIDTH      2500	//the longest pulse sent to a servo 
#define DEFAULT_PULSE_WIDTH  1500	//default pulse width when servo is attached
#define MAX_TIMER_COUNT		40000	//the timer TOP value (for creating 50Hz)

#define MAX_SERVOS				9	//9 Servos can be attached
#define INVALID_SERVO_NUMBER  255	//flag indicating an invalid servo index

class Servo {
public:
	Servo();
	uint8_t attach(int pin);									//attach the given pin; returns servoIndex number or 255 if too many servos
	uint8_t attach(int pin, int min, int max);					//attach the given pin and set the upper and lower pulse width limits; returns servoIndex number or 255 if too many servos
	uint8_t attach(int pin, int min, int max, int defaultPos);	//attach the given pin, set the upper and lower pulse width limits and set the pulse width when servo is attached; returns servoIndex number or 255 if too many servos
	void detach();												//detach the used pin
	void detachAll();											//automatically detaches all used pins
	void write(int value);										//write angle in degrees
	void writeMicroseconds(int value);							//write pulse width in microseconds
	int read();													//returns the current write angle in degrees
	int readMicroseconds();										//returns the current write angle in microseconds
	bool attached();											//returns true if this servo is attached, otherwise false 

private:
	uint8_t servoIndex;											//number of attached Servos
	uint8_t servoPin;											//pin number of the attached Servo
	uint16_t min;												//lower pulse width limit
	uint16_t max;												//upper pulse width limit
	uint16_t defaultPos;										//pulse width when servo is attached
	uint16_t pulseWidth;										//set pulse width
};

#endif
