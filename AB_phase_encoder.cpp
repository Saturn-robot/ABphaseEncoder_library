#include "AB_phase_encoder.h"

void ABPhaseEncoder::initEncoder()
{
  // Set mode of pins to be INPUT
  pinMode(Apin, INPUT);
  pinMode(Bpin, INPUT);
  direction = true;
  duration = 0L;
  // Set which pin to use as interrupt port
  attachInterrupt(intNum, callISR, CHANGE);
}

void ABPhaseEncoder::callISR()
{
  ISRCaller->encoderISR();
}

void ABPhaseEncoder::encoderISR()
{
  int Lstate = digitalRead(Apin);
  if ((lastValue == LOW) && Lstate == HIGH)
  {
    int val = digitalRead(Bpin);
    if (val == LOW && direction)
    {
      direction = false;
    }
    else if (val == HIGH && !direction)
    {
      direction = true;
    }
  }
  lastValue = Lstate;

  if (!direction)
  {
    duration++;
  }
  else
  {
    duration--;
  }
}

long ABPhaseEncoder::readEncoder()
{
  return duration;
}

void ABPhaseEncoder::resetEncoder()
{
  duration = 0L;
}
