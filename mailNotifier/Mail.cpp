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
  
  // Liga o emissor de IV e o recetor de IV
  ifled->turnAllON();
  ifSensor->turnAllSensorON();
  // Espera um pouco para o TBJ ter tempo
  delay(500);

  // Obtem a tensão no emissor do TBJ
  medida = ifSensor->getSensorVoltage(0);
  
  if(DEBUG){
    Serial.print("u = ");
    Serial.println(medida,4);
  }
  
  // Apaga os leds e o sensor
  ifled->turnAllOFF();
  ifSensor->turnAllSensorOFF();
  
  return medida;
}

void Mail::initial_calibration(){

  const double N = 10; // Quantas medições se fazem por calibração
  double cumsum = 0; // Variavel para guardar a soma das medições.

  // Obtem N medidas
  for(int i = 1; i < N+1; i++){
    cumsum += this->check_distance();
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

  // Caso se saiba que existe já novo correio, simplesmente retorna-se
  if(new_mail == true) return;

  double medida; // Medida de distância.

  // ofset de niveis do ADC que fazem trigger da notificação
  const int offset = 50; 

  medida = this->check_distance();

  if(DEBUG){
    Serial.print("u = ");
    Serial.println(medida,4);

    Serial.print("offset ");
    Serial.println(this->calibVoltage + 10/1024 * offset, 4);
  }
  
  // Notifica caso a nossa tensão recebida seja maior que a de calibração mais um offset 
  if(medida > this->calibVoltage + 10/1024 * offset){
    Serial.println("Detetei correio");
    new_mail = true;
  }
  
}

bool Mail::get_flag(){
  return new_mail;
}

void Mail::set_flag(bool flag){
  new_mail = flag;
}

void Mail::Notify(){
  Not->Notify();
}


Mail::~Mail(){
  delete ifled;
  delete ifSensor;
  delete Not;
}

