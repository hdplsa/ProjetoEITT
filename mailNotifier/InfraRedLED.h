#ifndef INFRAREDLED_H_INCLUDED
#define INFRAREDLED_H_INCLUDED

#include "Arduino.h"

class InfraRedLED{
  int NLED;
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
