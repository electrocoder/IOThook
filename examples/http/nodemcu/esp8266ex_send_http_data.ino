/**
   esp8266ex_send_http_data.ino

   sahin mersin

   https://github.com/electrocoder/IOThook/tree/master/examples

   iothook.com
   mesebilisim.com

   https://github.com/esp8266/Arduino Created on: 24.05.2015
*/

#include <Arduino.h>

#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>

#include <ESP8266HTTPClient.h>

#include <WiFiClient.h>

ESP8266WiFiMulti WiFiMulti;

const int led = 2;

void setup() {

  Serial.begin(115200);
  // Serial.setDebugOutput(true);

  Serial.println();
  Serial.println();
  Serial.println();

  for (uint8_t t = 4; t > 0; t--) {
    Serial.printf("[SETUP] WAIT %d...\n", t);
    Serial.flush();
    delay(1000);
  }

  pinMode(led, OUTPUT);

  WiFi.mode(WIFI_STA);
  WiFiMulti.addAP("SSID", "PASS");
}

void loop() {
  // wait for WiFi connection
  if ((WiFiMulti.run() == WL_CONNECTED)) {

  digitalWrite(led, 1);

    WiFiClient client;

    HTTPClient http;

    Serial.print("[HTTP] begin...\n");

    float t = 12.34; // example value
    float h = 45.67; // example value

    // https://iothook.com/en/device/data/100/
    // # 100 - Demo Data HTTP-100

    String address = "http://iothook.com/api/update/?api_key=9e722c4fc6c834b15ba01e86&field_1=" + String(t) + "&field_2=" + String(h);
    Serial.println(address);

    if (http.begin(client, address)) {  // HTTP


      Serial.print("[HTTP] GET...\n");
      // start connection and send HTTP header
      int httpCode = http.GET();

      // httpCode will be negative on error
      if (httpCode > 0) {
        // HTTP header has been send and Server response header has been handled
        Serial.printf("[HTTP] GET... code: %d\n", httpCode);

        // file found at server
        if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
          String payload = http.getString();
          Serial.println(payload);
        }
      } else {
        Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
      }

      http.end();
    } else {
      Serial.println("[HTTP] Unable to connect");
    }
  }

  digitalWrite(led, 0);

  delay(10000);
}
