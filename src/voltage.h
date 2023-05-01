#ifndef voltage_h
#define voltage_h
#include <Arduino.h>

//Create Variables for Current type and phase type

enum voltagetype{
    DC, AC
};

enum phase{
    SINGLE, DOUBLE
};

class voltage {
    private:
        //Private Varibales
        byte _pin, _pin2;
        voltagetype _voltagetype;
        phase _phase;
        int _scannum;
        float _calib, _tempvoltage, _tempvoltage2, _voltage, _voltage2;
        //Function to setup pins as input
        void begin(byte pin);
        void begin(byte pin, byte pin2);
    public:
        voltage(byte pin, voltagetype voltagetype); // Initialize DC or AC Single Phase Voltage reading
        voltage(byte pin, byte pin2, voltagetype voltagetype, phase phase); //Initialize AC Double Phase Voltage Reading
        void setScan(int scannum); //Set Scan numbers to scan voltage multiple times before getting result, helps with keeping AC voltage Reading Stable
        int getScan(); //get the scan number
        void setCalibration(float calib); //set Calibration Value
        float getCalibration(); // get Calibration Value
        float getVoltage(); //Read the Voltage
        float autoCalibrate(float voltage); //to be called once to get the calibration Value
};

#endif