#include <avr/io.h>
#include <avr/interrupt.h>
#include "InfraRedLED.h"
#include "InfraRedSensor.h"
#include "Notifier.h"

InfraRedLED *ifled = new InfraRedLED(1);
InfraRedSensor *ifSensor = new InfraRedSensor(1);
Notifier *Not = new Notifier(PiscaLED);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  ifled->turnAllON();
  ifSensor->turnAllSensorON();
  initTimer1();

  //SETUP WATCHDOG TIMER FOR 8sec
  WDTCSR = (24);//change enable and WDE - also resets
  WDTCSR = (33);//prescalers only - get rid of the WDE and WDCE bit
  WDTCSR |= (1<<6);//enable interrupt mode

  //ENABLE SLEEP - this enables the sleep mode
  SMCR |= (1 << 2); //power down mode
  SMCR |= 1;//enable sleep
  
}

void loop() {
  // put your main code here, to run repeatedly:

  // Liga o ADC (gasta energia)
  ADCSRA |= (1 << 7)
  
  double u = ifSensor->getSensorVoltage(0);
  Serial.print("u = ");
  Serial.println(u,4);
  delay(500);

  //Desliga o ADC
  ADCSRA &= ~(1 << 7);

  const int n = 1;

  for(int i=0; i < n; i++){ // Dorme n vezes, cada uma 8 segundos
  //BOD DISABLE - this must be called right before the __asm__ sleep instruction
  //O BOD (Brown-out detector) verifica a tensão de entrada, fazendo reset caso ela baixe muito,
  //No circuito final é capaz de ser melhor não usar isto para ele não se passar.
  MCUCR |= (3 << 5); //set both BODS and BODSE at the same time
  MCUCR = (MCUCR & ~(1 << 5)) | (1 << 6); //then set the BODS bit and clear the BODSE bit at the same time
  __asm__  __volatile__("sleep");//in line assembler to go to sleep
  }


  Serial.print("2\n");
  Not->Notify();
}

ISR(WDT_vect){
  //DON'T FORGET THIS!  Needed for the watch dog timer.  This is called after a watch dog timer timeout - this is the interrupt function called after waking up
}// watchdog interrupt
