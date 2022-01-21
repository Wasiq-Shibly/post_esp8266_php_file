
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>

const char* ssid = "jimmy2";
const char* password = "neways3747";

//Your Domain name with URL path or IP address with path
const char* serverName = "http://10.100.93.58:8080/water/waterqt.php?";

unsigned long lastTime = 0;

unsigned long timerDelay = 5000;

void setup() {
  Serial.begin(115200);

  WiFi.begin(ssid, password);
  Serial.println("Connecting");
  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());
 
 
}

void loop() 

 
 {
 
    if(WiFi.status()== WL_CONNECTED){


      
      WiFiClient client;
      HTTPClient http;
      http.begin(client, serverName);
      http.addHeader("Content-Type", "application/x-www-form-urlencoded");
      String httpRequestData = "temperature=24.25&tdsValue=500.85";           
      int httpResponseCode = http.POST(httpRequestData);
      Serial.print("HTTP Response code: ");
      Serial.println(httpResponseCode);
      String payload = http.getString();
      Serial.println(payload);
      http.end();
      
    }
    else {
      Serial.println("WiFi Disconnected");
    }

}
