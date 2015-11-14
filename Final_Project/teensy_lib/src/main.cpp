#include "WProgram.h"
#include "SPIFIFO.h"
#include "spi4teensy.h"

const int  cs=10; //chip select (for the RTC, can change to any ss pin)


extern "C"

#define Bluetooth Serial1 // using serial port 1 for bluetooth communication

// int RTC_init();
// int SetTimeDate(int d, int mo, int y, int h, int mi, int s);
// String ReadTimeDate();

int main(void) {
    Serial.begin(9600);     // initialize Serial for the RTC
    Bluetooth.begin(9600);  // initialize bluetooth at 9600 buad
    char c = 'a';
    int adcVal = 0;
    pinMode(A0,INPUT); // set analog pin 0 as input...pin14
    //pinMode(13, OUTPUT);
    uint32_t i = 0;

    // https://www.pjrc.com/teensy/td_libs_SPI.html
    // https://github.com/xxxajk/spi4teensy3  <----For a Teensy3 library
    //    SPIFIFOclass.begin(cs,);   // initialize SPI communication TODO pin configs for SPI

    while (1) {
        //Serial.println(ReadTimeDate());
        //delay(1000);
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
/*
int RTC_init(){
      pinMode(cs,OUTPUT); // chip select
      // start the SPI library:
      SPI.begin();
      SPI.setBitOrder(MSBFIRST);
      SPI.setDataMode(SPI_MODE3); // both mode 1 & 3 should work
      //set control register
      digitalWrite(cs, LOW);
      SPI.transfer(0x8E);
      SPI.transfer(0x60); //60= disable Osciallator and Battery SQ wave @1hz, temp compensation, Alarms disabled
      digitalWrite(cs, HIGH);
      delay(10);
}

int SetTimeDate(int d, int mo, int y, int h, int mi, int s){
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
        SPI.transfer(i+0x80);
        SPI.transfer(TimeDate[i]);
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
        SPI.transfer(i+0x00);
        unsigned int n = SPI.transfer(0x00);
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
