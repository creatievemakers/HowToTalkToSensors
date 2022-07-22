#ifndef _ANALOGSENSOR_H_
#define _ANALOGSENSOR_H_

#include <Arduino.h>

class AnalogSensor
{
public:
    //AnalogSensor(void);
    void setup(uint8_t pin);
    uint16_t read(void);

private:
    uint8_t pin;
};

#endif