#include <Arduino.h>
#include "MicrophoneSensor.h"
#include "AmbientLightSensor.h"
#include "DHTesp.h"

MicrophoneSensor micro;
AmbientLightSensor light;


DHTesp dht;

void setup()
{
  Serial.begin(115200);
  // micro.setup(32);
  light.setup(32);
  dht.setup(14, DHTesp::DHT22);
}

void loop()
{
  // read the microphonesensor
  //Serial.println(micro.read());
  //Serial.println(light.read());
  TempAndHumidity meas = dht.getTempAndHumidity();

  Serial.print("Temperature: ");
  Serial.println(meas.temperature);

  Serial.print("Humidity: ");
  Serial.println(meas.humidity);

  delay(5000);
}
