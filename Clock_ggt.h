#ifndef Clock_ggt_h
#define Clock_ggt_h

class Clock {
  private:
    byte minuteOnes = 0;
    byte minuteTens = 0;
    byte hourOnes = 8;
    byte hourTens = 0;

    bool is12hr = false;

    unsigned long previousMillisClockUpdate = 0;
    
  public:
    Clock();

    byte getHourTens();
    byte getHourOnes();
    byte getMinuteTens();
    byte getMinuteOnes();
    void setHourTens(byte);
    void setHourOnes(byte);
    void setMinuteTens(byte);
    void setMinuteOnes(byte);

    byte getHour();
    byte getMinute();
    byte getSecond();
    void setHour(byte);
    void setMinute(byte);
    
    void set12hr();

    void increment(unsigned long);
};  
#endif
