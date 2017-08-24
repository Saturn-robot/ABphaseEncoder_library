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

#ifndef AB_PHASE_ENCODER_H
#define AB_PHASE_ENCODER_H

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#define LEFT 1
#define RIGHT 0

class ABPhaseEncoders
{
private:
  static ABPhaseEncoders *ISRCaller;
  // Two pins of left encoder:A output & B output
  byte leftApin;  byte leftBpin;
  // Two pins of left encoder:A output & B output
  byte rightApin;  byte rightBpin;
  // Recording rotation directions of encoders
  boolean leftDirect;  boolean rightDirect;
  // If value of encoders is reversed, just reverse them
  boolean leftReversed;  boolean rightReversed;
  // Recording value of pins
  byte leftLastValue;  byte rightLastValue;
  // Recording counts of encoders
  volatile long leftDur;  volatile long rightDur;
  void initEncoder();
  // Parameters of arduino built-in function, used to call ISR.
  static void callLeftISR();
  static void callRightISR();
  // ISRs of encoders
  void leftEncoderISR();
  void rightEncoderISR();
public:
  ABPhaseEncoders(byte leftApin, byte leftBpin, byte rightApin, byte rightBpin)
                 : leftApin(leftApin), leftBpin(leftBpin),
                   rightApin(rightApin), rightBpin(rightBpin)
  {
    ISRCaller = this;
    initEncoder();
  }
  long readEncoder(int i);
  // Clear count of encoder
  void resetEncoder(int i);
  // Clear count of encoders
  void resetEncoders();
  // // When you get reversed value, just reverse it
  void leftReverse();
  void rightReverse();
};

#endif
