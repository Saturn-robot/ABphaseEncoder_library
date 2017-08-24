#include <AB_phase_encoder.h>

#define LEFT_ENC_A 2    // interrupt port 0
#define LEFT_ENC_B 22
#define RIGHT_ENC_A 3   // interrupt port 1
#define RIGHT_ENC_B 24

ABPhaseEncoders encoders(RIGHT_ENC_A, RIGHT_ENC_B, LEFT_ENC_A, LEFT_ENC_B);

void setup()
{
  Serial.begin(57600);
  // When you get reversed value, just reverse it
  encoders.rightReverse();
}

void loop()
{
  Serial.print("Left:");
  // Macro 'LEFT' means left encoder
  Serial.println(encoders.readEncoder(LEFT));
  Serial.print("Right:");
  // Macro 'RIGHT' means RIGHT encoder
  Serial.println(encoders.readEncoder(RIGHT));
}
