#include "WProgram.h"

extern "C" 

#define Bluetooth Serial1 // using serial port 1 for bluetooth communication

int main(void) {
    Bluetooth.begin(9600); // initialize bluetooth at 9600 buad
    char c = 'a';
    int adcVal = 0;
    pinMode(A0,INPUT); // set analog pin 0 as input
    pinMode(13, OUTPUT);
	uint32_t i = 0;

	while (1) {
		if(Bluetooth.available() > 0) {
			c = Bluetooth.read();
			Bluetooth.print(c);
		}
		if(c == 'r') {
			adcVal = analogRead(0); // analog reading on A0
			Bluetooth.println(adcVal);
			c = 'a';
	}

	while (1) {
		digitalWriteFast(13, HIGH);
		delay(100);
		digitalWriteFast(13, LOW);
		delay(100);
		digitalWriteFast(13, HIGH);
		delay(100);
		digitalWriteFast(13, LOW);
		delay(100);
		digitalWriteFast(13, HIGH);
		delay(1000);
		digitalWriteFast(13, LOW);
		delay(1000);
		Serial.print("Good Test ");
		Serial.println(i);
		i++;
	}
}
