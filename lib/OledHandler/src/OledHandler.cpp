#include <OledHandler.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Lambdas.h>

OledHandler::OledHandler(uint8_t screenWith,
                         uint8_t screenHeight,
                         uint8_t screenAddress) : display(screenWith, screenHeight)
{
    address = screenAddress;
}

void OledHandler::init(MeasuresHandlerFn measuresHandler,
                       TimeHandlerFn timeHandler)
{
    this->measuresHandler = measuresHandler;
    this->timeHandler = timeHandler;

    isReady = display.begin(SSD1306_SWITCHCAPVCC, address);

    if (!isReady)
    {
        Serial.println(F("SSD1306 allocation failed"));
        return;
    }

    display.clearDisplay();
    display.setTextColor(WHITE);
}

void OledHandler::printLoading()
{
    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(0, 10);
    display.println("Connecting WiFi...");
    display.display();
}

void OledHandler::printIp(String ip)
{
    display.stopscroll();
    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(0, 15);
    display.println(ip);
    display.display();
}

void OledHandler::printMeasures()
{
    Measures measures = measuresHandler();
    String time = timeHandler();

    // clear display
    display.clearDisplay();

    // display temperature
    display.setTextSize(2);
    display.setCursor(0, 0);
    display.print(time);

    // display temperature
    display.setTextSize(1);
    display.setCursor(0, 35);
    display.print("Temp: ");
    display.setTextSize(2);
    display.setCursor(0, 45);
    display.print(measures.temperature, 1);
    display.setTextSize(1);
    display.cp437(true);
    display.write(167);
    display.setTextSize(2);
    display.print("C");

    // display humidity
    display.setTextSize(1);
    display.setCursor(78, 35);
    display.print("Hum: ");
    display.setTextSize(2);
    display.setCursor(78, 45);
    display.print(measures.humidity, 0);
    display.print("%");

    display.display();
}