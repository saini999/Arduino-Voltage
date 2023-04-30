# Arduino-Voltage

This library is for measuring AC/DC Single/Double Phase Voltages

# Usage:

Including the Library:

` #include "voltage.h" `

Creating Voltage Object:

``` 
voltage v(pin,DC); 
    //v is Oject Name
    //pin is Analog Pin
    //DC defines Voltage Type DC
```

Calibrating the Voltage:
```
v.setCalibration(0.1234);
    //here v is Object Name
    //set setCalibration to any Random number for temporary calibration
    //then write down the output from a real volt meter.
    //then set autoCalibrate to the Actual Reading You get on the Volt Meter
v.autoCalibrate(220);
    //Warning this should be in void setup(){}
```
Reading the Voltage:
```
float voltage;
voltage = v.getVoltage();
    //And you should have the Voltage :>

```


Example Code: [arduino-voltage](/src/main.cpp)
