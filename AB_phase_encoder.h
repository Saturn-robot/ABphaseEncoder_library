#ifndef AB_PHASE_ENCODER_H
#define AB_PHASE_ENCODER_H

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

class ABPhaseEncoder
{
private:
  byte Apin;
  byte Bpin;
  //byte intPin;
  short int intNum;
  boolean direction;
  byte lastValue;
  static ABPhaseEncoder *ISRCaller;
  volatile long duration;
  static void callISR();
  void initEncoder();
  void encoderISR();
public:
  ABPhaseEncoder(byte Apin, byte Bpin, short int intNum)
                 : Apin(Apin),
                   Bpin(Bpin),
                   intNum(intNum)
  {
    ISRCaller = this;
    initEncoder();
  }
  long readEncoder();
  void resetEncoder();
};

#endif
