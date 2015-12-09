#include "blinds.h"

int currRot = 0;
int maxRot = 0;
int dir = 0;
RTC_DS3234 doRTC; // rtc class
int openF = 0;
int closeF = 0;

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
	/************** TODO -- send current percentage back to phone ***********/
	
	int x = (maxRot*p)/100;
	float currP = currRot/maxRot;
	if(x > maxRot) {
		x = maxRot;
	}
	// fully open (or very close) so check current to be safe
	if(x >= maxRot-2 && x > currRot) {
	   right();
        // measure current drawn by motor to detect full open position
        while((analogRead(A2) - analogRead(A1)) < 150) {
        	currP = 100*currRot/maxRot;
			Serial.println(currP);
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
	openF = 0;
	closeF = 0;
}

// initialize RTC
void initRTC() {
	// RTC interrupts
    attachInterrupt(rtcIP,rtc_isr1,FALLING);
    doRTC.begin(cs);			// start rtc
    doRTC.clearAlarmFlags();	// clear alarms
}

// rtc ISR's
void rtc_isr1() {
	RTCDateTime time = doRTC.getRTCDateTime();
	RTCDateTime alarm1 = doRTC.getAlarm1();
	if(time.minutes == alarm1.minutes && time.hours == alarm1.hours) {
		Serial.println("in int open");
		openF = 1;
	}
	else {
		Serial.println("in int close");
		closeF = 1;
	}
	doRTC.clearAlarmFlags();
}

// parse buffer for a command
	/*
	s0000 initial rtc time
	o0000 set open time
	c0000 set close time
	p0000 percentage to open 
	*/
int parse(char *buff, int *ind) {
	char cmd = buff[0];
	int min=0, hour=0;
	int p = 0;

	// convert chars in buffer to ints
	uint8_t d1,d2,d3,d4;
	d1 = buff[1] - '0';
	d2 = buff[2] - '0';
	d3 = buff[3] - '0';
	d4 = buff[4] - '0';
	RTCDateTime time;
	switch(cmd) {
		case 's': // set initial rtc date and time
			Serial.println("s");
			d1 = d1*10;
			hour = d1+d2;
			d3 = d3*10;
			min = d3+d4;
			delay(10);
			Serial.print(hour);
			Serial.print("  ");
			Serial.println(min);
							   //ss,  mm,  hh,   d, m,  y
    		doRTC.setRTCDateTime(00,  min, hour, 8, 12, 15);
    		*ind = 0; // reset buffer index to 0
    		return 0;
			break;
		case 'o': // set time to open blinds
			d1 = d1*10;
			hour = d1+d2;
			d3 = d3*10;
			min = d3+d4-1;
			delay(10);
		              	//ss, mm, hh
    		doRTC.setAlarm1(0, min, hour);
    		time = doRTC.getAlarm1();
			Serial.print(time.hours);
			Serial.print("  ");
			Serial.println(time.minutes);
    		*ind = 0; // reset buffer index to 0
    		return 0;
			break;
		case 'c':	// set time to close blinds
			Serial.println("c");
			d1 = d1*10;
			hour = d1+d2;
			d3 = d3*10;
			min = d3+d4;
			Serial.print(hour);
			Serial.print("  ");
			Serial.println(min);
		              	// mm, hh
			delay(10);
    		doRTC.setAlarm2(min, hour);
    		*ind = 0; // reset buffer index to 0
    		return 0;
			break;
		case 'p':	// set blind position to specific percentage
			Serial.println('p');
			d2 = d2*100;
			d3 = d3*10;
			p = d2+d3+d4;
			setPerc(p);
			*ind = 0; // reset buffer index to 0
			return 0;
			break;
		default: // bad command in buffer
			*ind = 0; // reset buffer index to 0
			return 1;
			break;
	}
}


