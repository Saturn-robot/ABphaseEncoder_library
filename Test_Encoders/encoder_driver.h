/* *******************************************************************
   Encoder driver function declarations by Chaoyang Liu
   ***************************************************************** */
#include "command.h"
  //below can be changed, but should be PORTD pins;
  //otherwise additional changes in the code are required
#define LEFT_ENC_A 2
#define LEFT_ENC_B 22
#define RIGHT_ENC_A 3
#define RIGHT_ENC_B 24

void initEncoders();
void leftEncoderEvent();
void rightEncoderEvent();

long readEncoder(int i);
void resetEncoder(int i);
void resetEncoders();
