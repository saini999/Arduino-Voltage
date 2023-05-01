#include <Arduino.h>
#include <voltage.h>

voltage v(A0, DC);

void setup() {
  Serial.begin(9600);
  v.setCalibration(0.216); //use some random number 1 > x > 0 for temp Calibration
  //Serial.println("AutoCalibrate:" + (String)v.autoCalibrate(220)); //220 is the real Voltage we just Checked.
  Serial.println("Scans: " + (String)v.getScan() + "\n Calibration: " + (String)v.getCalibration());
}

void loop() {
  Serial.println("Voltage: " + (String)v.getVoltage());
  delay(1000);
}