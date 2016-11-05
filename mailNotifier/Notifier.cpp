#include "Notifier.h"

Notifier::Notifier(NotificationType type){
  this->type = type;
  //Alloca os controladores do hardware
  this->ifLED = new InfraRedLED(3);
  this->ifSensor = new InfraRedSensor(3);
}

/* Verifica se existe correio na caixa
 *  O procedimento passa por verificar os valores de cada um
 *  dos sensores e aplicar a operação lógica OR. Apenas um dos
 *  sensores precisa de detectar a existência de cartas.
 */
int Notifier::testMailBox(){
  //Acende todos os LEDs
  this->ifLED->turnAllON();
}

Notifier::~Notifier(){
  delete ifLED;
  delete ifSensor;
}

