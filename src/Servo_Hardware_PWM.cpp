/*
For information about the library, license and author, see Servo_Hardware_PWM.h - file.
*/

#if defined(ARDUINO_ARCH_AVR)

#include <Arduino.h>
#include <Servo_Hardware_PWM.h>

#define BOOL_FALSE 0
#define BOOL_TRUE 255

static uint8_t servoCount = 0;
static uint8_t pinActive[MAX_SERVOS] = {BOOL_FALSE};

Servo::Servo()
{
	this->servoIndex = 0;
	this->servoPin = 0;

	if (servoCount < MAX_SERVOS) {
		this->servoIndex = servoCount++; //assign a servoIndex to this instance
	}
	else
	{
		this->servoIndex = INVALID_SERVO_NUMBER; //too many servos
	}
}

uint8_t Servo::attach(int pin)
{
	return this->attach(pin, MIN_PULSE_WIDTH, MAX_PULSE_WIDTH, DEFAULT_PULSE_WIDTH);
}

uint8_t Servo::attach(int pin, int min, int max)
{
	return this->attach(pin, min, max, DEFAULT_PULSE_WIDTH);
}

uint8_t Servo::attach(int pin, int min, int max, int defaultPos)
{
	this->min = min;
	this->max = max;
	this->defaultPos = defaultPos;

	if (this->servoIndex < MAX_SERVOS) {
		if (pin == 2) {
			if(pinActive[1] == BOOL_FALSE){
				//resetting the control register A and B:
				TCCR3A = 0x0;
				TCCR3B = 0x0;
			}

			//setting the prescaler to 8 (2MHz):
			TCCR3B |= (1 << CS31);

			//setting the waveform generation mode to 15:
			TCCR3A |= (1 << WGM31) | (1 << WGM30);
			TCCR3B |= (1 << WGM32) | (1 << WGM33);

			//setting the TOP value:
			OCR3A = MAX_TIMER_COUNT; //results in 50Hz at 2MHz Clock

			//setting the output to non inverted:
			TCCR3A |= (1 << COM3B1);

			OCR3B = this->defaultPos; //setting the pulse width

			//OC3B, Port E, Bit 4; setting pin 2 as output:
			DDRE |= (1 << PE4); //bit 4 (pin 2) as output  
			
			pinActive[0] = BOOL_TRUE;
			this->servoPin = 2;
		}
		else if (pin == 3) {
			if(pinActive[0] == BOOL_FALSE){
				//resetting the control register A and B:
				TCCR3A = 0x0;
				TCCR3B = 0x0;
			}

			//setting the prescaler to 8 (2MHz):
			TCCR3B |= (1 << CS31);

			//setting the waveform generation mode to 15:
			TCCR3A |= (1 << WGM31) | (1 << WGM30);
			TCCR3B |= (1 << WGM32) | (1 << WGM33);

			//setting the TOP value:
			OCR3A = MAX_TIMER_COUNT; //results in 50Hz at 2MHz Clock

			//setting the output to non inverted:
			TCCR3A |= (1 << COM3C1);

			OCR3C = this->defaultPos; //setting the pulse width

			//OC3C, Port E, Bit 5; setting pin 3 as output:
			DDRE |= (1 << PE5); //bit 5 (pin 3) as output  
			
			pinActive[1] = BOOL_TRUE;
			this->servoPin = 3;
		}
		else if (pin == 7) {
			if(pinActive[3] == BOOL_FALSE){
				//resetting the control register A and B:
				TCCR4A = 0x0;
				TCCR4B = 0x0;
			}

			//setting the prescaler to 8 (2MHz):
			TCCR4B |= (1 << CS41);

			//setting the waveform generation mode to 15:
			TCCR4A |= (1 << WGM41) | (1 << WGM40);
			TCCR4B |= (1 << WGM42) | (1 << WGM43);

			//setting the TOP value:
			OCR4A = MAX_TIMER_COUNT; //results in 50Hz at 2MHz Clock

			//setting the output to non inverted:
			TCCR4A |= (1 << COM4B1);

			OCR4B = this->defaultPos; //setting the pulse width

			//OC4B, Port H, Bit 4; setting pin 7 as output:
			DDRH |= (1 << PH4); //bit 4 (pin 7) as output  
			
			pinActive[2] = BOOL_TRUE;
			this->servoPin = 7;
		}
		else if (pin == 8) {
			if(pinActive[2] == BOOL_FALSE){
				//resetting the control register A and B:
				TCCR4A = 0x0;
				TCCR4B = 0x0;
			}

			//setting the prescaler to 8 (2MHz):
			TCCR4B |= (1 << CS41);

			//setting the waveform generation mode to 15:
			TCCR4A |= (1 << WGM41) | (1 << WGM40);
			TCCR4B |= (1 << WGM42) | (1 << WGM43);

			//setting the TOP value:
			OCR4A = MAX_TIMER_COUNT; //results in 50Hz at 2MHz Clock

			//setting the output to non inverted:
			TCCR4A |= (1 << COM4C1);

			OCR4C = this->defaultPos; //setting the pulse width

			//OC4C, Port H, Bit 5; setting pin 8 as output:
			DDRH |= (1 << PH5); //bit 5 (pin 8) as output  
			
			pinActive[3] = BOOL_TRUE;
			this->servoPin = 8;
		}
		else if (pin == 44) {
			if(pinActive[5] == BOOL_FALSE){
				//resetting the control register A and B:
				TCCR5A = 0x0;
				TCCR5B = 0x0;
			}
			
			//setting the prescaler to 8 (2MHz):
			TCCR5B |= (1 << CS51);

			//setting the waveform generation mode to 15:
			TCCR5A |= (1 << WGM51) | (1 << WGM50);
			TCCR5B |= (1 << WGM52) | (1 << WGM53);

			//setting the TOP value:
			OCR5A = MAX_TIMER_COUNT; //results in 50Hz at 2MHz Clock

			//setting the output to non inverted:
			TCCR5A |= (1 << COM5C1);

			OCR5C = this->defaultPos; //setting the pulse width

			//OC5C, Port L, Bit 5; setting pin 44 as output:
			DDRL |= (1 << PL5); //bit 5 (pin 44) as output
			
			pinActive[4] = BOOL_TRUE;
			this->servoPin = 44;
		}
		else if (pin == 45) {
			if(pinActive[4] == BOOL_FALSE){
				//resetting the control register A and B:
				TCCR5A = 0x0;
				TCCR5B = 0x0;
			}

			//setting the prescaler to 8 (2MHz):
			TCCR5B |= (1 << CS51);

			//setting the waveform generation mode to 15:
			TCCR5A |= (1 << WGM51) | (1 << WGM50);
			TCCR5B |= (1 << WGM52) | (1 << WGM53);

			//setting the TOP value:
			OCR5A = MAX_TIMER_COUNT; //results in 50Hz at 2MHz Clock

			//setting the output to non inverted:
			TCCR5A |= (1 << COM5B1);

			OCR5B = this->defaultPos; //setting the pulse width

			//OC5B, Port L, Bit 4; setting pin 45 as output:
			DDRL |= (1 << PL4); //bit 4 (pin 45) as output
			
			pinActive[5] = BOOL_TRUE;
			this->servoPin = 45;
		}
	}
	
	return this->servoIndex;
}

