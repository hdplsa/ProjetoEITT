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
  //Power do Sensor
  int sensorPowerPin[3];
  //Valor minimo de referência no sensor para haver carta
  double REF;
  
public:
  InfraRedSensor(int NSensor);
  void turnAllSensorON();
  void turnAllSensorOFF();
  double getSensorVoltage(int sensorPin);
  double *getAllVoltage();
  double *getAllAverageVoltage(int Ntests);
  int getORSensor();
  ~InfraRedSensor();
  
};

#endif
