# HowToTalkToSensors

## Required Software

- VSCode with Platformio extension
- Arduino IDE 

## Sensor list

| Type | --- | Sensor | Description | Amount | Metrics |
| --- | --- | --- | --- | --- | --- |
| 0 | ![SEN0394_IMG] | DFrobot SEN0394 | SGP40 air quality sensor | x | 0: Air Quality index (int) |
| 1 | ![SEN0487_IMG] | DFrobot SEN0487 | [MEMS Microphone](#mems-microphone) | x | 0: Sound Intensity (0-4096) |
| 2 | ![SEN0137_IMG] | DFrobot SEN0137 | [DHT22 Digital temperature and humidity sensor](#digital-temperature-and-humidity-sensor) | x | 0: temp<br>1: humidity |
| 3 |![DFR0026_IMG] | DFrobot DFR0026 | [Light Sensor](#ambient-light-sensor) | x | x |
| 4 | ![SEN0440_IMG] | DFrobot SEN0440 | MEMS Gassensor - MiCS-5524  | x | 0:Methane (CH4) (1000 - 25000)PPM<br>1: Ethanol          (C2H5OH) (10   - 500)PPM<br>2: Hydrogen         (H2)     (1    - 1000)PPM<br> 3: Ammonia          (NH3)    (1    - 500)PPM<br> 4: Carbon Monoxide  (CO)     (1    - 1000)PPM |
| 5 | ![AS7341_IMG] | DFrobot SEN0394 | 11-Channel color sensor | x | x |
| 6 | <img src="https://files.seeedstudio.com/wiki/Grove-Multichannel_Gas_Sensor/img/Grove-Multichannel_Gas_Sensor_V2_101020820/IMG/04.png" width="200"> | Grove - Multichannel Gas Sensor V2 | Gas Sensor | x | x |

[SEN0487_IMG]: https://www.tinytronics.nl/shop/image/cache/catalog/products/product-003985/dfrobot-fermion-mems-microphone-module-200x200.jpg
[DFR0026_IMG]: https://www.tinytronics.nl/shop/image/cache/catalog/products_2022/dfrobot-gravity-analog-ambient-light-sensor-1-6000lx-200x200.jpg
[SEN0137_IMG]: https://www.tinytronics.nl/shop/image/cache/catalog/products/product-003935/dfrobot-gravity-dht22-temperature-and-humidity-sensor-with-cable-front-200x200.jpg
[SEN0440_IMG]: https://www.tinytronics.nl/shop/image/cache/catalog/products/product-003991/dfrobot-fermion-mems-gas-sensor-mics-5524-200x200.jpg
[SEN0394_IMG]: https://www.tinytronics.nl/shop/image/cache/catalog/products/product-003995/dfrobot-gravity-sgp40-air-quality-sensor-200x200.jpg
[AS7341_IMG]: https://www.tinytronics.nl/shop/image/cache/catalog/products/product-004002/dfrobot-gravity-as7341-11-channel-visible-light-sensor-back-200x200.jpg 

## Platform list

| Prefifx-ID | --- | Platform | Description | Amount | Link |
| --- | --- | --- | --- | --- | --- |
|  | ![ESP32_IMG] | ESP32 WiFi en Bluetooth Board  | ESP32 | x |  |
|  | <img src="https://dramco.be/projects/dramco-uno/img/1-arduino-blink.gif" width="200"> | [Dramco uno](https://dramco.be/projects/dramco-uno/)  | - | x |  |

[ESP32_IMG]: https://www.tinytronics.nl/shop/image/cache/data/product-1443/esp32%20cp2102%20dev%20board%20v1%201-200x200.jpg



## Sensors

### MEMS Microphone

https://wiki.dfrobot.com/Fermion_MEMS_Microphone_Sensor_SKU_SEN0487

### Ambient Light Sensor

https://wiki.dfrobot.com/DFRobot_Ambient_Light_Sensor_SKU_DFR0026

### Digital temperature and humidity sensor

https://wiki.dfrobot.com/DFRobot_Ambient_Light_Sensor_SKU_DFR0026
