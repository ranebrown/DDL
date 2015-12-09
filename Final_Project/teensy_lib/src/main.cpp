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
	pinMode(22,OUTPUT); // test led for rtc

    // buffer for recieved/sent commands
    char rxBuff[5] = "empt";
    //char txBuff[5] = "empt";
    int i = 0;
    //int j = 0;
    int *indRX = &i;
    //int *indTX = &j;
    
    int myP = 0;            // used for testing the set percentage to open/close

    // Interrupt from read switch to track blinds position
    attachInterrupt(2, rotCount, FALLING);    

    initRTC(); // initialize real time clock
    // //                     //ss,  mm, hh, d, m, y
    doRTC.setRTCDateTime(45,  9, 8, 11,11,15);     
                  //ss, mm, hh
    doRTC.setAlarm1(1, 1, 1);
    delay(10);
                  //mm, hh
    doRTC.setAlarm2(1, 1);
    delay(10);

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
            Bluetooth.print(c);
            if(i < 5) {
                rxBuff[i] = c;
                i++;
            }
        }

        // parse command
        if(i == 5) {
            int x = parse(rxBuff, indRX);
            if(x == 1) {
                // bad command in buffer - tell phone to resend last command
                int tmp=0;
                while(tmp<5) {
                    Bluetooth.print('r');
                    tmp++;
                }
            }
        }

        // poll open/close flags
        if(openF == 1)
            setPerc(100);
        if(closeF == 1)
            setPerc(0);


/************** BELOW IS FOR TESTING PURPOSES ****************************************************/

        // grab command
        if(Serial.available() > 0) {
            c = Serial.read();
        }

        // print buffer
        // if(c == 'p') {
        //     for(i = 0; i < 5; i++) {
        //         Serial.print(rxBuff[i]);
        //     }
        //     i = 0;
        //     c = 'a';
        // }

        // set percentage to open/close
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
        
        // manual movement
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

        // print stored rotations
        if(c=='q') {
            Serial.print("max: ");
            Serial.println(maxRot);
            Serial.print("curr: ");
            Serial.println(currRot);
            c = 'a';
        }

        if(c=='z') {
            int x = 100;
            Serial.println(x);
            Bluetooth.print(x);
            c='a';
        }
    }
}
