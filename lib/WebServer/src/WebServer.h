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
    void init(MeasuresHandlerFn measuresHandler,
              TimeHandlerFn TimeHandlerFn);

private:
    String getHtmlPage(Measures measures, String time);
    String getJsonString(Measures measures, String time);
    AsyncWebServer webServer;
};
#endif