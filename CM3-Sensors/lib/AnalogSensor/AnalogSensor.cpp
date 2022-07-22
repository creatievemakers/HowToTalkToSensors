#include "AnalogSensor.h"

void AnalogSensor::setup(uint8_t pin)
{
    this->pin = pin;
}

uint16_t AnalogSensor::read()
{
    return analogRead(this->pin);
}