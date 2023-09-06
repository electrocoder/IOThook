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

  BasicHTTPClient.ino
  Created on: 24.05.2015

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

const char* ssid = "ssid";       // Change this to your WiFi SSID
const char* password = "password";  // Change this to your WiFi password

const char* host = "iothook.com";  // This should not be changed
const int httpPort = 80;           // This should not be changed

void setup() {

  Serial.begin(115200);
  while (!Serial) { delay(100); }

  Serial.println();
  Serial.println("******************************************************");
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

} // setup


void loop() {

  WiFiClient client;

  if (!client.connect(host, httpPort)) {
    return;
  }

  float field_1 = random(100);

  String footer = String(" HTTP/1.1\r\n") + "Host: " + String(host) + "\r\n" + "Connection: close\r\n\r\n";

  // HTTP Device Data List
  // # 100 - Demo Data HTTP-100
  // https://iothook.com/en/device/data/100/
  // Device Read API Key	b5d91b83c85276cddc84eb67
  // Read Device Data	https://iothook.com/api/device/?api_key=b5d91b83c85276cddc84eb67&results=2
  // Device Write API Key	9e722c4fc6c834b15ba01e86
  // Write Device Data	https://iothook.com/api/update/?api_key=9e722c4fc6c834b15ba01e86&field_1=10

  client.print("GET /api/update/?api_key=9e722c4fc6c834b15ba01e86&field_1=" + String(field_1) + footer);

  Serial.println(String(field_1) + " send ok");

  int maxloops = 0;
  //wait for the server's reply to become available
  while (!client.available() && maxloops < 1000)
  {
    maxloops++;
    delay(1); //delay 1 msec
  }
  if (client.available() > 0)
  {
    //read back one line from the server
    String line = client.readStringUntil('\r');
    Serial.println(line);
  }
  else
  {
    Serial.println("client.available() timed out ");
  }

  delay(5000);

} // loop
