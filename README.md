# NodeMCU DHT Monitor
A NodeMCU project which collects temperature and humidity from DHT sensors and send them to Blynk IOT service.

### Web server (http://192.168.0.1 - your LAN address)
<img src="https://github.com/vitorccs/nodemcu-dht/assets/9891961/0989e5f9-bb6d-4c2a-a4c5-92a22b60c720" width="700">

### Web server (http://192.168.0.1/api - your LAN address)
<img src="https://github.com/vitorccs/nodemcu-dht/assets/9891961/7c8b8e6a-5581-4217-a500-0537d35a7185" width="300">

### Blynk Dashboard
<img src="https://github.com/vitorccs/nodemcu-dht/assets/9891961/136471e9-8338-46af-8666-9a470d22a7bf" width="300">


## Description
This projects requires WiFi connection with an internet link. 
Additionaly, the board also acts a Web server and displays temperature and humidity in both HTML and JSON format (/api).
Note: The time is retrieved from a NTP service. 

<img src="https://github.com/vitorccs/nodemcu-dht/assets/9891961/bb293e60-6506-4d28-8bb6-851a7543ee0a" width="700">

<img src="https://github.com/vitorccs/nodemcu-dht/assets/9891961/d805e4df-9b90-4da3-99d9-e11f056354d8" width="700">

## Components
* 01 - NodeMCU v2 board
* 01 - DHT-11/DHT-22 sensor
* 01 - 10K Ω Resistor - acts as a pull-up resistor
* 01 - Adafruit 128x64 OLED display (SSD1306)

## About PlatformIO IDE
Platform IO is a plugin for Microsoft Visual Studio Code. It is a more robust IDE compared to the official Arduino IDE. It also allows us to easily create our own private libraries and use a more object oriented code.

## Instructions
In the folder `lib\Globals`, make a copy of file `Globals.sample` to `Globals.h` and change the parameters below. Then compile and upload the project to your NodeMCU board.

```c++
// WIFI
#define WIFI_SSID "MY_SSID"
#define WIFI_PWD "MY_PASSWORD"

// DHT-XX
#define DHTPIN D5
#define DHTTYPE DHT22

// BLYNK
#define BLYNK_TEMPLATE_ID "XXXXXXXXXXXX"
#define BLYNK_TEMPLATE_NAME "XXXXXXXXXXXX"
#define BLYNK_AUTH_TOKEN "XXXXXXXXXXXX"
#define BLYNK_UPDATE 5000

// OLED
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define SCREEN_ADDRESS 0x3C

// DELAYS
#define DELAY_INIT 5000
#define DELAY_REFRESH 1000

// NTP
#define NTP_TIME_ZONE 1 // Central European Time
#define NTP_SERVER_NAME "us.pool.ntp.org"
```

## Fritzing file
The electronic schematic was created in the [Fritzing](https://fritzing.org/) software and can be downloaded at
[NodeMcuDht.zip](https://github.com/vitorccs/nodemcu-dht/files/14054295/NodeMcuDht.zip)
