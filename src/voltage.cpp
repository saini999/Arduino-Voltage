#include <voltage.h>


void voltage::begin(byte pin){
    pinMode(pin, INPUT);
}

void voltage::begin(byte pin, byte pin2) {
    pinMode(pin, INPUT);
    pinMode(pin2, INPUT);
}

voltage::voltage(byte pin, voltagetype voltagetype){
    _pin = pin;
    _voltagetype = voltagetype;
    _scannum = 1;
    begin(_pin);
}
voltage::voltage(byte pin, byte pin2, voltagetype voltagetype, phase phase){
    _pin = pin;
    _pin2 = pin2;
    _voltagetype = voltagetype;
    _phase = phase;
    if(_voltagetype == DC){
        _scannum = 1;
    } else {
        _scannum = 10;
    }
    begin(_pin, _pin2);
}
void voltage::setScan(int scannum){
    _scannum = scannum;
}
int voltage::getScan(){
    return _scannum;
}
void voltage::setCalibration(float calib){
    _calib = calib;
}
float voltage::getCalibration(){
    return _calib;
}
float voltage::getVoltage() {
    if(_phase == SINGLE){
        _voltage = 0;
        for(int i = 0; i < _scannum; i++){
            _tempvoltage = analogRead(_pin) * _calib;
            if(_tempvoltage > _voltage){
                _voltage = _tempvoltage;
            }
        }
        return _voltage;
    }
    if(_phase == DOUBLE){
        _voltage = 0; _voltage2 = 0;
        for(int i = 0; i < _scannum; i++){
            _tempvoltage = analogRead(_pin) * _calib;
            _tempvoltage2 = analogRead(_pin2) * _calib;
            if(_tempvoltage > _voltage){
                _voltage = _tempvoltage;
            }
            if(_tempvoltage2 > _voltage2){
                _voltage2 = _tempvoltage2;
            }
        }
        return (_voltage + _voltage2) * 0.863; //0.863 is the constant to calculate double phase voltage
    }
}

float voltage::autoCalibrate(float voltage){
    _calib = (voltage / getVoltage()) * _calib;
    return _calib;
}