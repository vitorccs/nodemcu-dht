# NodeMCU DHT Monitor
A NodeMCU project which collects temperature and humidity from DHT sensors and send them to Blynk IOT service.

<img src="https://github.com/vitorccs/nodemcu-dht/assets/9891961/4df5f647-7a65-4737-a752-f45732b97167" width="700">

## Description
This projects requires WiFi connection with an internet link. 
Additionaly, the board also acts a Web server and displays temperature and humidity on a web page.
Note: The time is retrieved from a NTP service. 
<img src="https://github.com/vitorccs/nodemcu-dht/assets/9891961/cd229b49-1690-4b3c-838d-dc9824f74fd7" width="700">

## Components
* 01 - NodeMCU v2 board
* 01 - DHT-11/DHT-22 sensor
* 02 - 1K Ω Resistor - acts as a pull-up resistor
* 01 - Adafruit 128x64 OLED display (SSD1306)

## About PlatformIO IDE
Platform IO is a plugin for Microsoft Visual Studio Code. It is a more robust IDE compared to the official Arduino IDE. It also allows us to easily create our own private libraries and use a more object oriented code.

## About the code
The variales can be changed in the `lib\Globals\Globals.h` 

```c++
// WIFI
#define WIFI_SSID "MY_SSID"
#define WIFI_PWD "MY_PASSWORD"
#define WIFI_AP_MODE false // Access Point mode (no internet connection)

// DHT-XX
#define DHTPIN D5
#define DHTTYPE DHT22
#define UPDATE_MS 1000

// BLYNK
#define BLYNK_TEMPLATE_ID "XXXXXXXXXXXX"
#define BLYNK_TEMPLATE_NAME "XXXXXXXXXXXX"
#define BLYNK_AUTH_TOKEN "XXXXXXXXXXXX"

// OLED
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define SCREEN_ADDRESS 0x3C
```
