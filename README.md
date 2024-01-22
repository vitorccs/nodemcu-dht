# NodeMCU DHT Monitor
A NodeMCU project which displays temperature and humidity on a web page

<img src="https://github.com/vitorccs/nodemcu-dht/assets/9891961/4df5f647-7a65-4737-a752-f45732b97167" width="700">

## Description
The temperature and humidity is measured regularly in a time interval. The HTTP Server uses [asynchronous network](https://github.com/esphome/ESPAsyncWebServer) for better optimization and to prevent issues with sensor libraries.

<img src="https://github.com/vitorccs/nodemcu-dht/assets/9891961/cd229b49-1690-4b3c-838d-dc9824f74fd7" width="700">

## Components
* 01 - NodeMCU v2 board
* 01 - DHT-11/DHT-22 sensor
* 02 - 1K Ω Resistor
* 01 - Mini protoboard (170 holes) - using as board support

## About PlatformIO IDE
Platform IO is a plugin for Microsoft Visual Studio Code. It is a more robust IDE compared to the official Arduino IDE. It also allows us to easily create our own private libraries and use a more object oriented code.

## About the code
The PINs can be customized in the `main.cpp` 
```c++
#include <Arduino.h>
#include <DHT.h>
#include <DhtSensors.h>
#include <WifiHandler.h>
#include <WebServer.h>

#define WIFI_SSID "MY_SSDI"
#define WIFI_PWD "MY_PASSWORD"
#define DHTPIN D5
#define DHTTYPE DHT11
#define WIFI_AP_MODE false // Access Point mode (no internet connection)
#define UPDATE_MS 5000

WifiHandler wifiHandler;
DhtSensors dhtSensor(DHTPIN, DHTTYPE);
WebServer webServer;
uint32_t delayMS;
Measures measures;

void initWifi();

void setup()
{
  Serial.begin(115200);

  dhtSensor.init();

  MeasuresHandlerFunction measuresHandler = []()
  {
    Measures measures;
    measures.humidity = dhtSensor.humidity;
    measures.temperature = dhtSensor.temperature;

    return measures;
  };

  initWifi();

  webServer.init(measuresHandler);
}

void loop()
{
  dhtSensor.updateSensors();

  delay(UPDATE_MS);
}

void initWifi()
{
  if (WIFI_AP_MODE)
  {
    wifiHandler.apMode(WIFI_SSID, WIFI_PWD);
  }
  else
  {
    wifiHandler.connect(WIFI_SSID, WIFI_PWD);
  }
}
```
