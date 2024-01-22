#ifndef WEB_SERVER_H
#define WEB_SERVER_H
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <Measures.h>

typedef std::function<Measures()> MeasuresHandlerFunction;

class WebServer
{
public:
    WebServer();
    void init(MeasuresHandlerFunction measuresHandler);
private:
    String getHtmlPage(Measures measures);
    AsyncWebServer webServer;
};
#endif