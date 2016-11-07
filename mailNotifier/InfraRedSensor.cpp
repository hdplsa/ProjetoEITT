#include "InfraRedSensor.h"

InfraRedSensor::InfraRedSensor(int NSensor){
  int n;
  this->NSensor = NSensor;
  //Inicializa pinos dos sensores
  this->sensorPin[0] = 0;
  this->sensorPin[1] = 1;
  this->sensorPin[2] = 2;
  //Inicializa pinos de alimentação dos sensores
  this->sensorPowerPin[0] = 8;
  //Modo output nos pinos de alimentação dos LEDs
  for(n=0; n<this->NSensor; n++){
    pinMode(this->sensorPowerPin[n], OUTPUT);
  }
}

void InfraRedSensor::turnAllSensorON(){
  int n;
  for(n=0;n<this->NSensor;n++){
    digitalWrite(this->sensorPowerPin[n], HIGH);
  }
}

double InfraRedSensor::getSensorVoltage(int sensorPin){
  int sr;
  double u;
  sr = analogRead(sensorPin);
  u = (double)sr*(5.0/1024.0);
  return u;
}

double *InfraRedSensor::getAllVoltage(){
  int n;
  for(n=0;n<NSensor;n++){
    this->usensor[n] = getSensorVoltage(sensorPin[n]);
  }
  return this->usensor;
}

double *InfraRedSensor::getAllAverageVoltage(int Ntests){
  int n,k,av;
  for(n=0;n<NSensor;n++){
    for(k=1,av=0;k<=Ntests;k++){
       av = av + getSensorVoltage(sensorPin[n]);
    }
    this->usensor[n] = (double)av/(double)Ntests;
  }
  return this->usensor;
}

int InfraRedSensor::getORSensor(){
  int n,flag;
  for(n=0,flag=0;n<this->NSensor;n++){
    if(this->usensor[n] > this->REF){
      flag = 1;
    }
  }
  return flag;
}

InfraRedSensor::~InfraRedSensor(){
  
}

