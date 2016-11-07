#include <avr/io.h>
#include <avr/interrupt.h>
#include "InfraRedLED.h"
#include "InfraRedSensor.h"
#include "Notifier.h"

InfraRedLED *ifled = new InfraRedLED(1);
InfraRedSensor *ifSensor = new InfraRedSensor(1);
Notifier *Not = new Notifier(PiscaLED);

volatile bool flag = 0;

void initTimer1(){
  cli();
  TCCR1A = 0;// clear register
  TCCR1B = 0;// clear register
  TCNT1 = 0;//reset counter
  OCR1A = 7126; //must be <65536
  // = (16*10^6) / (1*1024) – 1
  TCCR1B |= (1 << WGM12); //CTC On
  // Set prescaler for 1024
  TCCR1B |= (1<<CS12)|(1<<CS10);
  // enable timer compare interrupt
  TIMSK1 |= (1 << OCIE1A);
  sei(); //allow interrupts
}
  
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  ifled->turnAllON();
  ifSensor->turnAllSensorON();
  initTimer1();
}

ISR(TIMER1_COMPA_vect){
  
  flag = 1; //notify main loop
 
}

void loop() {
  // put your main code here, to run repeatedly:
  double u = ifSensor->getSensorVoltage(0);
  Serial.print("u = ");
  Serial.println(u,4);
  delay(500);

  if(flag){
    Serial.print("2\n");
    Not->Notify();
  }
}