void Servo::detach()
{
 	if (servoPin == 2 && pinActive[0] == BOOL_TRUE) {
		if(pinActive[1] == BOOL_FALSE){
			//resetting the control register A and B:
			TCCR3A = 0x0;
			TCCR3B = 0x0;
			//resetting the TOP value:
			OCR3A = 0x0;
		}
		OCR3B = 0x0; //resetting the pulse width
		DDRE ^= (1 << PE4); //bit 4 (pin 2) stop output
 		pinActive[0] = BOOL_FALSE;		
		this->servoPin = 0; 
	}
	else if (servoPin == 3 && pinActive[1] == BOOL_TRUE) {
		if(pinActive[0] == BOOL_FALSE){
			//resetting the control register A and B:
			TCCR3A = 0x0;
			TCCR3B = 0x0;
			//resetting the TOP value:
			OCR3A = 0x0;
		}
		OCR3C = 0x0; //resetting the pulse width
		DDRE ^= (1 << PE5); //bit 5 (pin 3) stop output
		pinActive[1] = BOOL_FALSE;
		this->servoPin = 0;
	}
	else if (servoPin == 7 && pinActive[2] == BOOL_TRUE) {
		if(pinActive[3] == BOOL_FALSE){
			//resetting the control register A and B:
			TCCR4A = 0x0;
			TCCR4B = 0x0;
			//resetting the TOP value:
			OCR4A = 0x0;
		}
		OCR4B = 0x0; //resetting the pulse width
		DDRH ^= (1 << PH4); //bit 4 (pin 7) stop output
		pinActive[2] = BOOL_FALSE;
		this->servoPin = 0;
		}
	else if (servoPin == 8 && pinActive[3] == BOOL_TRUE) {
		if(pinActive[2] == BOOL_FALSE){
			//resetting the control register A and B:
			TCCR4A = 0x0;
			TCCR4B = 0x0;
			//resetting the TOP value:
			OCR4A = 0x0;
		}
		OCR4C = 0x0; //resetting the pulse width
		DDRH ^= (1 << PH5); //bit 5 (pin 8) stop output
		pinActive[3] = BOOL_FALSE;
		this->servoPin = 0;
	}
	else if (servoPin == 44 && pinActive[4] == BOOL_TRUE) {
		if(pinActive[5] == BOOL_FALSE){
			//resetting the control register A and B:
			TCCR5A = 0x0;
			TCCR5B = 0x0;
			//resetting the TOP value:
			OCR5A = 0x0;
		}
		OCR5C = 0x0; //resetting the pulse width
		DDRL ^= (1 << PL5); //bit 5 (pin 44) stop output
		pinActive[4] = BOOL_FALSE;
		this->servoPin = 0;
	}
	else if (servoPin == 45 && pinActive[5] == BOOL_TRUE) {
		if(pinActive[4] == BOOL_FALSE){
			//resetting the control register A and B:
			TCCR5A = 0x0;
			TCCR5B = 0x0;
			//resetting the TOP value:
			OCR5A = 0x0;
		}
		OCR5B = 0x0; //resetting the pulse width
		DDRL ^= (1 << PL4); //bit 4 (pin 45) stop output
		pinActive[5] = BOOL_FALSE;
		this->servoPin = 0;
	}
}

