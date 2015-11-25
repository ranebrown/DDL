//Written by Schuyler Senft-Grupp skysg@mit.edu
//3/27/12
//Feel free to use this code however you wish!
//I've changed this line

#include "RTC_DS3234.h"
#include "SPI.h"
//#include "SPIFIFO.h"

RTC_DS3234 RTC;

//RTC DS3234 register addresses
const uint8_t DT_READ = 0x00;
const uint8_t DT_WRITE = 0x80;
const uint8_t A1_READ = 0x07;
const uint8_t A1_WRITE = 0x87;
const uint8_t A2_READ = 0x0B;
const uint8_t A2_WRITE = 0x8B;
const uint8_t CONTROL_READ = 0x0E;
const uint8_t CONTROL_WRITE = 0x8E;
const uint8_t STATUS_READ = 0x0F;
const uint8_t STATUS_WRITE = 0x8F;

//RTC DS3234 register bit functions
const uint8_t A1IE = 0;
const uint8_t A2IE = 1;
const uint8_t INTCN = 3;
const uint8_t A1F = 0;
const uint8_t A2F = 1;


//function to initialize the RTC
//this should be called before any other functions
void RTC_DS3234::begin(uint8_t cs){
	_cs = cs;
	pinMode(_cs, OUTPUT);				//set chip select pin as output
	digitalWrite(_cs, HIGH); 			//set chip select high to disable SPI communications
	dataArray[0] = 0b00000101; 	//{_BV(INTCN) | _BV(A1IE)};
	readWrite(CONTROL_WRITE, 1); 	//Write to control register to turn on alarm 1 interrupts
	delay(10);							//not sure this is necessary
}

//Set the RTC date and time
//This should rarely be necessary
void RTC_DS3234::setRTCDateTime(uint8_t ss, uint8_t mm, uint8_t hh, uint8_t d, uint8_t m, uint8_t y){
	dataArray[0] = bin2bcd(ss);
	dataArray[1] = bin2bcd(mm);
	dataArray[2] = bin2bcd(hh);
	dataArray[3] = 1;
	dataArray[4] = bin2bcd(d);
	dataArray[5] = bin2bcd(m);
	dataArray[6] = bin2bcd(y);
	readWrite(DT_WRITE, 7);
}

//read the date and time from the RTC
//data is returned in a RTCDateTime struct (see header file)
RTCDateTime RTC_DS3234::getRTCDateTime(){
	readWrite(DT_READ, 7);
	return (RTCDateTime) {bcd2bin(dataArray[0]), bcd2bin(dataArray[1]),
							bcd2bin(dataArray[2]), bcd2bin(dataArray[4]),
							bcd2bin(dataArray[5]), bcd2bin(dataArray[6])};
}

//sets Alarm1 on the RTC
//the alarm interrupt pin will go low when the RTC seconds/minutes/hours matches the values ss, mm, hh
//after the alarm has been triggered, the user must call clearAlarmFlags to manually reset the pin to high
void RTC_DS3234::setAlarm1(uint8_t ss, uint8_t mm, uint8_t hh){
	dataArray[0] = bin2bcd(ss);
	dataArray[1] = bin2bcd(mm);
	dataArray[2] = bin2bcd(hh);
	dataArray[3] = 0b10000000;
	readWrite(A1_WRITE, 4);
}

//returns the value that Alarm1 is set to
RTCDateTime RTC_DS3234::getAlarm1(){
	readWrite(A1_READ, 4);
	return (RTCDateTime) {bcd2bin(dataArray[0]), bcd2bin(dataArray[1]), bcd2bin(dataArray[2]), dataArray[3],0,0};
}

//clears the alarm flags in the status register
//this function should be called once soon after the call to begin()
//and MUST be called after the alarm is triggered in order to allow the alarm to be triggered again in the future
void RTC_DS3234::clearAlarmFlags(){
	readWrite(STATUS_READ, 1); 			//read the value of the status register
	dataArray[0] = dataArray[0] & ~(_BV(A1F) | _BV(A2F)); //set only the alarm flags back to zero without changing any of the other bits
	readWrite(STATUS_WRITE, 1);			//write the new status register
}

//simultaneously reads and writes to the RTC
//the values in dataArray are written to the RTC, and the bytes read are stored in dataArray
void RTC_DS3234::readWrite(uint8_t address, uint8_t dataLength){
	oldSPISettings = SPCR; //store the old SPI control register settings
	SPI.setBitOrder(MSBFIRST); //Set the SPI settings for the DS3234
	SPI.setDataMode(SPI_MODE1);

	digitalWrite(_cs, LOW);	//Enable the device for communication
	SPI.transfer(address);	//Send the register address to read/write to

	for(uint8_t i = 0; i<dataLength; i++){
		dataArray[i] = SPI.transfer(dataArray[i]); //Read/write all values in array
	}

	digitalWrite(_cs, HIGH); //Disable the device for SPI communication
	SPCR = oldSPISettings;  //Reset the SPI settings
}

//convert binary coded decimal to binary
uint8_t RTC_DS3234::bcd2bin (uint8_t val)
{
    return val - 6 * (val >> 4);
}

//convert binary to binary coded decimal
uint8_t RTC_DS3234::bin2bcd (uint8_t val)
{
    return val + 6 * (val / 10);
}
