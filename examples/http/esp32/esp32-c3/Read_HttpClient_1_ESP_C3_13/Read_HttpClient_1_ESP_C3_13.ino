/*
  Date: 02.09.2023
  Device: ESP-C3-13
  FCC ID: 2ATPO-ESP-C3-X C3-2M
  Device Doc.: https://docs.ai-thinker.com/_media/esp32/docs/esp-c3-12f_specification.pdf
  Arduino IDE Board Select: ESP32C3 Dev Module
  Arduino IDE CPU Frequency: 160MHZ
  Arduino IDE Flash Size: 2MB
  Arduino IDE Partition Schema: 2MB
  Arduino IDE MacOS Upload Speed: MacOS: 115200, Windows and Linux: 460800

  MacOS Boud Rate Error:
    18:15:51.714 -> ESP-ROM:esp32c3-api1-20210207
    18:15:51.714 -> Build:Feb  7 2021
    18:15:51.714 -> rst:0x1 (POWERON),boot:0xc (SPI_FAST_FLASH_BOOT)
    18:15:51.714 -> SPIWP:0xee
    18:15:51.714 -> mode:QIO, clock div:1
    18:15:51.714 -> load:0x3fcd5810,len:0x438
    18:15:51.714 -> ets_loader.c 78 
 */

#include <WiFi.h>
#include <WiFiMulti.h>

#include <HTTPClient.h>

#include <Arduino_JSON.h>

WiFiMulti wifiMulti;

const int red = 3;
const int green = 4;
const int blue = 5;
const int cold_white = 18;
const int warm_white = 19;

void setup() {

  Serial.begin(115200);
  while (!Serial) { delay(100); }

  Serial.println();
  Serial.println("******************************************************");
  Serial.print("Connecting to ");

  wifiMulti.addAP("ssid", "password");

  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(cold_white, OUTPUT);
  pinMode(warm_white, OUTPUT);

  Serial.println("");

}  // setup


void loop() {

  if ((wifiMulti.run() == WL_CONNECTED)) {

    // HTTP Device Data List
    // # 100 - Demo Data HTTP-100
    // https://iothook.com/en/device/data/100/
    // Device Read API Key	b5d91b83c85276cddc84eb67
    // Read Device Data	https://iothook.com/api/device/?api_key=b5d91b83c85276cddc84eb67&results=2
    // Device Write API Key	9e722c4fc6c834b15ba01e86
    // Write Device Data	https://iothook.com/api/update/?api_key=9e722c4fc6c834b15ba01e86&field_1=10

    HTTPClient http;

    String serverPath = "http://iothook.com/api/device/?api_key=b5d91b83c85276cddc84eb67&results=1&format=json";

    http.begin(serverPath);

    int httpCode = http.GET();
    Serial.println(httpCode);

    if (httpCode > 0) {

      String payload = http.getString();

      JSONVar myObject = JSON.parse(payload);

      if (JSON.typeof(myObject) == "undefined") {
        Serial.println("Parsing input failed!");
        return;
      }

      Serial.println(myObject);
      JSONVar keys = myObject.keys();

      Serial.println(myObject[0]["field_1"]);
      Serial.println(myObject[0]["field_2"]);
      Serial.println(myObject[0]["field_3"]);
      Serial.println(myObject[0]["field_4"]);
      Serial.println(myObject[0]["field_5"]);
      Serial.println(myObject[0]["field_6"]);
      Serial.println(myObject[0]["field_7"]);
      Serial.println(myObject[0]["field_8"]);

      if (myObject[0]["field_1"] != null) {
        String answer = myObject[0]["field_1"];
        int field_1 = answer.toInt();
        Serial.print("field_1: ");
        Serial.println(field_1);
        analogWrite(red, field_1);
      }
      if (myObject[0]["field_2"] != null) {
        String answer = myObject[0]["field_2"];
        int field_2 = answer.toInt();
        Serial.print("field_2: ");
        Serial.println(field_2);
        analogWrite(green, field_2);
      }
      if (myObject[0]["field_3"] != null) {
        String answer = myObject[0]["field_3"];
        int field_3 = answer.toInt();
        Serial.print("field_3: ");
        Serial.println(field_3);
        analogWrite(blue, field_3);
      }
      if (myObject[0]["field_4"] != null) {
        String answer = myObject[0]["field_4"];
        int field_4 = answer.toInt();
        Serial.print("field_4: ");
        Serial.println(field_4);
        analogWrite(cold_white, field_4);
      }
      if (myObject[0]["field_5"] != null) {
        String answer = myObject[0]["field_5"];
        int field_5 = answer.toInt();
        Serial.print("field_5: ");
        Serial.println(field_5);
        analogWrite(warm_white, field_5);
      }
      if (myObject[0]["field_6"] != null) {
        String answer = myObject[0]["field_6"];
        int field_6 = answer.toInt();
        Serial.print("field_6: ");
        Serial.println(field_6);
      }
      if (myObject[0]["field_7"] != null) {
        String answer = myObject[0]["field_7"];
        int field_7 = answer.toInt();
        Serial.print("field_7: ");
        Serial.println(field_7);
      }
      if (myObject[0]["field_8"] != null) {
        String answer = myObject[0]["field_8"];
        int field_8 = answer.toInt();
        Serial.print("field_8: ");
        Serial.println(field_8);
      }


    } else {
      Serial.print("Error code: ");
      Serial.println(httpCode);
    }

    http.end();
  }

  delay(5000);

}  // loop
