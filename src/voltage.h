#ifndef voltage_h
#define voltage_h

#include <Arduino.h>
//Enum Variables for Selecting voltage type & Phase
enum voltagetype {
    DC, AC
};
enum phase {
    SINGLE, DOUBLE
};

class voltage {
    private:
        byte _pin;
        byte _pin2;
        voltagetype _voltagetype;
        phase _phase;
        int _scannum;
        float _calib;
        float _tempvoltage;
        float _voltage;
        float _tempvoltage2;
        float _voltage2;
        void begin(byte pin);
        void begin(byte pin, byte pin2);
    public:
        voltage(byte pin, voltagetype voltagetype);
        voltage(byte pin, byte pin2, voltagetype voltagetype, phase phase);
        void setScan(int scannum);
        int getScan();
        void setCalibration(float calib);
        float getCalibration();
        float getVoltage();
        void autoCalibrate(float voltage);
};
#endif