void Servo::detachAll() {
	if (pinActive[0] == BOOL_TRUE)
	{
		//resetting the control register A and B:
		TCCR3A = 0x0;
		TCCR3B = 0x0;
		//resetting the TOP value:
		OCR3A = 0x0;

		OCR3B = 0x0; //resetting the pulse width
		DDRE ^= (1 << PE4); //bit 4 (pin 2) stop output
		pinActive[0] = BOOL_FALSE;
	}
	if (pinActive[1] == BOOL_TRUE)
	{
		//resetting the control register A and B:
		TCCR3A = 0x0;
		TCCR3B = 0x0;
		//resetting the TOP value:
		OCR3A = 0x0;

		OCR3C = 0x0; //resetting the pulse width
		DDRE ^= (1 << PE5); //bit 5 (pin 3) stop output
		pinActive[1] = BOOL_FALSE;
	}
	if (pinActive[2] == BOOL_TRUE)
	{
		//resetting the control register A and B:
		TCCR4A = 0x0;
		TCCR4B = 0x0;
		//resetting the TOP value:
		OCR4A = 0x0;

		OCR4B = 0x0; //resetting the pulse width
		DDRH ^= (1 << PH4); //bit 4 (pin 7) stop output
		pinActive[2] = BOOL_FALSE;
	}
	if (pinActive[3] == BOOL_TRUE)
	{
		//resetting the control register A and B:
		TCCR4A = 0x0;
		TCCR4B = 0x0;
		//resetting the TOP value:
		OCR4A = 0x0;

		OCR4C = 0x0; //resetting the pulse width
		DDRH ^= (1 << PH5); //bit 5 (pin 8) stop output
		pinActive[3] = BOOL_FALSE;
	}
	if (pinActive[4] == BOOL_TRUE)
	{
		//resetting the control register A and B:
		TCCR5A = 0x0;
		TCCR5B = 0x0;
		//resetting the TOP value:
		OCR5A = 0x0;

		OCR5C = 0x0; //resetting the pulse width
		DDRL ^= (1 << PL5); //bit 5 (pin 44) stop output
		pinActive[4] = BOOL_FALSE;
	}
	if (pinActive[5] == BOOL_TRUE)
	{
		//resetting the control register A and B:
		TCCR5A = 0x0;
		TCCR5B = 0x0;
		//resetting the TOP value:
		OCR5A = 0x0;

		OCR5B = 0x0; //resetting the pulse width
		DDRL ^= (1 << PL4); //bit 4 (pin 45) stop output
		pinActive[5] = BOOL_FALSE;
	}
}

void Servo::write(int value) 
{
	float tempValue;

	if (value <= 0)
	{
		tempValue = 0.0;
	}
	else if (value >= 180)
	{
		tempValue = 180.0;
	}
	else
	{
		tempValue = (float)value;
	}

	tempValue = (((this->max - this->min) * tempValue) / 180.0) + this->min;

	value = (int)tempValue;
	this->writeMicroseconds(value);
}

void Servo::writeMicroseconds(int value)
{
	if ((this->servoIndex < MAX_SERVOS)) {
		if (value < this->min) {
			value = this->min;
		}
		else if (value > this->max) {
			value = this->max;
		}
		this->pulseWidth = value;

		if (this->servoPin == 2 && pinActive[0] == BOOL_TRUE) {
			OCR3B = 0x0;
			OCR3B = this->pulseWidth * 2;
		}
		else if (this->servoPin == 3 && pinActive[1] == BOOL_TRUE) {
			OCR3C = 0x0;
			OCR3C = this->pulseWidth * 2;
		}
		else if (this->servoPin == 7 && pinActive[2] == BOOL_TRUE) {
			OCR4B = 0x0;
			OCR4B = this->pulseWidth * 2;
		}
		else if (this->servoPin == 8 && pinActive[3] == BOOL_TRUE) {
			OCR4C = 0x0;
			OCR4C = this->pulseWidth * 2;
		}
		else if (this->servoPin == 44 && pinActive[4] == BOOL_TRUE) {
			OCR5C = 0x0;
			OCR5C = this->pulseWidth * 2;
		}
		else if (this->servoPin == 45 && pinActive[5] == BOOL_TRUE) {
			OCR5B = 0x0;
			OCR5B = this->pulseWidth * 2;
		}
	}
}

int Servo::read() {
	float angle;

	if ((this->readMicroseconds() - this->min) <= 0)
	{
		angle = 0.0;
	}
	else
	{
		angle = (180.0 / (this->max - this->min)) * (this->readMicroseconds() - this->min);
	}

	return (int)angle;
}

int Servo::readMicroseconds() {
	if (this->servoIndex == INVALID_SERVO_NUMBER)
	{
		this->pulseWidth = 0;
	}

	return this->pulseWidth;
}
#endif
