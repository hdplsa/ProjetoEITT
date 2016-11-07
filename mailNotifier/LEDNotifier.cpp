#include "LEDNotifier.h"

LEDNotifier::LEDNotifier(int LEDPin){
  this->LEDPin = LEDPin;
  pinMode(this->LEDPin[n], OUTPUT);
}

void LEDNotifier::turnON(){
  digitalWrite(this->LEDPin, HIGH);
}

void LEDNotifier::turnOFF(){
  digitalWrite(this->LEDPin, LOW);
}

LEDNotifier::~LEDNotifier(){
  
}

