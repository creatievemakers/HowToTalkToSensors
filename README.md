# HowToTalkToSensors

## Required Software

- VSCode with Platformio extension
- Arduino IDE 

## Sensor list

| Type | --- | Sensor | Description | Amount | Metrics |
| --- | --- | --- | --- | --- | --- |
| 0 | ![SEN0394_IMG] | DFrobot SEN0394 | [SGP40 air quality sensor](#air-quality-sensor) | 4 | 0: Air Quality index (int) |
| 1 | ![SEN0487_IMG] | DFrobot SEN0487 | [MEMS Microphone](#mems-microphone) | 7 | 0: Sound Intensity (0-4096) |
| 2 | ![SEN0137_IMG] | DFrobot SEN0137 | [DHT22 Digital temperature and humidity sensor](#digital-temperature-and-humidity-sensor) | 7 | 0: temp<br>1: humidity |
| 3 |![DFR0026_IMG] | DFrobot DFR0026 | [Light Sensor](#ambient-light-sensor) | 7| x |
| 4 | ![SEN0440_IMG] | DFrobot SEN0440 | [MEMS Gassensor - MiCS-5524](#gas-sensor)  | 2 | 0:Methane (CH4) (1000 - 25000)PPM<br>1: Ethanol          (C2H5OH) (10   - 500)PPM<br>2: Hydrogen         (H2)     (1    - 1000)PPM<br> 3: Ammonia          (NH3)    (1    - 500)PPM<br> 4: Carbon Monoxide  (CO)     (1    - 1000)PPM |
| 5 | ![AS7341_IMG] | DFrobot SEN0394 | [11-Channel color sensor]("11-channel-color-sensor) | 1 | x |
| 6 | <img src="https://files.seeedstudio.com/wiki/Grove-Multichannel_Gas_Sensor/img/Grove-Multichannel_Gas_Sensor_V2_101020820/IMG/04.png" width="200"> | Grove - [Multichannel Gas Sensor V2](#gas-sensor-seeed) | Gas Sensor | 1 | x |
| 7 | ![SEN019_IMG] | DFrobot SEN0193 | [Soil Moisture Sensor]("soil-moisture-sensor) | 7 | 0: moisture level |
| 8 | ![SEN0018_IMG] | DFrobot SEN0018 | [Motion Sensor]("motion-sensor) | 7 | Digital |

Others (only 1):
  - 001511 - BME280 Digital Barometer Pressure and Humidity Sensor Module						
  - 003975 - DFRobot Fermion MAX30102 Heart Rate and Oximeter Sensor V2 						
  - 003959 - DFRobot Gravity Analog Heart Rate Monitor Sensor - ECG Kit						
  - 004111- DFRobot Gravity Digital Magnet Sensor						
			



[SEN0487_IMG]: https://www.tinytronics.nl/shop/image/cache/catalog/products/product-003985/dfrobot-fermion-mems-microphone-module-200x200.jpg
[DFR0026_IMG]: https://www.tinytronics.nl/shop/image/cache/catalog/products_2022/dfrobot-gravity-analog-ambient-light-sensor-1-6000lx-200x200.jpg
[SEN0137_IMG]: https://www.tinytronics.nl/shop/image/cache/catalog/products/product-003935/dfrobot-gravity-dht22-temperature-and-humidity-sensor-with-cable-front-200x200.jpg
[SEN0440_IMG]: https://www.tinytronics.nl/shop/image/cache/catalog/products/product-003991/dfrobot-fermion-mems-gas-sensor-mics-5524-200x200.jpg
[SEN0394_IMG]: https://www.tinytronics.nl/shop/image/cache/catalog/products/product-003995/dfrobot-gravity-sgp40-air-quality-sensor-200x200.jpg
[AS7341_IMG]: https://www.tinytronics.nl/shop/image/cache/catalog/products/product-004002/dfrobot-gravity-as7341-11-channel-visible-light-sensor-back-200x200.jpg 
[SEN019_IMG]: https://www.tinytronics.nl/shop/image/cache/catalog/products/product-003939/dfrobot-gravity-capacitive-soil-moisture-sensor-front-side-200x200.jpg 
[SEN0018_IMG]: https://www.tinytronics.nl/shop/image/cache/catalog/products/product-003981/dfrobot-gravitiy-digital-ir-motion-sensor-200x200.jpg

## Platform list

| Prefifx-ID | --- | Platform | Description | Amount | Link |
| --- | --- | --- | --- | --- | --- |
|  | ![ESP32_IMG] | ESP32 WiFi en Bluetooth Board  | ESP32 | 40 |  |
|  | <img src="https://dramco.be/projects/dramco-uno/img/1-arduino-blink.gif" width="200"> | [Dramco uno](https://dramco.be/projects/dramco-uno/)  | - | x |  |
|  |  | Raspberry Pi 4  |  | 1 |  |

[ESP32_IMG]: https://www.tinytronics.nl/shop/image/cache/data/product-1443/esp32%20cp2102%20dev%20board%20v1%201-200x200.jpg



## Sensors

### MEMS Microphone

https://wiki.dfrobot.com/Fermion_MEMS_Microphone_Sensor_SKU_SEN0487

### Ambient Light Sensor

https://wiki.dfrobot.com/DFRobot_Ambient_Light_Sensor_SKU_DFR0026

### Digital temperature and humidity sensor

https://wiki.dfrobot.com/DHT22_Temperature_and_humidity_module_SKU_SEN0137

### 11 Channel Color Sensor

https://wiki.dfrobot.com/Gravity_AS7341_Visible_Light_Sensor_SKU_SEN0364

### Air quality sensor

https://wiki.dfrobot.com/Gravity_SGP40_Air_Quality_Sensor_SKU_SEN0394

### Gas sensor

https://wiki.dfrobot.com/Fermion__MEMS_Gas_Sensor___MiCS-5524_SKU_SEN0440

### Gas sensor Seeed

https://wiki.seeedstudio.com/Grove-Multichannel-Gas-Sensor-V2/

### Soil moisture sensor

https://wiki.dfrobot.com/Capacitive_Soil_Moisture_Sensor_SKU_SEN0193

### Motion Sensor

https://wiki.dfrobot.com/Digital_Infrared_motion_sensor__SKU_SEN0018_

## Read an Analog Sensor

```cpp
#include <Arduino.h>

#define ADC_PIN   8 // analog pin O-3.3V

void setup() {
  pinMode(ADC_PIN, INPUT);        // set the pin as input
  Serial.begin(11520);           //  setup serial
}

void loop() {
  uint16_t val = analogRead(ADC_PIN);  // read the input pin (12 bit)
  Serial.println(val);          // debug value
}
```

## Read a Digital Sensor
```cpp
#include <Arduino.h>

#define DIGITAL_PIN   8 // digital pin O-3.3V

void setup() {
  pinMode(DIGITAL_PIN, INPUT);        // set the pin as input
  Serial.begin(11520);           //  setup serial
}

void loop() {
  uint8_t val = digitalRead(DIGITAL_PIN);  // val O or 1 or equivalent LOW or HIGH
  Serial.println(val);          // debug value
}
```

## Connecting to WiFi

```cpp
#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>


const char *ssid = "iotd";
const char *password = "ez8?!NUD";


HTTPClient http;
String mac;

void setup()
{
  Serial.begin(115200);

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

  sendData(sensor_type, value, metric_type);

  delay(30 * 1000);
}

```

