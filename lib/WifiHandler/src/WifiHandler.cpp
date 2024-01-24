#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <WifiHandler.h>

IPAddress WifiHandler::connect(const char *ssid,
                               const char *pwd)
{
    WiFi.begin(ssid, pwd);

    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }

    const IPAddress ip = WiFi.localIP();

    debug(ssid, ip, false);

    return ip;
}

IPAddress WifiHandler::apMode(const char *ssid,
                              const char *pwd,
                              int channel)
{
    WiFi.softAP(ssid, pwd, channel);

    const IPAddress ip = WiFi.softAPIP();

    debug(ssid, ip, true);

    return ip;
}

IPAddress WifiHandler::init(const char *ssid,
                            const char *pwd,
                            bool isApMode,
                            int channel)
{
    if (isApMode)
    {
        return apMode(ssid, pwd, channel);
    }
    else
    {
        return connect(ssid, pwd);
    }
}

void WifiHandler::debug(const char *ssid,
                        IPAddress ip,
                        bool apMode)
{
    Serial.println("");

    if (apMode)
    {
        Serial.print("AP Mode connected at ");
    }
    else
    {
        Serial.print("Wi-Fi connected at ");
    }

    Serial.println(ssid);
    Serial.print("http://");
    Serial.println(ip);
}
