#ifndef DHT_SENSORS_H
#define DHT_SENSORS_H
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

class DhtSensors
{
public:
    DhtSensors(uint8_t pin, uint8_t type);
    void init();
    void updateSensors();
    float temperature = 0;
    float humidity = 0;
    uint32_t delayMS;
private:
    DHT_Unified dht;
    sensor_t sensor;
    sensors_event_t event;
};

#endif