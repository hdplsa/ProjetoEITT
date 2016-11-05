#ifndef NOTIFIER_H_INCLUDED
#define NOTIFIER_H_INCLUDED

#include "Arduino.h"
#include "InfraRedLED.h"
#include "InfraRedSensor.h"

enum NotificationType {PiscaLED, GSM};

class Notifier{
  //Tipo de notificador, definido logo à partida
  NotificationType type;
  //Ponteiros para LEDs e Sensores de forma a obter dados
  InfraRedLED *ifLED;
  InfraRedSensor *ifSensor;

public:
  Notifier(NotificationType type);
  int testMailBox();
  ~Notifier();
};

#endif
