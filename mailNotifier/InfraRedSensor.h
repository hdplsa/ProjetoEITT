#ifndef INFRAREDSENSOR_H_INCLUDED
#define INFRAREDSENSOR_H_INCLUDED

#include "Arduino.h"

class InfraRedSensor{
  //Número de sensores
  int NSensor;
  //Número dos pins do sensor
  int sensorPin[3];
  //Tensões de entrada dos sensores
  double usensor[3];

public:
  InfraRedSensor(int NSensor);
  double getSensorVoltage(int sensorPin);
  double *getAllVoltage();
  double *getAllAverageVoltage(int Ntests);
  ~InfraRedSensor();
  
};

#endif
