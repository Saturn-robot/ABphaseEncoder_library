/* *******************************************************************
   Encoder driver function definitions by Chaoyang Liu
   ***************************************************************** */
#include "encoder_driver.h"

// variables to store the number of encoder pulses
// for each motor
volatile long left_enc_pos = 0L;
volatile long right_enc_pos = 0L;

void initEncoders()
{
    pinMode(LEFT_ENC_A, INPUT);
    pinMode(LEFT_ENC_B, INPUT);
    pinMode(RIGHT_ENC_A, INPUT);
    pinMode(RIGHT_ENC_B, INPUT);

    attachInterrupt(0, leftEncoderEvent, CHANGE);
    attachInterrupt(1, rightEncoderEvent, CHANGE);
}

  // encoder event for the interrupt call
void leftEncoderEvent()
{
    if (digitalRead(LEFT_ENC_A) == HIGH)
    {
      if (digitalRead(LEFT_ENC_B) == LOW)
      {
        left_enc_pos++;
      }
      else
      {
        left_enc_pos--;
      }
    }
    else
    {
      if (digitalRead(LEFT_ENC_B) == LOW)
      {
        left_enc_pos--;
      }
      else
      {
        left_enc_pos++;
      }
    }
}

// encoder event for the interrupt call
void rightEncoderEvent()
{
    if (digitalRead(RIGHT_ENC_A) == HIGH)
    {
      if (digitalRead(RIGHT_ENC_B) == LOW)
      {
        right_enc_pos++;
      }
      else
      {
        right_enc_pos--;
      }
    }
    else
    {
      if (digitalRead(RIGHT_ENC_B) == LOW)
      {
        right_enc_pos--;
      }
      else
      {
        right_enc_pos++;
      }
    }
}

/* Wrap the encoder reading function */
long readEncoder(int i)
{
    if (i == LEFT) return left_enc_pos;
    else return -right_enc_pos;    // It's just because my right encoder get reverse value so if yours is normal, don't add "-"
}

/* Wrap the encoder reset function */
void resetEncoder(int i)
{
    if (i == LEFT)
    {
      left_enc_pos=0L;
      return;
    }
    else
    {
      right_enc_pos=0L;
      return;
    }
}

/* Wrap the encoder reset function */
void resetEncoders()
{
    resetEncoder(LEFT);
    resetEncoder(RIGHT);
}
