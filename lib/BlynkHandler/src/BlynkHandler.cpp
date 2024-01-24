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

    blynkTimer.setInterval(timer, [measuresHandler]() {
        Measures measures = measuresHandler();

        Blynk.virtualWrite(V0, measures.temperature);
        Blynk.virtualWrite(V1, measures.humidity);
    });
}

void BlynkHandler::run()
{
    Blynk.run();
    blynkTimer.run();
}
