#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>

#include "utils.h"

const char *ssid = "NETGEAR68";
const char *password = "excitedtuba713";

/* define which sensors you want to use */
// #define INCLUDE_GAS_SENSOR_SEN0040
// #define INLUDE_GAS_SENSOR_SEEED
// #define INCLUDE_MICROPHONE_SENSOR
// #define INCLUDE_AMBIENT_LIGHT_SENSOR
// #define INCLUDE_TEMP_AND_HUMIDITY_SENSOR_SEN0137
// #define INCLUDE_AIR_QUALITY_SENSOR
// #define INCLUDE_COLOR_SENSOR

#ifdef INCLUDE_GAS_SENSOR_SEN0040
#include "DFRobot_MICS.h"


#define CALIBRATION_TIME 3 // minutes

// When using the Breakout version, use the following program to construct an object from DFRobot_MICS_ADC
/**!
  adcPin is A0~A5
  powerPin is General IO
*/
#define ADC_PIN 34
#define POWER_PIN 35
DFRobot_MICS_ADC mics(/*adcPin*/ ADC_PIN, /*powerPin*/ POWER_PIN);
#endif

#ifdef INCLUDE_MICROPHONE_SENSOR
#include "MicrophoneSensor.h"
/* value = averaged signal strength detected */
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
#include <Wire.h> // default 0x55 address
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

HTTPClient http;
String mac;

void setup()
{
  Serial.begin(115200);

#ifdef INCLUDE_MICROPHONE_SENSOR
  micro.setup(32);
#endif
  //  light.setup(32);
  #ifdef INCLUDE_TEMP_AND_HUMIDITY_SENSOR_SEN0137
  dht.setup(14, DHTesp::DHT22);
  #endif
  pinMode(LED_PIN, OUTPUT);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED)
  {
    digitalWrite(LED_PIN, HIGH);
    delay(500);
    Serial.println("Connecting to WiFi..");
    digitalWrite(LED_PIN, LOW);
    delay(500);
  }

  Serial.println("Connected to the WiFi network");

  mac = WiFi.macAddress();

#ifdef INCLUDE_AIR_QUALITY_SENSOR
  Serial.println("sgp40 is starting, the reading can be taken after 10 seconds...");
  /*
   * The preheating time of the sensor is 10s.
   * duration:Initialize the wait time. Unit: millisecond. Suggestion: duration > = 10000 ms
   */
  while (gas.begin(/*duration = */ 10000) != true)
  {
    Serial.println("failed to init chip, please check if the chip connection is fine");
    delay(1000);
  }
  Serial.println("----------------------------------------------");
  Serial.println("sgp40 initialized successfully!");
  Serial.println("----------------------------------------------");
#endif

#ifdef INCLUDE_GAS_SENSOR_SEN0040
  while (!mics.begin())
  {
    Serial.println("NO Devices detected!");
    delay(1000);
  }
  Serial.println("Device connected successfully !");

  /**!
    Gets the power mode of the sensor
    The sensor is in sleep mode when power is on, so it needs to wake up the sensor.
    The data obtained in sleep mode is wrong
   */
  uint8_t mode = mics.getPowerState();
  if (mode == SLEEP_MODE)
  {
    mics.wakeUpMode();
    Serial.println("wake up sensor success!");
  }
  else
  {
    Serial.println("The sensor is wake up mode");
  }

  /**!
     Do not touch the sensor probe when preheating the sensor.
     Place the sensor in clean air.
     The default calibration time is 3 minutes.
  */
  while (!mics.warmUpTime(CALIBRATION_TIME))
  {
    Serial.println("Please wait until the warm-up time is over!");
    delay(1000);
  }
#endif
}

void sendData(uint8_t type, String value, uint8_t metric=0)
{
  http.begin(URL_API);
  http.addHeader("Content-Type", "application/json");

  String putMsg = "{\"mac\":\"";
  putMsg.concat(mac);
  putMsg.concat("\", \"type\":");
  putMsg.concat(type);
  putMsg.concat(",\"metric\":");
  putMsg.concat(metric);
  putMsg.concat(", \"value\":\"");
  putMsg.concat(value);
  putMsg.concat("\"}");

  Serial.println(putMsg);

  int httpResponseCode = http.PUT(putMsg);

  http.end();
}

void loop()
{

#ifdef INCLUDE_AIR_QUALITY_SENSOR
  sendData(AIR_QUALITY_SENSOR_TYPE, String(gas.getVoclndex()))
#endif

#ifdef INCLUDE_MICROPHONE_SENSOR
      sendData(MICROPHONE_SENSOR_TYPE, String(micro.read(10)));
#endif

#ifdef INCLUDE_TEMP_AND_HUMIDITY_SENSOR_SEN0137
  TempAndHumidity meas = dht.getTempAndHumidity();

  sendData(TEMP_AND_HUMIDITY_SENSOR_SEN0137_TYPE, String(meas.temperature),TEMP_METRIC_TYPE);
  sendData(TEMP_AND_HUMIDITY_SENSOR_SEN0137_TYPE, String(meas.humidity), HUMIDITY_METRIC_TYPE);

#endif

#ifdef INCLUDE_AMBIENT_LIGHT_SENSOR
      sendData(AMBIENT_LIGHT_SENSOR_TYPE, String(light.read()));
#endif


#ifdef INCLUDE_GAS_SENSOR_SEN0040

  Serial.println(mics.getGasData(CO));
  String value = String(mics.getGasData(CO), 1);
  sendData(GAS_SENSOR_SEN0040_TYPE, value, CO_METRIC_TYPE);

  value = String(mics.getGasData(NH3), 1);
  sendData(GAS_SENSOR_SEN0040_TYPE, value, NH3_METRIC_TYPE);

  value = String(mics.getGasData(H2), 1);
  sendData(GAS_SENSOR_SEN0040_TYPE, value, H2_METRIC_TYPE);

  value = String(mics.getGasData(CH4), 1);
  sendData(GAS_SENSOR_SEN0040_TYPE, value, CH4_METRIC_TYPE);

  value = String(mics.getGasData(C2H5OH), 1);
  sendData(GAS_SENSOR_SEN0040_TYPE, value, C2H5OH_METRIC_TYPE);

  value = String(mics.getGasData(NO2), 1);
  sendData(GAS_SENSOR_SEN0040_TYPE, value, NO2_METRIC_TYPE);
#endif

#ifdef INCLUDE_COLOR_SENSOR
  // Channel mapping mode : 1.eF1F4ClearNIR, 2.eF5F8ClearNIR
  color_sensor.startMeasure(color_sensor.eF1F4ClearNIR);
  // Read the value of sensor data channel 0~5, under eF1F4ClearNIR

  uint16_t data[12];

  for(int i =0;i<6;i++){
    data[i] = color_sensor.getChannelData(i);
  }

  color_sensor.startMeasure(color_sensor.eF5F8ClearNIR);
  // Read the value of sensor data channel 0~5, under eF5F8ClearNIR
  for (int i = 6; i < 12; i++)
  {
    data[i] = color_sensor.getChannelData(i-6);
  }

  String value = "";

  for(int i=0; i<12;i++){
    value += String(data[i]);
    value += ";"
  }

  sendData(GAS_SENSOR_SEN0040_TYPE, value, NO2_METRIC_TYPE);
#endif

  delay(30 * 1000);
}
