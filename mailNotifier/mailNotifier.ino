#include <avr/io.h>
#include <avr/interrupt.h>
#include "InfraRedLED.h"
#include "InfraRedSensor.h"
#include "Notifier.h"
#include "Mail.h"

const int DEBUG = 1;
Mail *mail;

void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(9600);

  mail = new Mail(PiscaLED, DEBUG);

  setup_sleep();
  
}

void loop() {
  // put your main code here, to run repeatedly:

  // Liga o ADC (gasta energia)
  ADCSRA |= (1 << 7);
  
  mail->check_mail();

  //Desliga o ADC
  ADCSRA &= ~(1 << 7);

  sleeps(1);
}

void setup_sleep(){

  //SETUP WATCHDOG TIMER FOR 8sec
  WDTCSR = (24); //change enable and WDE - also resets
  WDTCSR = 0b00000111; // diz o tempo que queremos (pg.55 datasheet) - get rid of the WDE and WDCE bit
  WDTCSR |= (1<<6); // pin WDIE - enable interrupt mode

  //ENABLE SLEEP - this enables the sleep mode
  SMCR |= (1 << 2); //power down mode
  SMCR |= 1;//enable sleep
  
}

// Dorme durante N ciclos, de X minutos, definidos durante o setup
void sleeps(int N){

  for(int i=0; i < N; i++){ // Dorme n vezes, cada uma 8 segundos
    //BOD DISABLE - this must be called right before the __asm__ sleep instruction
    //O BOD (Brown-out detector) verifica a tensão de entrada, fazendo reset caso ela baixe muito,
    //No circuito final é capaz de ser melhor não usar isto para ele não se passar.
    MCUCR |= (3 << 5); //set both BODS and BODSE at the same time
    MCUCR = (MCUCR & ~(1 << 5)) | (1 << 6); //then set the BODS bit and clear the BODSE bit at the same time
    __asm__  __volatile__("sleep");//in line assembler to go to sleep
  }
  
}

ISR(WDT_vect){
  //DON'T FORGET THIS!  Needed for the watch dog timer.  This is called after a watch dog timer timeout - this is the interrupt function called after waking up
}// watchdog interrupt
