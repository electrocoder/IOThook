// 30.07.2020
// Wifi Elektrik Kontrol
// electrocoder@gmail.com
// sahin mersin
// v1
// mesebilisim.com

#include <ESP8266WiFi.h>          //https://github.com/esp8266/Arduino

#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>          //https://github.com/tzapu/WiFiManager

#include <Ticker.h>

#include <ESP8266HTTPClient.h>

Ticker ticker;

void tick()
{
  int state = digitalRead(BUILTIN_LED);  // get the current state of GPIO1 pin
  digitalWrite(BUILTIN_LED, !state);     // set pin to the opposite state
}


void configModeCallback (WiFiManager *myWiFiManager) {
  Serial.println("Entered config mode");
  Serial.println(WiFi.softAPIP());
  //if you used auto generated SSID, print it
  Serial.println(myWiFiManager->getConfigPortalSSID());
  //entered config mode, make led toggle faster
  ticker.attach(0.2, tick);
}


void setup() {
  Serial.begin(115200);

  pinMode(BUILTIN_LED, OUTPUT);

  ticker.attach(0.6, tick);

  WiFiManager wifiManager;
  //reset settings - for testing
  //wifiManager.resetSettings();

  wifiManager.setAPCallback(configModeCallback);

  if (!wifiManager.autoConnect("MeseIoT", "MeseIoT**")) {
    Serial.println("failed to connect and hit timeout");
    ESP.reset();
    delay(1000);
  }

  Serial.println("connected...yeey :)");
  ticker.detach();
  //keep LED on
  digitalWrite(BUILTIN_LED, LOW);

}


void loop() {
  delay(2000);

  HTTPClient http;

  http.begin("http://iothook.com/api/update/?api_key=1274db1febddee135c5d26042&field_1=1");

  Serial.print("[HTTP] GET...\n");

  int httpCode = http.GET();
  if (httpCode > 0) {

    Serial.printf("[HTTP] GET... code: %d\n", httpCode);

    if (httpCode == HTTP_CODE_OK) {

      int len = http.getSize();

      uint8_t buff[128] = { 0 };

      WiFiClient * stream = http.getStreamPtr();

      while (http.connected() && (len > 0 || len == -1)) {

        size_t size = stream->available();

        if (size) {
          int c = stream->readBytes(buff, ((size > sizeof(buff)) ? sizeof(buff) : size));

          Serial.write(buff, c);

          if (len > 0) {
            len -= c;
          }
        }
        delay(1);
      }

      Serial.println();
      Serial.print("[HTTP] connection closed or file end.\n");

    }
  } else {
    Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
  }

  http.end();

  delay(13000);
}
