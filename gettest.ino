
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>

const char *ssid = "jimmy2";
const char *password = "neways3747";

String serverName = "http://10.100.93.58:8080/water/waterqt.php";

unsigned long lastTime = 0;

unsigned long timerDelay = 1000;

float temperature = 25.26, tdsValue = 185;

void setup()
{
  Serial.begin(115200);

  WiFi.begin(ssid, password);
  Serial.println("Connecting");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());

  Serial.println("Timer set to 5 seconds (timerDelay variable), it will take 5 seconds before publishing the first reading.");
}

void loop()
{
  Serial.println("database");
  if (WiFi.status() == WL_CONNECTED)
  {
    WiFiClient client;
    HTTPClient http;
    http.useHTTP10(true);
    http.begin(client, serverName);
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");
    String httpRequestData = "temperature=";
    httpRequestData += temperature;
    httpRequestData += "&tdsValue=";
    httpRequestData += tdsValue;
    Serial.println(httpRequestData);
    http.addHeader("authorization", "api_pi_12345678!@#$%^&*");
    int httpResponseCode = http.POST(httpRequestData);
    Serial.println(httpResponseCode);
  }
}
