#include <Arduino.h>
#include <Globals.h>
#include <DHT.h>
#include <DhtSensors.h>
#include <WifiHandler.h>
#include <OledHandler.h>
#include <BlynkHandler.h>
#include <WebServer.h>
#include <Lambdas.h>
#include <NtpTimer.h>

WifiHandler wifiHandler;
DhtSensors dhtSensor(DHTPIN, DHTTYPE);
OledHandler oledHandler(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_ADDRESS);
WebServer webServer;
uint32_t delayMS;
Measures measures;
BlynkHandler blynkHandler;
NtpTimer ntpTimer;

void setup()
{
  MeasuresHandlerFn measuresHandler = []()
  {
    Measures measures;
    measures.humidity = dhtSensor.humidity;
    measures.temperature = dhtSensor.temperature;

    return measures;
  };

  TimeHandlerFn TimeHandlerFn = []()
  {
    char buffer[20];
    sprintf(buffer, "%02d/%02d/%02d %02d:%02d:%02d", day(), month(), year(), hour(), minute(), second());
    return String(buffer);
  };

  Serial.begin(115200);

  oledHandler.init(measuresHandler,
                   TimeHandlerFn);

  oledHandler.printLoading();

  dhtSensor.init();

  const IPAddress ip = wifiHandler.connect(WIFI_SSID,
                                           WIFI_PWD);

  oledHandler.printIp(ip.toString());

  webServer.init(measuresHandler);

  blynkHandler.init(BLYNK_AUTH_TOKEN,
                    measuresHandler,
                    BLYNK_UPDATE);

  ntpTimer.init();

  delay(DELAY_INIT);
}

void loop()
{
  delay(DELAY_REFRESH);

  dhtSensor.updateSensors();

  blynkHandler.run();

  oledHandler.printMeasures();
}
