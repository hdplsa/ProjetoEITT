#ifndef LEDNOTIFIER_H_INCLUDED
#define LEDNOTIFIER_H_INCLUDED

class LEDNotifier{
  //Pino do LED
  int LEDPin;
  
public:
  LEDNotifier(int LEDPin);
  void turnON();
  void turnOFF();
  ~LEDNotifier();
  
};


#endif
