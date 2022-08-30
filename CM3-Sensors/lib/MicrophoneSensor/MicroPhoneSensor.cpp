#include "MicrophoneSensor.h"

uint16_t MicrophoneSensor::read(uint8_t interval_s)
{
    float sum = 0;
    uint32_t i = 0;

    time_t start = millis();

    while (millis() - start < interval_s * 1000) 
    {
        sum += analogRead(this->pin);
        i++;
    }

    return (uint16_t) (sum/ i); // cast to uint16_t value 
}