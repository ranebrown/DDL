#include "WProgram.h"

extern "C"

#define Bluetooth Serial1 // using serial port 1 for bluetooth communication

int main(void) {

    Bluetooth.begin(9600);  // initialize bluetooth at 9600 buad
    char c = 'a';
    int adcVal = 0;
    pinMode(A0,INPUT); // set analog pin 0 as input
    pinMode(13, OUTPUT);
    uint32_t i = 0;

    // https://www.pjrc.com/teensy/td_libs_SPI.html
    // https://github.com/xxxajk/spi4teensy3  <----For a Teensy3 library
    //SPI.begin();   // initialize SPI communication TODO pin configs for SPI

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

    //Flash the LED a few times then write to the terminal.
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
