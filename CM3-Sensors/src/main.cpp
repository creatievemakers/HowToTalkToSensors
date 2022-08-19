#include <Arduino.h>
#include <WiFi.h>
#include <PubSubClient.h>

/* define which sensors you want to use */
// #define INCLUDE_GAS_SENSOR_SEN0040
// #define INLUDE_GAS_SENSOR_SEEED
// #define INCLUDE_MICROPHONE_SENSOR
// #define INCLUDE_AMBIENT_LIGHT_SENSOR
// #define INCLUDE_TEMP_AND_HUMIDITY_SENSOR_SEN0137
#define INCLUDE_AIR_QUALITY_SENSOR
// #define INCLUDE_COLOR_SENSOR

#ifdef INCLUDE_MICROPHONE_SENSOR
  #include "MicrophoneSensor.h"
/* value = {0,1} sound detected */
MicrophoneSensor micro;
#endif

#ifdef INCLUDE_AMBIENT_LIGHT_SENSOR
  /* value = intensity (12-bit lux) */ // not really lux, we can probably approximate to 0 (2^12)-1 <-> 1-6000lux
  #include "AmbientLightSensor.h"
  AmbientLightSensor light;
#endif

#ifdef INCLUDE_TEMP_AND_HUMIDITY_SENSOR_SEN0137
  /* value = temp (°C), humidity (%) */
#include "DHTesp.h"
  DHTesp dht;
#endif

#ifdef INLUDE_GAS_SENSOR_SEEED
  /* value = NO2, C2H5CH, VOC, CO */
  #include <Multichannel_Gas_GMXXX.h>
  #include <Wire.h>
  GAS_GMXXX<TwoWire> gas;
#endif

#ifdef INCLUDE_AIR_QUALITY_SENSOR
  /* value = NO2, C2H5CH, VOC, CO */
  #include <DFRobot_SGP40.h>
#include <Wire.h>
  DFRobot_SGP40 gas;
#endif

#ifdef INCLUDE_COLOR_SENSOR
  /* value = ADF1, ADF2, ADF3, ADF4, ADF5, ADF6, ADF7, ADF8, ADNIR */
  #include "DFRobot_AS7341.h"
  DFRobot_AS7341 color_sensor;
  DFRobot_AS7341::sModeOneData_t data1;
  DFRobot_AS7341::sModeTwoData_t data2;
#endif

  /* sensors/<group-id>/<sensor-name>/<sensor-id> */
  /* value = ssid , rssi (dB) */
  WiFiClient espClient;
  PubSubClient client(espClient);

  void setup()
  {
    Serial.begin(115200);
    // micro.setup(32);
    //light.setup(32);
    //dht.setup(14, DHTesp::DHT22);
    Serial.println("sgp40 is starting, the reading can be taken after 10 seconds...");
    while (gas.begin(/*duration = */ 10000) != true)
    {
      Serial.println("failed to init chip, please check if the chip connection is fine");
      delay(1000);
    }
    Serial.println("----------------------------------------------");
    Serial.println("sgp40 initialized successfully!");
    Serial.println("----------------------------------------------");
}

void loop()
{
  // read the microphonesensor
  //Serial.println(micro.read());
  //Serial.println(light.read());
  // TempAndHumidity meas = dht.getTempAndHumidity();

  // Serial.print("Temperature: ");
  // Serial.println(meas.temperature);

  // Serial.print("Humidity: ");
  // Serial.println(meas.humidity);

  Serial.println(gas.getVoclndex());

  delay(10*1000);
}
