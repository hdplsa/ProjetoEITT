#include "Mail.h"

Mail::Mail(NotificationType type){

  // Aloca os objetos
  this->ifled = new InfraRedLED(1);
  this->ifSensor = new InfraRedSensor(1);
  this->Not = new Notifier(type);

  // Faz a calibração
  this->initial_calibration();
  
}

double Mail::check_distance(){

  double medida;
  
  // Liga o emissor de IV
  ifled->turnAllON();
  // Espera um pouco para o TBJ ter tempo
  delay(100);

  // Obtem a tensão no emissor do TBJ
  medida = ifSensor->getSensorVoltage(0);
  Serial.print("u = ");
  Serial.println(medida,4);

  return medida;
}

void Mail::initial_calibration(){

  const int N = 10; // Quantas medições se fazem por calibração
  double cumsum = 0; // Variavel para guardar a soma das medições.

  for(int i = 1; i < N; i++){
    cumsum = this->check_distance();
  }

  this->calibVoltage = cumsum / N;

}

void Mail::chech_mail(){

  double medida; // Medida de distância.
  int offset; // ofset de niveis do ADC que fazem trigger da notificação

  medida = this->check_distance();

  if(medida > this->calibVoltage + 5/1024 * 50){
    Not->Notify();
  }
  
}

Mail::~Mail(){
  delete ifled;
  delete ifSensor;
  delete Not;
}

