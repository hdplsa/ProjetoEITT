#ifndef MAIL_H_INCLUDED
#define MAIL_H_INCLUDED

#include "Arduino.h"
#include "InfraRedLED.h"
#include "InfraRedSensor.h"
#include "Notifier.h"

class Mail{

  // Obtejos do emissor de IV, sensor de IV e notificação
  InfraRedLED *ifled;
  InfraRedSensor *ifSensor;
  Notifier *Not;

  // Variáveis provenientes da calibação
  double calibVoltage;
  
  public:
    Mail(NotificationType type);
    ~Mail();
    double check_distance();    
    void chech_mail();

  private:
    void initial_calibration();
  
};

#endif
