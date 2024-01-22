#include <WebServer.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>

WebServer::WebServer(): webServer(80)
{
}

void WebServer::init(MeasuresHandlerFunction measuresHandler)
{
    ArRequestHandlerFunction onRequest = [measuresHandler, this](AsyncWebServerRequest *request)
    {
        Measures measures = measuresHandler();

        request->send(200, "text/html", getHtmlPage(measures));
    };

    webServer.on("/", HTTP_GET, onRequest);
    
    webServer.begin();

    Serial.println("HTTP Server ready");
}

String WebServer::getHtmlPage(Measures measures)
{
  const int refreshRate = 2;

  String ptr = "<!DOCTYPE html> <html>\n";
  ptr += "<head><meta charset=\"utf-8\">";
  ptr += "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=no\">\n";
  ptr += "<meta http-equiv='refresh' content='" + String(refreshRate) + "'>";
  ptr += "<link href=\"https://fonts.googleapis.com/css?family=Open+Sans:300,400,600\" rel=\"stylesheet\">\n";
  ptr += "<title>Temperature & Humidity Monitor</title>\n";

  ptr += "<style>html { font-family: 'Open Sans', sans-serif; display: block; margin: 0px auto; text-align: center;color: #000000;}\n";
  ptr += "body{margin-top: 50px;}\n";
  ptr += "h1 {margin: 50px auto 30px;}\n";
  ptr += "h2 {margin: 40px auto 20px;}\n";
  ptr += "p {font-size: 24px;color: #000000;margin-bottom: 10px;}\n";
  ptr += "</style>\n";
  ptr += "</head>\n";
  ptr += "<body>\n";
  ptr += "<div id=\"webpage\">\n";
  ptr += "<h1>Temperature & Humidity Monitor</h1>\n";
  ptr += "<h2>NODEMCU ESP8266 Web Server</h2>\n";

  ptr += "<p><b>Temperature: </b>";
  ptr += String(measures.temperature);
  ptr += " °C</p>";
  ptr += "<p><b>Humidity: </b>";
  ptr += String(measures.humidity);
  ptr += " %</p>";

  ptr += "</div>\n";
  ptr += "</body>\n";
  ptr += "</html>\n";

  return ptr;
}
