#include <Arduino.h>
#include <voltage.h>

voltage v(A0, DC);

void setup() {
  Serial.begin(9600);
  v.setCalibration(0.00488); // random num for temp Calib
  v.autoCalibrate(220); //Voltage Measured on A voltmeter to Calibrate to.
  Serial.println("Scans Per Cycle:" + (String)v.getScan()/*Get the Number of Scan Cycles*/ 
          + " | Calibration:" + (String)v.getCalibration()/*Get the Calibration Constant*/);
}

void loop() {
  Serial.println((String)v.getVoltage());
  delay(2000);
}