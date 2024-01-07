/*
  07.01.2024
  ESP32 C3
  2MB
  iothook.com
  mesebilisim.com
  electrocoder
  https://github.com/electrocoder/IOThook
*/

#include <Arduino.h>
#include <WiFi.h>         // esp
#include <WiFiMulti.h>    // esp
#include <PubSubClient.h> // mqtt

const char *ssid = "ssid";
const char *password = "password";

const char *HTTP_MQTT_SERVER = "iothook.com";
const int MQTT_PORT = 1883;
const String writeApiKey = "writeApiKey";

int field_1 = 0;

int numberOfResults = 3;
int fieldNumber = 1;

WiFiClient wifi_client;
PubSubClient pub_sub_client(wifi_client);

const char *mqtt_topic_telemetry = "v1/devices/me/telemetry"; // mqtt topic 

void setup()
{
  Serial.begin(115200);
  while (!Serial)
  {
    delay(100);
  }

  Serial.println();
  Serial.println("***");
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  pub_sub_client.setServer(HTTP_MQTT_SERVER, MQTT_PORT);

  while (!pub_sub_client.connected())
  {
    if (pub_sub_client.connect("qw", writeApiKey.c_str(), ""))
    {
      Serial.println("Connected");
    }
  }
} // setup

void loop()
{
  int in1, in2, in3;
  in1 = analogRead(A2);
  in1 = analogRead(A3);
  in1 = analogRead(A0);

  String data = "{in1:" + String(in1) + ",in2:" + String(in2) + ",in3:" + String(in3) + "}";

  pub_sub_client.publish(mqtt_topic_telemetry, data.c_str());

  Serial.print(in1);
  Serial.print(", ");
  Serial.print(in2);
  Serial.print(", ");
  Serial.println(in3);

  delay(1000);
} // loop
