#include "Mail.h"

Mail::Mail(NotificationType type, int DEBUG){

  // Diz se estamos em debug ou não
  this->DEBUG = DEBUG;

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
  if(DEBUG){
    Serial.print("u = ");
    Serial.println(medida,4);
  }
  return medida;
}

void Mail::initial_calibration(){

  const int N = 10; // Quantas medições se fazem por calibração
  double cumsum = 0; // Variavel para guardar a soma das medições.

  // Obtem N medidas
  for(int i = 1; i < N; i++){
    cumsum = this->check_distance();
  }

  // Faz a média das medidas
  this->calibVoltage = cumsum / N;
  
  if(DEBUG){
    Serial.println("Calibration done");
    Serial.print("V = ");
    Serial.println(this->calibVoltage,4);
  }

}

void Mail::check_mail(){

  double medida; // Medida de distância.

  // ofset de niveis do ADC que fazem trigger da notificação
  const int offset = 50; 

  medida = this->check_distance();

  if(DEBUG){
    Serial.print("u = ");
    Serial.println(medida,4);
  }
  
  // Notifica caso a nossa tensão recebida seja maior que a de calibração mais um offset 
  if(medida > this->calibVoltage + 5/1024 * offset){
    Not->Notify();
  }
  
}

Mail::~Mail(){
  delete ifled;
  delete ifSensor;
  delete Not;
}

