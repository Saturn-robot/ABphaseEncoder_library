/* *******************************************************************
   Encoder driver function definitions by Chaoyang Liu
   ***************************************************************** */
#include "encoder_driver.h"

// variables to store the number of encoder pulses
// for each motor
volatile unsigned long fleftCount = 0;
volatile unsigned long frightCount = 0;
volatile unsigned long bleftCount = 0;
volatile unsigned long brightCount = 0;

  /* Wrap the encoder initializeing to be run in the main setup() function */
  void initEncoders() {
    pinMode(FLH_ENCODER_A, INPUT);
    pinMode(FLH_ENCODER_B, INPUT);
    pinMode(BRH_ENCODER_A, INPUT);
    pinMode(BRH_ENCODER_B, INPUT);
    pinMode(FRH_ENCODER_A, INPUT);
    pinMode(FRH_ENCODER_B, INPUT);
    pinMode(BLH_ENCODER_A, INPUT);
    pinMode(BLH_ENCODER_B, INPUT);

    // initialize hardware interrupts
    attachInterrupt(4, fleftEncoderEvent, CHANGE);
    attachInterrupt(5, frightEncoderEvent, CHANGE);
    attachInterrupt(3, bleftEncoderEvent, CHANGE);
    attachInterrupt(2, brightEncoderEvent, CHANGE);

    Serial.begin(57600);
  }

  // encoder event for the interrupt call
  void fleftEncoderEvent() {
    if (digitalRead(FLH_ENCODER_A) == HIGH) {
      if (digitalRead(FLH_ENCODER_B) == LOW) {
        fleftCount++;
      }
      else {
        fleftCount--;
      }
    }
    else {
      if (digitalRead(FLH_ENCODER_B) == LOW) {
        fleftCount--;
      }
      else {
        fleftCount++;
      }
    }
  }

  // encoder event for the interrupt call
  void frightEncoderEvent() {
    if (digitalRead(FRH_ENCODER_A) == HIGH) {
      if (digitalRead(FRH_ENCODER_B) == LOW) {
        frightCount++;
      }
      else {
        frightCount--;
      }
    }
    else {
      if (digitalRead(FRH_ENCODER_B) == LOW) {
        frightCount--;
      }
      else {
        frightCount++;
      }
    }
  }

  void bleftEncoderEvent() {
    if (digitalRead(BLH_ENCODER_A) == HIGH) {
      if (digitalRead(BLH_ENCODER_B) == LOW) {
        bleftCount++;
      }
      else {
        bleftCount--;
      }
    }
    else {
      if (digitalRead(BLH_ENCODER_B) == LOW) {
        bleftCount--;
      }
      else {
        bleftCount++;
      }
    }
  }

  // encoder event for the interrupt call
  void brightEncoderEvent() {
    if (digitalRead(BRH_ENCODER_A) == HIGH) {
      if (digitalRead(BRH_ENCODER_B) == LOW) {
        brightCount++;
      }
      else {
        brightCount--;
      }
    }
    else {
      if (digitalRead(BRH_ENCODER_B) == LOW) {
        brightCount--;
      }
      else {
        brightCount++;
      }
    }
  }

long readEncoder(int i) {
    if (i == FLEFT)
      return fleftCount;
    else if (i == FRIGHT)
      return frightCount;
    else if (i == BLEFT)
      return bleftCount;
    else
      return brightCount;
  }

  /* Wrap the encoder reset function */
  void resetEncoder(int i) {
    if (i == FLEFT) {
      fleftCount = 0L;
      return;
    }
    else if (i == FRIGHT) {
      frightCount = 0L;
      return;
    }
    else if (i == BLEFT) {
      bleftCount = 0L;
      return;
    }
    else {
      brightCount = 0L;
      return;
    }
  }

/* Wrap the encoder reset function */
void resetEncoders() {
  resetEncoder(FLEFT);
  resetEncoder(FRIGHT);
  resetEncoder(BLEFT);
  resetEncoder(BRIGHT);
}
