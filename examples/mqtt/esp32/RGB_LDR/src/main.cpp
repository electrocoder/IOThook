/*
  07.01.2024
  ESP32 C3
  2MB
  iothook.com
  mesebilisim.com
  electrocoder
  https://github.com/electrocoder/IOThook

    ESP-C3-13 ESP-C3-13-KIT development board ESP32
    ESP-C3-13-Kit
    Esp32-C3 2M flash ESP-C3 ESP C3 13 13U ESP-C3-13U WiFi + Bluetooth 5.0 BLE5.0 2.4GHz Geliştirme kartı

    Model: ESP-C3-13-KIT development board
    Package size: DIP-30 20.0x18.0x3.1mm (±0.2mm)
    Antenna: On-board PCB antenna
    Spectrum range: 2400 - 2483.5MHz
    Operating temperature: -40℃ - 85℃
    Storage environment: -40℃ - 125℃, <90% RH
    Power Supply Requirement: 5V >500mA
    Supported Interfaces: UART / GPIO / ADC / PWM / I2C / I2S
    IO Ports: IO0, IO1, IO2, IO3, IO4, IO5, IO6, IO7, IO8, IO9, IO10, IO18, IO19, IO20, IO21
    Serial port speed: 110 - 4608000 bps, default 115200 bps
    Bluetooth: BLE 5.0
    WIFI security: WEP / WPA-PSK / WPA2-PSK
    SPI Flash: 4MB
    Onboard LED: RGBWA (IO3 Red, IO4 Green, IO5 Blue), IO18 Amber, IO19 White

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
