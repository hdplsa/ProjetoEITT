#include "Notifier.h"

const int LEDPin = 2;

Notifier::Notifier(NotificationType type){
  this->type = type;
  //Alloca os controladores do hardware
  //this->ifLED = new InfraRedLED(1);
  //this->ifSensor = new InfraRedSensor(1);
  //Aloca Notificador(es)
  switch(this->type){
    case PiscaLED:
      piscaLED = new LEDNotifier(LEDPin);
      gsm = 0;
      break;
    case GSM:
      piscaLED = 0;
      gsm = new GSMNotifier();
      break;
    case BOTH:
      piscaLED = new LEDNotifier(LEDPin);
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

void Notifier::Notify(){

  switch(this->type){
    case PiscaLED:
      this->piscaLED->turnON();
      delay(500);
      this->piscaLED->turnOFF();
    break;
    case GSM:
      if(!this->notified){
        // this->GSMNotifier();
      }
    break;
    case BOTH:
    break;
    default:
    break;
  }
  this->notified = true; 
}

Notifier::~Notifier(){
  delete ifLED;
  delete ifSensor;
}

