#include "WProgram.h"

extern "C" 

int main(void) {
	pinMode(13, OUTPUT);
	uint32_t i = 0;
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
