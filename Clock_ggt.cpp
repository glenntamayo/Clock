#include <Arduino.h>
#include "Clock_ggt.h"
#include <Timer.h>

#if 1
#define DEBUGCK
#else
#define DEBUGCK(a)
#endif

Clock::Clock() {
}

void Clock::increment(unsigned long updateTime) {
  unsigned long currentMillis = millis();
  if ((currentMillis - previousMillisClockUpdate) > updateTime) {
    byte _hour = hourTens * 10 + hourOnes;
		byte _minute = minuteTens * 10 + minuteOnes;
    if (_minute < 59) {
      _minute++;
    } else {
			_minute = 0;	  
			if (_hour < 23) {
				_hour++;
			} else {      
				_hour = 0;
			}
    }
		setHour(_hour);
		setMinute(_minute);
		previousMillisClockUpdate = currentMillis;
  }
}

byte Clock::getHourTens() {
  return hourTens;  
}

byte Clock::getHourOnes() {
  return hourOnes;  
}

byte Clock::getMinuteTens() {
  return minuteTens;
}

byte Clock::getMinuteOnes() {
  return minuteOnes;
}

void Clock::setHourTens(byte _hourTens) {
  hourTens = _hourTens;  
}

void Clock::setHourOnes(byte _hourOnes) {
  hourOnes = _hourOnes;  
}

void Clock::setMinuteTens(byte _minuteTens) {
  minuteTens = _minuteTens;
}

void Clock::setMinuteOnes(byte _minuteOnes) {
  minuteOnes = _minuteOnes;
}

byte Clock::getHour() {
  byte _hour = hourTens * 10 + hourOnes;
  if (is12hr){
		if (_hour == 0){
			return 12;		
		}else if(_hour > 12){
			return _hour -12;
		} else {
			return _hour;
		}
  } else{
	return _hour;
  }
}

byte Clock::getMinute() {
  return minuteTens * 10 + minuteOnes;  
}

void Clock::setHour(byte _hour) {
  hourTens = _hour / 10;
  hourOnes = _hour % 10;
}

void Clock::setMinute(byte _minute) {
  minuteTens = _minute / 10;
  minuteOnes = _minute % 10;  
}

void Clock::set12hr() {
  is12hr = true;  
}
