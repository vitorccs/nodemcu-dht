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
//#define NTP_TIME_ZONE -5  // Eastern Standard Time (USA)
//#define NTP_TIME_ZONE -4  // Eastern Daylight Time (USA)
//#define NTP_TIME_ZONE -8  // Pacific Standard Time (USA)
//#define NTP_TIME_ZONE -7  // Pacific Daylight Time (USA)
#define NTP_SERVER_NAME "us.pool.ntp.org"
//#define NTP_SERVER_NAME "time.nist.gov"
//#define NTP_SERVER_NAME "time-a.timefreq.bldrdoc.gov"
//#define NTP_SERVER_NAME "time-b.timefreq.bldrdoc.gov"
//#define NTP_SERVER_NAME "time-c.timefreq.bldrdoc.gov"