#ifndef _ANALOGSENSOR_H_
#define _ANALOGSENSOR_H_

#include <Arduino.h>

class AnalogSensor
{
public:
    //AnalogSensor(void);
    void setup(uint8_t pin); //TODO enforce usage between 32-39 because ADC2 is occupied by the radio
    uint16_t read(void);
    uint8_t pin; // public so derived class can access
};

#endif