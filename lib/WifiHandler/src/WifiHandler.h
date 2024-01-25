#ifndef WIFI_HANDLER_H
#define WIFI_HANDLER_H
#include <ESP8266WiFi.h>

class WifiHandler
{
public:
    IPAddress connect(const char *ssid, const char *pwd);
    IPAddress apMode(const char *ssid, const char *pwd, int channel = 1);
    IPAddress init(const char *ssid, const char *pwd, bool isApMode, int channel = 1);
    void debug(const char *ssid, IPAddress ip, bool apMode);
};
#endif