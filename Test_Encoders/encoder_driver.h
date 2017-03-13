/* *******************************************************************
   Encoder driver function declarations by Chaoyang Liu
   ***************************************************************** */
#include "command.h"
  //below can be changed, but should be PORTD pins;
  //otherwise additional changes in the code are required
  #define FRH_ENCODER_A 18
  #define FRH_ENCODER_B 22
  #define BRH_ENCODER_A 21
  #define BRH_ENCODER_B 24
  #define FLH_ENCODER_A 19
  #define FLH_ENCODER_B 23
  #define BLH_ENCODER_A 20
  #define BLH_ENCODER_B 25

void fleftEncoderEvent();
void frightEncoderEvent();
void bleftEncoderEvent();
void brightEncoderEvent();

void initEncoders();
long readEncoder(int i);
void resetEncoder(int i);
void resetEncoders();
