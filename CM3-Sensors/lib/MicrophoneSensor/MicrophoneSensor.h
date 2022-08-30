#ifndef _MICROPHONESENSOR_H_
#define _MICROPHONESENSOR_H_

#include <Arduino.h>
#include "AnalogSensor.h"

class MicrophoneSensor : public AnalogSensor
{
    using AnalogSensor::AnalogSensor; // use constructor of the AnalogSensor class
    public:
        uint16_t read(uint8_t interval);
        uint8_t TYPE = 1;
};

#endif