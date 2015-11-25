//Written by Schuyler Senft-Grupp skysg@mit.edu
//3/27/12
//Feel free to use this code however you wish!

//This library makes several assumptions and does not take full advantage of all the RTC DS3234 features.
//Below is a list of some of these limitations:
// 1. times are all assumed to be 24 hours (i.e. no AM/PM)
// 2. there are several alarm modes - the only one implemented here is a match with seconds/minutes/hours
// 3. only Alarm1 can be set

#ifndef __RTC_DS3234_H__
#define __RTC_DS3234_H__

#include <stdio.h>
#include <stdint.h>

typedef struct {
	uint8_t seconds, minutes, hours, days, months, year;
}RTCDateTime;

class RTC_DS3234{
public:
	void begin(uint8_t cs);
	void setRTCDateTime(uint8_t ss, uint8_t mm, uint8_t hh, uint8_t d, uint8_t month, uint8_t year);
	RTCDateTime getRTCDateTime();
	void setAlarm1(uint8_t ss, uint8_t mm, uint8_t hh);
	RTCDateTime getAlarm1();
	void clearAlarmFlags();

private:
	uint8_t _cs;
	uint8_t dataArray [7];
	uint8_t oldSPISettings;

	void readWrite(uint8_t address, uint8_t dataLength);
	uint8_t bcd2bin (uint8_t val);
	uint8_t bin2bcd (uint8_t val);

};

extern RTC_DS3234 RTC;

#endif // __RTC_DS3234_H__
