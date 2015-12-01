#include "WProgram.h"
#include <spi4teensy.h>
#include <RTC_DS3234.h>
#include <avr/io.h>
#include <avr/interrupt.h>

RTC_DS3234 doRTC;

extern "C"
const int  cs = 10; //chip select (for the RTC, can change to any ss pin)
void led_isr1();
void led_isr2();

int main(void) {

    RTCDateTime time;
    Serial.begin(9600);     // initialize Serial for the RTC
    //Bluetooth.begin(9600);  // initialize bluetooth at 9600 buad
    //char c = 'a';
    //int adcVal = 0;
    //pinMode(A0,INPUT); // set analog pin 0 as input...pin14
    pinMode(23, OUTPUT);
    pinMode(3, INPUT);
    //uint32_t i = 0;

    digitalWrite(23,HIGH);
    delay(200);
    digitalWrite(23,LOW);
    delay(200);
    digitalWrite(23,HIGH);
    delay(200);
    digitalWrite(23,LOW);

    attachInterrupt(3,led_isr1,FALLING);
    attachInterrupt(4,led_isr2,FALLING);

    doRTC.begin(cs);
    doRTC.clearAlarmFlags();
                       //ss,  mm, hh, d, m, y
    doRTC.setRTCDateTime(00,  10, 8, 11,11,15);

                  //ss, mm, hh
    doRTC.setAlarm1(5, 10, 8);
    delay(10);
                  //mm, hh
    doRTC.setAlarm2(11, 8);
    delay(100);

    while(1){
        time = doRTC.getRTCDateTime();
        Serial.print("Hours: ");
        Serial.println(time.hours);
        Serial.print("Minutes: ");
        Serial.println(time.minutes);
        Serial.print("Seconds: ");
        Serial.println(time.seconds);
        digitalWrite(23,HIGH);
        delay(50);
        digitalWrite(23,LOW);

        delay(849);
    }
}

void led_isr1(){
    digitalWrite(23,HIGH);
    delay(150);
    digitalWrite(23,LOW);
    delay(150);
    digitalWrite(23,HIGH);
    delay(150);
    digitalWrite(23,LOW);
    doRTC.clearAlarmFlags();
}

void led_isr2(){
    digitalWrite(23,HIGH);
    delay(150);
    digitalWrite(23,LOW);
    delay(150);
    digitalWrite(23,HIGH);
    delay(150);
    digitalWrite(23,LOW);
    delay(150);
    digitalWrite(23,HIGH);
    delay(150);
    digitalWrite(23,LOW);
    doRTC.clearAlarmFlags();
}







//Placeholder
