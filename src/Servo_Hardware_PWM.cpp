/*
For information about the library, license and author, see Servo_Hardware_PWM.h - file.
*/

#if defined(ARDUINO_ARCH_AVR)

#include <Arduino.h>
#include <Servo_Hardware_PWM.h>

static int servoCount = 0;
static bool pinActive[MAX_SERVOS] = {false};

Servo::Servo()
{
	if (servoCount < MAX_SERVOS) {
		this->servoIndex = servoCount++; //assign a servoIndex to this instance
	}
}

void Servo::attach(int pin)
{
	if (this->servoIndex < MAX_SERVOS) {
		if (pin == 2) {
			if(pinActive[1] == false){
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

			OCR3B = DEFAULT_PULSE_WIDTH; //setting the pulse width

			//OC3B, Port E, Bit 4; setting pin 2 as output:
			DDRE |= (1 << PE4); //bit 4 (pin 2) as output  
			
			pinActive[0] = true;
			this->servoPin = 2;
		}
		else if (pin == 3) {
			if(pinActive[0] == false){
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

			OCR3C = DEFAULT_PULSE_WIDTH; //setting the pulse width

			//OC3C, Port E, Bit 5; setting pin 3 as output:
			DDRE |= (1 << PE5); //bit 5 (pin 3) as output  
			
			pinActive[1] = true;
			this->servoPin = 3;
		}
		else if (pin == 7) {
			if(pinActive[3] == false){
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

			OCR4B = DEFAULT_PULSE_WIDTH; //setting the pulse width

			//OC4B, Port H, Bit 4; setting pin 7 as output:
			DDRH |= (1 << PH4); //bit 4 (pin 7) as output  
			
			pinActive[2] = true;
			this->servoPin = 7;
		}
		else if (pin == 8) {
			if(pinActive[2] == false){
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

			OCR4C = DEFAULT_PULSE_WIDTH; //setting the pulse width

			//OC4C, Port H, Bit 5; setting pin 8 as output:
			DDRH |= (1 << PH5); //bit 5 (pin 8) as output  
			
			pinActive[3] = true;
			this->servoPin = 8;
		}
		else if (pin == 44) {
			if(pinActive[5] == false){
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

			OCR5C = DEFAULT_PULSE_WIDTH; //setting the pulse width

			//OC5C, Port L, Bit 5; setting pin 44 as output:
			DDRL |= (1 << PL5); //bit 5 (pin 44) as output
			
			pinActive[4] = true;
			this->servoPin = 44;
		}
		else if (pin == 45) {
			if(pinActive[4] == false){
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

			OCR5B = DEFAULT_PULSE_WIDTH; //setting the pulse width

			//OC5B, Port L, Bit 4; setting pin 45 as output:
			DDRL |= (1 << PL4); //bit 4 (pin 45) as output
			
			pinActive[5] = true;
			this->servoPin = 45;
		}
	}
}

void Servo::detach()
{
 	if (servoPin == 2) {
		if(pinActive[1] == false){
			//resetting the control register A and B:
			TCCR3A = 0x0;
			TCCR3B = 0x0;
			//resetting the TOP value:
			OCR3A = 0x0;
		}
		OCR3B = 0x0; //resetting the pulse width
		DDRE ^= (1 << PE4); //bit 4 (pin 2) stop output
 		pinActive[0] = false;		
		this->servoPin = 0; 
	}
	else if (servoPin == 3) {
		if(pinActive[0] == false){
			//resetting the control register A and B:
			TCCR3A = 0x0;
			TCCR3B = 0x0;
			//resetting the TOP value:
			OCR3A = 0x0;
		}
		OCR3C = 0x0; //resetting the pulse width
		DDRE ^= (1 << PE5); //bit 5 (pin 3) stop output
		pinActive[1] = false;
		this->servoPin = 0;
	}
	else if (servoPin == 7) {
		if(pinActive[3] == false){
			//resetting the control register A and B:
			TCCR4A = 0x0;
			TCCR4B = 0x0;
			//resetting the TOP value:
			OCR4A = 0x0;
		}
		OCR4B = 0x0; //resetting the pulse width
		DDRH ^= (1 << PH4); //bit 4 (pin 7) stop output
		pinActive[2] = false;
		this->servoPin = 0;
		}
	else if (servoPin == 8) {
		if(pinActive[2] == false){
			//resetting the control register A and B:
			TCCR4A = 0x0;
			TCCR4B = 0x0;
			//resetting the TOP value:
			OCR4A = 0x0;
		}
		OCR4C = 0x0; //resetting the pulse width
		DDRH ^= (1 << PH5); //bit 5 (pin 8) stop output
		pinActive[3] = false;
		this->servoPin = 0;
	}
	else if (servoPin == 44) {
		if(pinActive[5] == false){
			//resetting the control register A and B:
			TCCR5A = 0x0;
			TCCR5B = 0x0;
			//resetting the TOP value:
			OCR5A = 0x0;
		}
		OCR5C = 0x0; //resetting the pulse width
		DDRL ^= (1 << PL5); //bit 5 (pin 44) stop output
		pinActive[4] = false;
		this->servoPin = 0;
	}
	else if (servoPin == 45) {
		if(pinActive[4] == false){
			//resetting the control register A and B:
			TCCR5A = 0x0;
			TCCR5B = 0x0;
			//resetting the TOP value:
			OCR5A = 0x0;
		}
		OCR5B = 0x0; //resetting the pulse width
		DDRL ^= (1 << PL4); //bit 4 (pin 45) stop output
		pinActive[5] = false;
		this->servoPin = 0;
	}
}

void Servo::write(int value) 
{
	if (value < 0)
	{
		value = 0;
	}
	else if (value > 180)
	{
		value = 180;
	}
	value = map(value, 0, 180, MIN_PULSE_WIDTH, MAX_PULSE_WIDTH);

	this->writeMicroseconds(value);
}

void Servo::writeMicroseconds(int value)
{
	if ((this->servoIndex < MAX_SERVOS)) {
		if (value < MIN_PULSE_WIDTH) {
			value = MIN_PULSE_WIDTH;
		}
		else if (value > MAX_PULSE_WIDTH) {
			value = MAX_PULSE_WIDTH;
		}
		if (this->servoPin == 2) {
			OCR3B = 0x0;
			OCR3B = value * 2;
		}
		else if (this->servoPin == 3) {
			OCR3C = 0x0;
			OCR3C = value * 2;
		}
		else if (this->servoPin == 7) {
			OCR4B = 0x0;
			OCR4B = value * 2;
		}
		else if (this->servoPin == 8) {
			OCR4C = 0x0;
			OCR4C = value * 2;
		}
		else if (this->servoPin == 44) {
			OCR5C = 0x0;
			OCR5C = value * 2;
		}
		else if (this->servoPin == 45) {
			OCR5B = 0x0;
			OCR5B = value * 2;
		}
	}
}
#endif
