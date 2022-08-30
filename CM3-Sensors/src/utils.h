/*
type definitions to distinguish between different sensor types
see github.com/creatievemakers/HowToTalkToSensors
*/

#define AIR_QUALITY_SENSOR_TYPE                     0
#define MICROPHONE_SENSOR_TYPE                      1
#define TEMP_AND_HUMIDITY_SENSOR_SEN0137_TYPE       2
#define AMBIENT_LIGHT_SENSOR_TYPE                   3
#define GAS_SENSOR_SEN0040_TYPE                     4
#define COLOR_SENSOR_TYPE                           5
#define GAS_SENSOR_SEEED_TYPE                       6
#define SOIL_MOISTURE_SENSOR_TYPE                   7
#define MOTION_SENSOR_TYPE                          8

#define TEMP_METRIC_TYPE 0
#define HUMIDITY_METRIC_TYPE 1

#define LIGHT_METRIC_TYPE 0

#define HUMIDITY_METRIC_TYPE 0

#define CH4_METRIC_TYPE 0
#define C2H5OH_METRIC_TYPE 1
#define H2_METRIC_TYPE 2
#define NH3_METRIC_TYPE 3
#define CO_METRIC_TYPE 4
#define NO2_METRIC_TYPE 5

#define LED_PIN 2

#define URL_API "https://api.creativemakers.xyz/sensor-data.php"