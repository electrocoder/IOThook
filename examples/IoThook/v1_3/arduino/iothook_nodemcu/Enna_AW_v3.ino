// 30.11.2017
// nodemcu ile sicaklik ve nem takibi
// electrocoder
// sahin@mesebilisim.com
// sahin mersin
// v3

#include <ESP8266WiFi.h>          //https://github.com/esp8266/Arduino

#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>          //https://github.com/tzapu/WiFiManager

#include <ESP8266HTTPClient.h>

#include "DHT.h"

#define DHTPIN 4     // D2 - GPIO4
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);


void configModeCallback (WiFiManager *myWiFiManager) {
  Serial.println("Ayarlar");
  Serial.println(WiFi.softAPIP());

  Serial.println(myWiFiManager->getConfigPortalSSID());
}


void setup() {
  Serial.begin(115200);

  WiFiManager wifiManager;
  //reset ayari
  //wifiManager.resetSettings();

  wifiManager.setAPCallback(configModeCallback);

  if (!wifiManager.autoConnect("MeseIoT", "MeseIoT**")) {
    Serial.println("Zaman asimi hatasi");

    ESP.reset();
    delay(1000);
  }

  Serial.println("Baglanti saglandi");

  dht.begin();
}


void loop() {
  delay(2000);

  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);

  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("DHT hatasi!");
    return;
  }

  float hif = dht.computeHeatIndex(f, h);
  float hic = dht.computeHeatIndex(t, h, false);

  Serial.println("\n*****************************************************************");

  Serial.print("Nem: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Sicaklik: ");
  Serial.print(t);
  Serial.print(" *C ");
  Serial.print(f);
  Serial.print(" *F\t");
  Serial.print("Heat index: ");
  Serial.print(hic);
  Serial.print(" *C ");
  Serial.print(hif);
  Serial.println(" *F");

  Serial.println("\n*****************************************************************");

  HTTPClient http;

  http.begin("http://iothook.com/api/latest/datas/update/?api_key=API_KEY&value_1=" + String(t) + "&value_2=" + String(h) + "");

  int httpCode = http.GET();
  if (httpCode > 0) {
    Serial.printf("[HTTP] GET... Return: %d\n", httpCode);

    if (httpCode == HTTP_CODE_OK) {

      int len = http.getSize();

      uint8_t buff[128] = { 0 };

      WiFiClient * stream = http.getStreamPtr();

      while (http.connected() && (len > 0 || len == -1)) {
        size_t size = stream->available();

        if (size) {
          // read up to 128 byte
          int c = stream->readBytes(buff, ((size > sizeof(buff)) ? sizeof(buff) : size));

          Serial.write(buff, c);

          if (len > 0) {
            len -= c;
          }
        }
        delay(1);
      }

    }
  } else {
    Serial.printf("[HTTP] GET... Hata...: %s\n", http.errorToString(httpCode).c_str());
  }

  http.end();
  delay(13000);
}

