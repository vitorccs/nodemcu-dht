#include <WebServer.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <Measures.h>
#include <Lambdas.h>

WebServer::WebServer() : webServer(80)
{
}

void WebServer::init(MeasuresHandlerFn measuresHandler,
                     TimeHandlerFn TimeHandlerFn)
{
  ArRequestHandlerFunction onWebRequest = [measuresHandler, TimeHandlerFn, this](AsyncWebServerRequest *request)
  {
    Measures measures = measuresHandler();
    String time = TimeHandlerFn();

    request->send(200, "text/html", getHtmlPage(measures, time));
  };

  ArRequestHandlerFunction onApiRequest = [measuresHandler, TimeHandlerFn, this](AsyncWebServerRequest *request)
  {
    Measures measures = measuresHandler();
    String time = TimeHandlerFn();

    request->send(200, "application/json", getJsonString(measures, time));
  };

  webServer.on("/", HTTP_GET, onWebRequest);
  webServer.on("/api", HTTP_GET, onApiRequest);

  webServer.begin();

  Serial.println("HTTP Server ready");
}

String WebServer::getHtmlPage(Measures measures,
                              String time)
{
  const int refreshRate = 5;

  String html = "<!DOCTYPE html> <html>\n";
  html += "<head><meta charset=\"utf-8\">";
  html += "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=no\">\n";
  html += "<meta http-equiv='refresh' content='" + String(refreshRate) + "'>";
  html += "<title>Temperature & Humidity Monitor</title>\n";

  html += "<style>html { font-family: 'Open Sans', 'Arial', sans-serif; display: block; margin: 0px auto; text-align: center;color: #000000;}\n";
  html += "body {margin-top: 50px; color: darkblue;}\n";
  html += "h1 {margin: 50px auto 30px;}\n";
  html += "h2 {margin: 40px auto 20px; color: #555;}\n";
  html += "h3 {margin: 40px auto 5px; text-transform: uppercase;}\n";
  html += "p {font-size: 24px;color: #000000;margin: 10px;}\n";
  html += "</style>\n";
  html += "</head>\n";
  html += "<body>\n";
  html += "<div id=\"webpage\">\n";
  html += "<h1>Temperature & Humidity Monitor</h1>\n";
  html += "<h2>NODEMCU ESP8266 Web Server</h2>\n";

  html += "<h3>Time:</h3>";
  html += "<p>" + time + "</p>";

  html += "<h3>Temperature:</h3>";
  html += "<p>" + String(measures.temperature) + "°C</p>";

  html += "<h3>Humidity:</h3>";
  html += "<p>" + String(measures.humidity) + "%</p>";

  html += "</div>\n";
  html += "</body>\n";
  html += "</html>\n";

  return html;
}

String WebServer::getJsonString(Measures measures,
                                String time)
{

  String json = "{";
  json += "\"temperature\": " + String(measures.temperature) + ",";
  json += "\"humidity\": " + String(measures.humidity) + ",";
  json += "\"time\": \"" + time + "\"";
  json += "}";

  return json;
}
