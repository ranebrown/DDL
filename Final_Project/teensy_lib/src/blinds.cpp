#include "blinds.h"

int currRot = 0;
int maxRot = 0;
int dir = 0;
RTC_DS3234 doRTC; // rtc class

// turn servo left
void left() {
	delay(100);
	analogWriteFrequency(A9, 270);
	analogWrite(A9,127);
	dir = 0;
}

// turn servo right
void right() {
	delay(100);
	analogWriteFrequency(A9, 600);  
	analogWrite(A9,127);
	dir = 1;
}

// stop servo
void stop() {
	delay(100);
	analogWrite(A9,0);
}

// count rotations
void rotCount() {
	if(dir == 1)
		currRot++;
	else 
		currRot--;
}

// set blinds open/close to given percentage
void setPerc(int p) {
	// IF GOING TO 100% CHECK CURRENT
	
	int x = (maxRot*p)/100;
	if(x > maxRot) {
		x = maxRot;
	}
	// fully open (or very close) so check current to be safe
	if(x >= maxRot-2 && x > currRot) {
	   right();
        // measure current drawn by motor to detect full open position
        while((analogRead(A2) - analogRead(A1)) < 150) {
        	if(currRot == maxRot)
        		break;
            delay(20);
        }
        stop();
	}
	// opening to set percentage
	else if(x > currRot) {
		right();
	  	while(currRot < x) {
            delay(10);
        }
        stop();
	}
	// closing to set percentage
	else if(x < currRot) {
		left();
		while(currRot > x) {
            delay(10);
        }
        stop();
	}
}

// initialize RTC
void initRTC(){
	// RTC interrupts
    attachInterrupt(rtcIP,rtc_isr1,FALLING);
    attachInterrupt(rtcIP,rtc_isr2,FALLING);

    doRTC.begin(cs);			// start rtc
    doRTC.clearAlarmFlags();	// clear alarms
}

// rtc ISR's
void rtc_isr1() {
	doRTC.clearAlarmFlags();
}
void rtc_isr2(){
	doRTC.clearAlarmFlags();
}

