#ifndef WEB_SERVER_H
#define WEB_SERVER_H
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <Measures.h>
#include <Lambdas.h>

class WebServer
{
public:
    WebServer();
    void init(MeasuresHandlerFn measuresHandler);
private:
    String getHtmlPage(Measures measures);
    AsyncWebServer webServer;
};
#endif