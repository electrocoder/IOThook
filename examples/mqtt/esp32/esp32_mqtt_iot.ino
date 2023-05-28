/*
  Test
  24.04.2023
  ESP32-WROOM-32D Wifi Bluetooth Development Module

  REQUIRES the following Arduino libraries:
  DHT Sensor Library: https://github.com/adafruit/DHT-sensor-library
  Adafruit Unified Sensor Lib: https://github.com/adafruit/Adafruit_Sensor
  HX711 https://github.com/bogde/HX711
  Mqtt : https://github.com/256dpi/arduino-mqtt?ysclid=leihxfhhq6294250283
*/


#include <WiFi.h>
#include <MQTT.h>
#include "HX711.h"

#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN 23
#define DHTTYPE DHT21

DHT_Unified dht(DHTPIN, DHTTYPE);

const char ssid[] = "SSID";
const char pass[] = "PASS";

WiFiClient net;
MQTTClient client;

const char BROKER[] = "iothook.com";
const char BROKERUSERNAME[] = "iothookpublic";
const char BROKERPASSWORD[] = "iothookpublic";

const char PUBTOPIC[] = "iot/ofis/esp32test/r";
const char SUBTOPIC[] = "iot/ofis/esp32test/w/ID_1";

const char UID[] = "UID001";


const int LED_BUILTIN = 2;

const int ldr = A0;

unsigned long lastMillis = 0;

#define DEBUG 1


void messageReceived(String &topic, String &payload) {

  if (DEBUG) Serial.println("messageReceived: " + topic + " - " + payload);

  String messageTemp;

  for (int i = 0; i < payload.length(); i++) {
    // Serial.print((char)payload[i]);
    messageTemp += (char)payload[i];
  }

  if (messageTemp == "led:on") {
    Serial.println(" led on ");
    digitalWrite(LED_BUILTIN, HIGH);
  } else if (messageTemp == "led:off") {
    Serial.println(" led off ");
    digitalWrite(LED_BUILTIN, LOW);
  }

}  // messageReceived


void setup() {

  Serial.begin(115200);

  pinMode(LED_BUILTIN, OUTPUT);

  WiFi.begin(ssid, pass);

  client.begin(BROKER, net);

  client.onMessage(messageReceived);

  connect();

  delay(100);

}  // setup


void connect() {

  Serial.print("checking wifi...");
  while (WiFi.status() != WL_CONNECTED) {
    if (DEBUG) Serial.print(".");
    delay(1000);
  }

  Serial.print("\nconnecting...");
  while (!client.connect(UID, BROKERUSERNAME, BROKERPASSWORD)) {
    if (DEBUG) Serial.print(".");
    delay(1000);
  }

  Serial.println("\nconnected!");

  client.subscribe(SUBTOPIC);

}  // connect


void loop() {

  client.loop();
  delay(10);

  if (!client.connected()) {
    delay(5000);
    connect();
  }

  if (millis() - lastMillis > 1000) {
    lastMillis = millis();
    send_data();
  }

  delay(100);

}  // loop


void send_data() {

  float field_1 = random(0, 2000);

  int isik = analogRead(ldr);

  String veriler = "{'weight':" + String(field_1) + ",'temperature':" + String(field_1) + ",'humidity':" + String(field_1) + ",'image':1,'ldr':" + String(isik) + ",'device_id':" + UID + "}";
  if (DEBUG) Serial.println("send_data " + veriler);

  client.publish(PUBTOPIC, veriler);

}  // send_data
