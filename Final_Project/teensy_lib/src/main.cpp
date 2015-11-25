#include "WProgram.h"
#include <spi4teensy.h>
#include <RTC_DS3234.h>

const int  cs = 10; //chip select (for the RTC, can change to any ss pin)


extern "C"

// void RTC_init();
// void SetTimeDate(int d, int mo, int y, int h, int mi, int s);
// String ReadTimeDate();

int main(void) {
    RTC_DS3234 doRTC;
    RTCDateTime time;
    Serial.begin(9600);     // initialize Serial for the RTC
    //Bluetooth.begin(9600);  // initialize bluetooth at 9600 buad
    //char c = 'a';
    //int adcVal = 0;
    //pinMode(A0,INPUT); // set analog pin 0 as input...pin14
    //pinMode(13, OUTPUT);
    //uint32_t i = 0;

    doRTC.begin(cs);
                       //ss, mm, hh, d, m, y
    doRTC.setRTCDateTime(0,  10, 8,  11,11,15);

    while(1){
        time = doRTC.getRTCDateTime();
        Serial.print("Hours: ");
        Serial.println(time.hours);
        Serial.print("Minutes: ");
        Serial.println(time.minutes);
        Serial.print("Seconds: ");
        Serial.println(time.seconds);

        delay(1000);
    }


    // while (1) {
    //     //Serial.println(ReadTimeDate());
    //     //delay(1000);
    //     if(Bluetooth.available() > 0) {
    //         c = Bluetooth.read();
    //         Bluetooth.print(c);
    //     }
    //     if(c == 'r') {
    //         adcVal = analogRead(0); // analog reading on A0
    //         Bluetooth.println(adcVal);
    //         c = 'a';
    //     }
    // }
}



/*
void RTC_init(){
      pinMode(cs,OUTPUT); // chip select
      // start the SPI library:
      spi4teensy3::init(0,0,1);
      //SPIFIFO.begin(cs,SPI_CLOCK_24MHz,SPI_MODE1);
      //SPI.begin();
      //SPI.setBitOrder(MSBFIRST);
      //SPI.setDataMode(SPI_MODE3); // both mode 1 & 3 should work
      //set control register
      digitalWrite(cs, LOW);
      spi4teensy3::send(0x8E);
      spi4teensy3::send(0x60);//60= disable Osciallator and Battery SQ wave @1hz, temp compensation, Alarms disabled
      //SPIFIFO.write(0x8E);
      //SPIFIFO.write(0x60);
      digitalWrite(cs, HIGH);
      delay(10);
}

void SetTimeDate(int d, int mo, int y, int h, int mi, int s){
    int TimeDate [7]={s,mi,h,0,d,mo,y};
    for(int i=0; i<=6;i++){
        if(i==3)
            i++;
        int b= TimeDate[i]/10;
        int a= TimeDate[i]-b*10;
        if(i==2){
            if (b==2)
                b=B00000010;
            else if (b==1)
                b=B00000001;
        }
        TimeDate[i]= a+(b<<4);

        digitalWrite(cs, LOW);

        spi4teensy3::send(i+0x80);
        spi4teensy3::send(TimeDate[i]);

        //SPIFIFO.write(i+0x80);
        //SPIFIFO.write(TimeDate[i]);
        //SPI.transfer(i+0x80);
        //SPI.transfer(TimeDate[i]);
        digitalWrite(cs, HIGH);
  }
}

String ReadTimeDate(){
    String temp;
    int TimeDate [7]; //second,minute,hour,null,day,month,year
    for(int i=0; i<=6;i++){
        if(i==3)
            i++;
        digitalWrite(cs, LOW);
        spi4teensy3::send(i+0x00);
        //SPIFIFO.write(i+0x00);
        //SPI.transfer(i+0x00);
        unsigned int n = spi4teensy3::receive();
        //unsigned int n = SPIFIFO.read();
        //unsigned int n = SPI.transfer(0x00);
        digitalWrite(cs, HIGH);
        int a=n & B00001111;
        if(i==2){
            int b=(n & B00110000)>>4; //24 hour mode
            if(b==B00000010)
                b=20;
            else if(b==B00000001)
                b=10;
            TimeDate[i]=a+b;
        }
        else if(i==4){
            int b=(n & B00110000)>>4;
            TimeDate[i]=a+b*10;
        }
        else if(i==5){
            int b=(n & B00010000)>>4;
            TimeDate[i]=a+b*10;
        }
        else if(i==6){
            int b=(n & B11110000)>>4;
            TimeDate[i]=a+b*10;
        }
        else{
            int b=(n & B01110000)>>4;
            TimeDate[i]=a+b*10;
            }
    }
    temp.concat(TimeDate[4]);
    temp.concat("/") ;
    temp.concat(TimeDate[5]);
    temp.concat("/") ;
    temp.concat(TimeDate[6]);
    temp.concat("     ") ;
    temp.concat(TimeDate[2]);
    temp.concat(":") ;
    temp.concat(TimeDate[1]);
    temp.concat(":") ;
    temp.concat(TimeDate[0]);
  return(temp);
}
*/









//Placeholder
