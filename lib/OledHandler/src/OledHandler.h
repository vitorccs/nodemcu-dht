#ifndef OLED_HANDLER_H
#define OLED_HANDLER_H
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Lambdas.h>

class OledHandler
{
public:
    OledHandler(uint8_t screenWith,
                uint8_t screenHeight,
                uint8_t screenAddress);
    void init(MeasuresHandlerFn measuresHandler,
              TimeHandlerFn timeHandler);
    void printMeasures();
    void printLoading();
    void printIp(String ip);

private:
    Adafruit_SSD1306 display;
    MeasuresHandlerFn measuresHandler;
    TimeHandlerFn timeHandler;
    uint8_t address;
    bool isReady;
};

#endif