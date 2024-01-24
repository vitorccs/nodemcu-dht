#include <WiFiUdp.h>
#include <NtpTimer.h>
#include <TimeLib.h>
#include <ESP8266WiFi.h>

// NTP Servers:
static const char ntpServerName[] = "us.pool.ntp.org";
// static const char ntpServerName[] = "time.nist.gov";
// static const char ntpServerName[] = "time-a.timefreq.bldrdoc.gov";
// static const char ntpServerName[] = "time-b.timefreq.bldrdoc.gov";
// static const char ntpServerName[] = "time-c.timefreq.bldrdoc.gov";

const int timeZone = 1; // Central European Time
// const int timeZone = -5;  // Eastern Standard Time (USA)
// const int timeZone = -4;  // Eastern Daylight Time (USA)
// const int timeZone = -8;  // Pacific Standard Time (USA)
// const int timeZone = -7;  // Pacific Daylight Time (USA)

// NTP time is in the first 48 bytes of message
const int NTP_PACKET_SIZE = 48;

// buffer to hold incoming & outgoing packets
byte packetBuffer[NTP_PACKET_SIZE];

// local port to listen for UDP packets
unsigned int localPort = 8888;
unsigned int currAttempt = 0;
unsigned int maxAttempts = 5;

time_t getNtpTime();

WiFiUDP Udp;


void NtpTimer::init()
{
    Udp.begin(localPort);

    setSyncProvider(getNtpTime);
    setSyncInterval(300);
}


time_t NtpTimer::getNtpTime()
{
    IPAddress ntpServerIP; // NTP server's ip address

    while (Udp.parsePacket() > 0)
    {
        // discard any previously received packets
    }

    Serial.println("Transmit NTP Request");

    // get a random server from the pool
    WiFi.hostByName(ntpServerName, ntpServerIP);
    Serial.print(ntpServerName);
    Serial.print(": ");
    Serial.println(ntpServerIP);
    sendNTPpacket(ntpServerIP);

    uint32_t beginWait = millis();

    while (millis() - beginWait < 1500)
    {
        int size = Udp.parsePacket();
        
        if (size >= NTP_PACKET_SIZE)
        {
            Serial.println("Receive NTP Response");
            Udp.read(packetBuffer, NTP_PACKET_SIZE); // read packet into the buffer
            unsigned long secsSince1900;
            // convert four bytes starting at location 40 to a long integer
            secsSince1900 = (unsigned long)packetBuffer[40] << 24;
            secsSince1900 |= (unsigned long)packetBuffer[41] << 16;
            secsSince1900 |= (unsigned long)packetBuffer[42] << 8;
            secsSince1900 |= (unsigned long)packetBuffer[43];
            return secsSince1900 - 2208988800UL + timeZone * SECS_PER_HOUR;
        }
    }

    if (currAttempt < maxAttempts) {
        Serial.println("NTP retrying...");

        return getNtpTime();
    }

    Serial.println("No NTP Response :-(");

    return 0; // return 0 if unable to get the time
}

void NtpTimer::sendNTPpacket(IPAddress &address)
{
    // set all bytes in the buffer to 0
    memset(packetBuffer, 0, NTP_PACKET_SIZE);

    // Initialize values needed to form NTP request
    // (see URL above for details on the packets)

    packetBuffer[0] = 0b11100011; // LI, Version, Mode
    packetBuffer[1] = 0;          // Stratum, or type of clock
    packetBuffer[2] = 6;          // Polling Interval
    packetBuffer[3] = 0xEC;       // Peer Clock Precision

    // 8 bytes of zero for Root Delay & Root Dispersion
    packetBuffer[12] = 49;
    packetBuffer[13] = 0x4E;
    packetBuffer[14] = 49;
    packetBuffer[15] = 52;

    // all NTP fields have been given values, now
    // you can send a packet requesting a timestamp:
    Udp.beginPacket(address, 123); // NTP requests are to port 123
    Udp.write(packetBuffer, NTP_PACKET_SIZE);
    Udp.endPacket();
}