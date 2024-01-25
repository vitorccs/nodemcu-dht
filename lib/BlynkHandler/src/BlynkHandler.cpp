#include <BlynkHandler.h>
#include <Measures.h>
#include <Lambdas.h>
#include <Blynk/BlynkTimer.h>
#include <Globals.h>
#include <BlynkSimpleEsp8266.h>

void BlynkHandler::init(const char *authToken,
                        MeasuresHandlerFn measuresHandler,
                        long timer)
{
    Blynk.config(authToken);

    updaterTimer.setInterval(timer, [measuresHandler]() {
        Measures measures = measuresHandler();

        Blynk.virtualWrite(V0, measures.temperature);
        Blynk.virtualWrite(V1, measures.humidity); 
    });
}

void BlynkHandler::temperatureAlert(MeasuresHandlerFn measuresHandler,
                                    float temperature,
                                    String eventName,
                                    String message,
                                    long timer)
{
    temperatureTimer.setInterval(timer, [measuresHandler, temperature, eventName, message]() {
        Measures measures = measuresHandler();

        if (measures.temperature > temperature) {
            Blynk.logEvent(eventName, message);
            Serial.println("Alert: " + eventName);
        }
    });
}

void BlynkHandler::humidityAlert(MeasuresHandlerFn measuresHandler,
                                 float humidity,
                                 String eventName,
                                 String message,
                                 long timer)
{
    humidityTimer.setInterval(timer, [measuresHandler, humidity, eventName, message]() {
        Measures measures = measuresHandler();

        if (measures.humidity > humidity)
    {
        Blynk.logEvent(eventName, message);
        Serial.println("Alert: " + eventName);
    }
    });
}

void BlynkHandler::run()
{
    Blynk.run();
    updaterTimer.run();
    temperatureTimer.run();
    humidityTimer.run();
}
