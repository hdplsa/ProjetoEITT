#ifndef INFRAREDLED_H_INCLUDED
#define INFRAREDLED_H_INCLUDED

#include "Arduino.h"

class InfraRedLED{
  //Numero de LEDs infravermelhos
  int NLED;
  //Pins dos LEDs
  int LEDPin[3];

public:
  InfraRedLED(int NLED);
  void turnLEDON(int LEDPin);
  void turnAllON();
  void turnLEDOFF(int LEDPin);
  void turnAllOFF();
  ~InfraRedLED();
};

#endif
