#include "blinds.h"

extern "C"

int main(void) {
    Bluetooth.begin(9600);  // bluetooth serial comms
    Serial.begin(9600);     // usb serial for testing purposes
    char c = 'a';           // variable for manual control (testing purposes)

    // gpio setup
    pinMode(motor,OUTPUT);
    pinMode(start,INPUT); 
    pinMode(reedS,INPUT);
    pinMode(rtcIP,INPUT);

    // buffer for recieved/sent commands
    char buff[10];
    int index = 0;
    
    int myP = 0;            // used for testing the set percentage to open/close

    // Interrupt from read switch to track blinds position
    attachInterrupt(2, rotCount, FALLING);    

    initRTC(); // initialize real time clock

    /* RTC functions
    doRTC.setRTCDateTime(00,  10, 8, 11,11,15);
                  //ss, mm, hh
    doRTC.setAlarm1(5, 10, 8);
                  //mm, hh
    doRTC.setAlarm2(11, 8);  
    */            

    while (1) {
        // check if start button pressed
        if(digitalRead(start) == 0) {
            currRot = 0;
            right();
            // measure current drawn by motor to detect full open position
            while((analogRead(A2) - analogRead(A1)) < 150) {
                delay(50);
            }
            stop();
            maxRot = currRot; // stores the rotation count to reach fully open position
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

        // manual movement - testing
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
            Serial.print("max: ");
            Serial.println(maxRot);
            Serial.print("curr: ");
            Serial.println(currRot);
            c = 'a';
        }

        // s0000 initial rtc time
        // p0000 percentage to open 
        // o0000 set open time
        // c0000 set close time
        // send current percentage back to phone
    }
}
