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
