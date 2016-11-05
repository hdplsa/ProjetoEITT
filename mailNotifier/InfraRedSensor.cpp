#include "InfraRedSensor.h"

InfraRedSensor::InfraRedSensor(int NSensor){
  this->NSensor = NSensor;
  //Inicializa pinos dos sensores
  this->sensorPin[0] = 0;
  this->sensorPin[1] = 1;
  this->sensorPin[2] = 2;
}

double InfraRedSensor::getSensorVoltage(int sensorPin){
  int sr;
  double u;
  sr = analogRead(sensorPin);
  u = (double)sr*(5.0/1024.0);
  return u;
}

void InfraRedSensor::getAllVoltage(){
  int n;
  for(n=0;n<NSensor;n++){
    this->usensor[n] = getSensorVoltage(sensorPin[n]);
  }
}

InfraRedSensor::~InfraRedSensor(){
  
}

