/***********************************************************************
  Thingsboard ESP32C3
  27.11.2023
  https://thingsboard.io/docs/samples/esp32/gpio-control-pico-kit-dht22-sensor/
 **********************************************************************/

#include <WiFi.h>
#include "WiFiClientSecure.h"
#include "Adafruit_MQTT.h"
#include "Adafruit_MQTT_Client.h"

/************************* WiFi Access Point *********************************/
#define WLAN_SSID "WLAN_SSID"
#define WLAN_PASS "WLAN_PASS"

/************************* Server Setup *********************************/
#define MQTT_SERVER "iot.mesebilisim.com"
#define MQTT_SERVER_PORT 1883

#define MQTT_CLIENT_ID "MQTT_CLIENT_ID"
#define MQTT_USERNAME "MQTT_USERNAME"
#define MQTT_PASSWORD "MQTT_PASSWORD"

WiFiClient wifi_client;

Adafruit_MQTT_Client mqtt_client(&wifi_client, MQTT_SERVER, MQTT_SERVER_PORT, MQTT_CLIENT_ID, MQTT_USERNAME, MQTT_PASSWORD);

Adafruit_MQTT_Publish topic_pub = Adafruit_MQTT_Publish(&mqtt_client, "v1/devices/me/telemetry");
Adafruit_MQTT_Subscribe topic_sub = Adafruit_MQTT_Subscribe(&mqtt_client, "v1/devices/me/rpc/request/+");
Adafruit_MQTT_Publish topic_sub_response = Adafruit_MQTT_Publish(&mqtt_client, "v1/devices/me/attributes");

#define LED 3

void setup() {
  Serial.begin(115200);
  delay(10);

  Serial.println(F("Mese IO MQTT"));

  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(WLAN_SSID);

  delay(1000);

  WiFi.begin(WLAN_SSID, WLAN_PASS);
  delay(2000);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();

  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  pinMode(LED, OUTPUT);

  // first rgb status
  Serial.print(F("Sending "));
  String data = "{r:" + String(random(0, 2)) + ",g:" + String(random(0, 2)) + ",b:" + String(random(0, 2)) + "}";
  Serial.print(data);

  if (!topic_sub_response.publish(data.c_str())) {
    Serial.println(F("Failed"));
  } else {
    Serial.println(F(" OK!"));
  }

  mqtt_client.subscribe(&topic_sub);

}  // setup

uint32_t x = 0;

void loop() {
  MQTT_connect();

  Adafruit_MQTT_Subscribe *subscription;
  while ((subscription = mqtt_client.readSubscription(1000))) {
    Serial.println("sub geldi");
    if (subscription == &topic_sub) {
      Serial.print(F("On-Off button: "));
      Serial.println((char *)topic_sub.lastread);

      if (strcmp((char *)topic_sub.lastread, "ON") == 0) {
        digitalWrite(LED, LOW);
      }
      if (strcmp((char *)topic_sub.lastread, "OFF") == 0) {
        digitalWrite(LED, HIGH);
      }
    }
  }

  Serial.print(F("Sending "));
  String data = "{r:" + String(random(0, 2)) + ",g:" + String(random(0, 2)) + ",b:" + String(random(0, 2)) + "}";
  Serial.print(data);

  if (!topic_pub.publish(data.c_str())) {
    Serial.println(F("Failed"));
  } else {
    Serial.println(F(" OK!"));
  }

  delay(1000);

}  // loop

void MQTT_connect() {
  int8_t ret;

  if (mqtt_client.connected()) {
    return;
  }

  Serial.print("Connecting to MQTT... ");

  uint8_t retries = 50;
  while ((ret = mqtt_client.connect()) != 0) {
    Serial.println(mqtt_client.connectErrorString(ret));
    Serial.println("Retrying MQTT connection in 5 seconds...");
    mqtt_client.disconnect();
    delay(1000);
    retries--;
    if (retries == 0) {
      ESP.restart();
    }
  }

  Serial.println("MQTT Connected!");

}  // MQTT_connect
