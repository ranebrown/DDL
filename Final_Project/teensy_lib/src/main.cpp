#include "WProgram.h"

extern "C" 

#define Bluetooth Serial1 // using serial port 1 for bluetooth communication

int main(void) {
    Bluetooth.begin(9600); // initialize bluetooth at 9600 buad
    char c = 'a';
    int adcVal = 0;
    pinMode(A0,INPUT); // set analog pin 0 as input

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
	}
}