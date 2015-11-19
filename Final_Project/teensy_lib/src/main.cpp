#include "WProgram.h"
#include "blinds.h"

extern "C"

#define Bluetooth Serial1 // using serial port 1 for bluetooth communication
#define start 19    // pin connected to button
#define motor A0    // analog pin for reading motor voltage

int main(void) {
    Bluetooth.begin(9600); // initialize bluetooth at 9600 buad
    char c = 'a';
    int adcVal = 0;
    pinMode(A0,INPUT); // set analog pin 0 as input
    pinMode(A9,OUTPUT); // set analog pin as output
    // pinMode(13, OUTPUT); // LED connected to pin 13
    pinMode(start,INPUT); 
    uint32_t i = 0;
    char buff[10];
    int index = 0;
    Serial.begin(9600); // usb serial
    pinMode(2,INPUT);
    int myP = 0;
    maxRot = 30;


    while (1) {
       // Serial.println(digitalRead(2));
        //delay(100);

        // check if start button pressed
        if(digitalRead(start) == 0) {
            currRot = 0;
            right();
            while(analogRead(motor) > 775) {
                if(digitalRead(2) == 0)
                    currRot++;
                delay(50);
            }
            stop();
            maxRot = currRot;
            Serial.println(currRot);
        }

        // store command in buffer
        if(Bluetooth.available() > 0) {
            c = Bluetooth.read();
            if(index < 10) {
                buff[index] = c;
                index++;
            }
            else {
                Bluetooth.print("Buffer full\r\n");
            }
        }

        // parse command
        if(c == 'p') {
            for(index = 0; index < 10; index++) {
                Bluetooth.print(buff[index]);
            }
            index = 0;
            c = 'a';
        }

        // if(c == 'v') {
        //     adcVal = analogRead(5); // analog reading on A0
        //     Bluetooth.println(adcVal);
        //     c = 'a';
        // }

        // manual movement
        if(c == 'i') {
            myP += 10;
            if(myP>=100)
                myP=100;
            Serial.println(myP);
            c = 'a';
        }
        if(c == 'd') {
            myP -= 10;
            if(myP<=0)
                myP=0;
            Serial.println(myP);
            c = 'a';
        }
        if(c == 't') {
            setPerc(myP);
            Serial.println(currRot);
            c = 'a';
        }
        if(Serial.available() > 0) {
            c = Serial.read();
        }
        if(c == 'l') {
            left();
            c = 'a';
        }
        if(c == 'r') {
            right();
            c = 'a';
        }
        if(c == 's') {
            stop();
            c = 'a';
        }
        if(c=='q') {
            Serial.println(currRot);
            int x = (currRot*50)/100;
            Serial.println(x);
            c = 'a';
        }
        rotCount();

        // p0000 percentage to open 
        // o0000 set open time
        // c0000 set close time

        // When adc value > X stop motor
        // while opening hall effect sensor counts rotations
        // all the way closed set to calcuated i 
        // all the way open set to calcualted rotations in other direction

        // 2 digit value sent over bluetooth representing percentage to open
        // num of rotations * percentage = num rotations to open 

        /* communications
            open/close by percentage
            scheduled open/close time 24 hr format
            initial time set for RTC

            percentage sent to phone indicating progress
        */

    }
}
