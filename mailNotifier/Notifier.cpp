#include "Notifier.h"

Notifier::Notifier(NotificationType type){
  this->type = type;
  //Alloca os controladores do hardware
  this->ifLED = new InfraRedLED(3);
  this->ifSensor = new InfraRedSensor(3);
  //Aloca Notificador(es)
  switch(this->type){
    case PiscaLED:
      piscaLED = new LEDNotifier();
      gsm = 0;
      break;
    case GSM:
      piscaLED = 0;
      gsm = new GSMNotifier();
      break;
    case BOTH:
      piscaLED = new LEDNotifier();
      gsm = new GSMNotifier();
      break;
  }
}

/* Verifica se existe correio na caixa
 *  O procedimento passa por verificar os valores de cada um
 *  dos sensores e aplicar a operação lógica OR. Apenas um dos
 *  sensores precisa de detectar a existência de cartas.
 */
int Notifier::testMailBox(){
  int flag;
  //Acende todos os LEDs
  this->ifLED->turnAllON();
  //Recebe OR das leituras dos sensores
  flag = this->ifSensor->getORSensor();
  //Apaga todos os LEDs
  this->ifLED->turnAllOFF();
  //Iniciar processo de notificação
  if(flag){
    //Verificação do tipo de processo de notificação
    switch(this->type){
      case PiscaLED:

        break;
      case GSM:

        break;
    }
  }
}

Notifier::~Notifier(){
  delete ifLED;
  delete ifSensor;
}

