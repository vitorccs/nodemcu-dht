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

private:
    BlynkTimer blynkTimer;
};

#endif