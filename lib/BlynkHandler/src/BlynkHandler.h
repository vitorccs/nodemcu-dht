#ifndef BLYNK_HANDLER_H
#define BLYNK_HANDLER_H
#include <Measures.h>
#include <Lambdas.h>
#include <Blynk/BlynkTimer.h>

class BlynkHandler
{
public:
    void init(const char *authToken,
              MeasuresHandlerFn measuresHandler,
              long timer = 5000L);
    void run();
    void temperatureAlert(MeasuresHandlerFn measuresHandler,
                          float temperature,
                          String eventName,
                          String message,
                          long timer = 5000L);
    void humidityAlert(MeasuresHandlerFn measuresHandler,
                       float humidity,
                       String eventName,
                       String message,
                       long timer = 5000L);

private:
    BlynkTimer updaterTimer;
    BlynkTimer temperatureTimer;
    BlynkTimer humidityTimer;
};

#endif