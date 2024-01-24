#ifndef NTP_TIMER_H
#define NTP_TIMER_H
#include <WiFiUdp.h>
#include <NtpTimer.h>
#include <TimeLib.h>
#include <ESP8266WiFi.h>

class NtpTimer
{
public:
    static void init(int zone, String server);
    static int timeZone;
    static String serverName;
    static unsigned int currAttempt;
    static unsigned int maxAttempts;
    static unsigned int localPort;
    static WiFiUDP Udp;
private:
    static time_t getNtpTime();
    static void sendNTPpacket(IPAddress &address);
};

#endif