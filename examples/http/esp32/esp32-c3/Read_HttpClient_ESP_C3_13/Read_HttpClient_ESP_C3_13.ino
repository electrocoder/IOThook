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


void readResponse(WiFiClient *client){
  unsigned long timeout = millis();
  while(client->available() == 0){
    if(millis() - timeout > 5000){
      Serial.println(">>> Client Timeout !");
      client->stop();
      return;
    }
  }

  // Read all the lines of the reply from server and print them to Serial
  while(client->available()) {
    String line = client->readStringUntil('\r');
    Serial.print(line);
  }

  Serial.printf("\nClosing connection\n\n");
}


void loop() {

  WiFiClient client;

  if (!client.connect(host, httpPort)) {
    return;
  }

  String footer = String(" HTTP/1.1\r\n") + "Host: " + String(host) + "\r\n" + "Connection: close\r\n\r\n";

  // HTTP Device Data List
  // # 100 - Demo Data HTTP-100
  // https://iothook.com/en/device/data/100/
  // Device Read API Key	b5d91b83c85276cddc84eb67
  // Read Device Data	https://iothook.com/api/device/?api_key=b5d91b83c85276cddc84eb67&results=2
  // Device Write API Key	9e722c4fc6c834b15ba01e86
  // Write Device Data	https://iothook.com/api/update/?api_key=9e722c4fc6c834b15ba01e86&field_1=10

  client.print("GET /api/device/?api_key=b5d91b83c85276cddc84eb67&results=1&format=json" + footer);

  readResponse(&client);

  Serial.println("read ok");

  delay(5000);

} // loop
