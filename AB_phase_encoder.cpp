/*
 * AB phase encoder library, using to collect encoder data from encoder
 * Copyright (C) 2017  Liu Chaoyang
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 **/


#include "AB_phase_encoder.h"

ABPhaseEncoders* ABPhaseEncoders::ISRCaller = NULL;

void ABPhaseEncoders::initEncoder()
{
  // Set mode of pins to be INPUT
  pinMode(leftApin, INPUT);
  pinMode(leftBpin, INPUT);
  pinMode(rightApin, INPUT);
  pinMode(rightBpin, INPUT);
  leftDirect = true;  rightDirect = true;
  leftReversed = false;  rightReversed = false;
  leftDur = 0L;  rightDur = 0L;
  // Set which pins to use as interrupt port
  attachInterrupt(digitalPinToInterrupt(leftApin), callLeftISR, CHANGE);
  attachInterrupt(digitalPinToInterrupt(rightApin), callRightISR, CHANGE);
}

void ABPhaseEncoders::callLeftISR()
{
  ISRCaller->leftEncoderISR();
}

void ABPhaseEncoders::callRightISR()
{
  ISRCaller->rightEncoderISR();
}

void ABPhaseEncoders::leftEncoderISR()
{
  int Lstate = digitalRead(leftApin);
  if ((leftLastValue == LOW) && Lstate == HIGH)
  {
    int val = digitalRead(leftBpin);
    if (val == LOW && leftDirect)
    {
      leftDirect = false;
    }
    else if (val == HIGH && !leftDirect)
    {
      leftDirect = true;
    }
  }
  leftLastValue = Lstate;

  if (!leftDirect)
  {
    leftDur++;
  }
  else
  {
    leftDur--;
  }
}

void ABPhaseEncoders::rightEncoderISR()
{
  int Lstate = digitalRead(rightApin);
  if ((rightLastValue == LOW) && Lstate == HIGH)
  {
    int val = digitalRead(rightBpin);
    if (val == LOW && rightDirect)
    {
      rightDirect = false;
    }
    else if (val == HIGH && !rightDirect)
    {
      rightDirect = true;
    }
  }
  rightLastValue = Lstate;

  if (!rightDirect)
  {
    rightDur++;
  }
  else
  {
    rightDur--;
  }
}

long ABPhaseEncoders::readEncoder(int i)
{
  if (i == LEFT)
  {
    return leftReversed ? -leftDur : leftDur;
  }
  else
  {
    return rightReversed ? -rightDur : rightDur;
  }
}

void ABPhaseEncoders::resetEncoder(int i)
{
  if (i == LEFT)
  {
    leftDur = 0L;
  }
  else
  {
    rightDur = 0L;
  }
}

void ABPhaseEncoders::resetEncoders()
{
  resetEncoder(0);
  resetEncoder(1);
}

void ABPhaseEncoders::leftReverse()
{
  leftReversed = !leftReversed;
}

void ABPhaseEncoders::rightReverse()
{
  rightReversed = !rightReversed;
}
