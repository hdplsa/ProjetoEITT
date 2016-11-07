#include "InfraRedLED.h"
#include "InfraRedSensor.h"
#include "Notifier.h"

InfraRedLED *ifled = new InfraRedLED(1);
InfraRedSensor *ifSensor = new InfraRedSensor(1);
  
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  ifled->turnAllON();
  ifSensor->turnAllSensorON();
}

void loop() {
  // put your main code here, to run repeatedly:
  double u = ifSensor->getSensorVoltage(0);
  Serial.print("u = ");
  Serial.println(u,4);
  delay(500);
}
