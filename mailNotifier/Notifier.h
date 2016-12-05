#ifndef NOTIFIER_H_INCLUDED
#define NOTIFIER_H_INCLUDED

#include "Arduino.h"
#include "InfraRedLED.h"
#include "InfraRedSensor.h"
#include "LEDNotifier.h"
#include "GSMNotifier.h"

enum NotificationType {PiscaLED, GSM, BOTH};

class Notifier{
  //Tipo de notificador, definido logo à partida
  NotificationType type;
  //Ponteiros para LEDs e Sensores de forma a obter dados
  InfraRedLED *ifLED;
  InfraRedSensor *ifSensor;
  //Notificadores
  LEDNotifier *piscaLED;
  GSMNotifier *gsm;

  /* Este inteiro diz se já notificamos o utilizador
   * serve especialmente para o caso do GSM em que 
   * não queremos notificar mais do que uma vez caso
   * haja correio
   */
  bool notified;

public:
  Notifier(NotificationType type);
  int testMailBox();
  void Notify();
  ~Notifier();
};

#endif
