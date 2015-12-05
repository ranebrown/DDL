#ifndef BLINDS_H
#define BLINDS_H

#include "WProgram.h"
#include <spi4teensy.h>
#include <RTC_DS3234.h>
#include <avr/io.h>
#include <avr/interrupt.h>


#define Bluetooth Serial1   // using serial port 1 for bluetooth communication
#define start 19            // pin connected to button to initialize system
#define reedS 2             // read switch used to detect # of rotations
#define motor 19            // pin connected to motor pwm signal
#define rtcIP 3          	// pin used for interrupt from RTC
const int  cs = 10;         // chip select (for the RTC, can change to any ss pin)

// variables used in blinds.cpp and in main.cpp
extern RTC_DS3234 doRTC; 	// rtc class
extern int currRot;
extern int maxRot;
extern int dir;

// turn servo left
void left();

// turn servo right
void right();

// stop servo
void stop();

// count rotations
void rotCount();

// set blinds open/close to given percentage
void setPerc(int p);

// initialize RTC
void initRTC();

// rtc ISR's
void rtc_isr1();
void rtc_isr2();

// parse buffer for a command
	/*
	s0000 initial rtc time
	o0000 set open time
	c0000 set close time
	p0000 percentage to open 
	*/
	// return 0 success, 1 bad command in buffer
int parse(char *buff, int *ind);

#endif