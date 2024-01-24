#ifndef NTP_TIMER_H
#define NTP_TIMER_H
#include <WiFiUdp.h>
#include <NtpTimer.h>
#include <TimeLib.h>
#include <ESP8266WiFi.h>

class NtpTimer
{
public:
    static void init();
private:
    static time_t getNtpTime();
    static void sendNTPpacket(IPAddress &address);
};

#endif