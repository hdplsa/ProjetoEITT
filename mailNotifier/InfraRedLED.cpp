#include "InfraRedLED.h"


InfraRedLED::InfraRedLED(int NLED){
  int n;
  
  this->NLED = NLED;
  for(n=0; n<NLED; n++){
    pinMode(this->LEDPin[n], OUTPUT);
  }
}

void InfraRedLED::turnLEDON(int LEDPin){
  digitalWrite(LEDPin, HIGH);
}

void InfraRedLED::turnAllON(){
  int n;
  // Acende todos os LEDs
  for(n=0; n<NLED; n++){
    turnLEDON(this->LEDPin[n]);
  }
}

void InfraRedLED::turnLEDOFF(int LEDPin){
  digitalWrite(LEDPin, LOW);
}

void InfraRedLED::turnAllOFF(){
  int n;
  // Acende todos os LEDs
  for(n=0; n<NLED; n++){
    turnLEDOFF(this->LEDPin[n]);
  }
}

InfraRedLED::~InfraRedLED(){
  
}
