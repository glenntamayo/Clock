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
      
    if (minuteOnes < 9) {
      minuteOnes++;
    } else {
      minuteOnes = 0;
      if (minuteTens < 5) {
        minuteTens++;
      } else {
        minuteTens = 0;
        if (hourTens == 1 && hourOnes == 2) {
          hourOnes = 1;
          hourTens = 0;
        } else {      
          if (hourOnes < 9) {
            hourOnes++; 
          } else {
            hourOnes = 0;
            hourTens = 1;
          }
        }
      }
    }
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
  if ((is12hr) && (hourTens > 0) && (hourOnes > 2)){
	hourTens = hourTens - 1;
	hourOnes = hourOnes - 2;
  }
  if ((hourTens == 0) && (hourOnes == 0)){
	hourTens = 1;
	hourOnes = 2;		
  }
  return hourTens * 10 + hourOnes;
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
 /* 
  Serial.print(minuteTens);
  Serial.print(" : ");
  Serial.println(minuteOnes);
  */
  
}
/*
void Clock::setSecond(byte _second) {
  second = _second;  
}
*/
/*
void Clock::incrementDigit(int digitFocus, int increment) {
  int i;
  int j;
  switch (digitFocus) {
  case 0:
    i = minuteOnes + increment;
    switch (i) {
    case -1:
      minuteOnes = 9;
      break;
    case 10:
      minuteOnes = 0;
      break;
    default:  
      minuteOnes = i;
    }
    minuteChanged = true;
    break;
  case 1:
    i = minuteTens + 1;
    switch (i) {
    case -1:
      minuteTens = 5;
      break;
    case 6:
      minuteTens = 0;
      break;
    default:
      minuteTens = i;
    }
    minuteChanged = true;
    break;
  case 2:
    i = hourOnes + increment;
    j = hourTens;
    switch (j) {
    case 0:
      switch (i) {
      case 0:
        hourOnes = 2;
        hourTens = 1;
        break;
      case 10:
        hourOnes = 0;
        hourTens = 1;
        break;
      default:
        hourOnes = i;
      }
      break;
    case 1:
      switch (i) {
      case -1:
        hourOnes = 9;
        hourTens = 0;
        break;
      case 0:
        hourOnes = 0;
        hourTens = 1;
        break;
      case 3:
        hourOnes = 1;
        hourTens = 0;
        break;
      default:
        hourOnes = i;
      }
      break;
    }
    hourChanged = true;
    break;
  }
}
*/
void Clock::set12hr() {
  is12hr = true;  
}
