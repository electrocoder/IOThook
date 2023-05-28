/*
  17.11.2022
  MQTT Pub ve Sub
  Arduino Uno, W5500 Lite
  Lib: // https://github.com/256dpi/arduino-mqtt
*/

#include <ArduinoJson.h>
#include <Ethernet.h>
#include <MQTT.h>

byte mac[] = { 0xA0, 0x00, 0x00, 0x00, 0x00, 0x05 };
// byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
byte ip[] = { 192, 168, 1, 177 };

// String server = "www.iothook.com";
char ID[] = "00000000005";                   // char ID 11 karakter
String SID = "00000000005";                 // string ID 11 karakter
char topic_publish[] = "mese/iot/response";  // firma_namespace/firma_grup_name/response
char topic_subscribe[] = "mese/iot/write/";  // firma_namespace/firma_grup_name/write

#define MQTT_USER "iothookpublic"
#define MQTT_PASS "iothookpublic"

unsigned long lastMillis = 0;
unsigned long id = 0;             // msg publish counter
unsigned int refresh_time = 1000;  // 1sn

const int out1 = 7, out2 = 8, out3 = 9, out4 = A5, out5 = A4;                                        // 24 v cikis
const int in1 = 3, in2 = 4, in3 = 5, in4 = 6, in5 = A3;                                              // 24 v giris
bool state_in1 = false, state_in2 = false, state_in3 = false, state_in4 = false, state_in5 = false;  // 24 v giris durumlari
int adc1 = A0, adc2 = A1, adc3 = A2, adc4 = A6;                                                      // 4 analog giris

bool MSG = false;
bool out_status1 = false;
bool out_status2 = false;
bool out_status3 = false;
bool out_status4 = false;
bool out_status5 = false;

float value_adc1=0;
float value_adc2=0;
float value_adc3=0;
float value_adc4=0;

String msg = "";

EthernetClient ethClient;
MQTTClient mqttClient(220); // 220 den fazla yer ayrilirsa calismiyor


void connect() {
  Serial.print("connecting...");
  while (!mqttClient.connect(ID, MQTT_USER, MQTT_PASS)) {
    Serial.print(".");
    delay(1000);
  }

  Serial.println("\nconnected!");

  mqttClient.subscribe(strcat(topic_subscribe, ID));
  // mqttClient.unsubscribe("/hello");
}


void messageReceived(String &topic, String &payload) {

  Serial.println("messageReceived: " + topic + " - " + payload);

  StaticJsonDocument<256> doc;
  // DeserializationError error = deserializeJson(doc, payload, length);
  // if (error)
  // return;

  MSG = true;
  JsonObject obj = doc.as<JsonObject>();

  unsigned int json_out1 = obj["out1"];
  if (json_out1 == 1) {
    out_status1 = true;
  } else if (json_out1 == 0) {
    out_status1 = false;
  }

  unsigned int json_out2 = obj["out2"];
  if (json_out2 == 1) {
    out_status2 = true;
  } else if (json_out2 == 0) {
    out_status2 = false;
  }

  unsigned int json_out3 = obj["out3"];
  if (json_out3 == 1) {
    out_status3 = true;
  } else if (json_out3 == 0) {
    out_status3 = false;
  }

  unsigned int json_out4 = obj["out4"];
  if (json_out4 == 1) {
    out_status4 = true;
  } else if (json_out4 == 0) {
    out_status4 = false;
  }

  unsigned int json_out5 = obj["out5"];
  if (json_out5 == 1) {
    out_status5 = true;
  } else if (json_out5 == 0) {
    out_status5 = false;
  }

}  // messageReceived


void setup() {

  Serial.begin(115200);
  while (!Serial) {
    ;
  }

  msg.reserve(350);

  pinMode(out1, OUTPUT);
  pinMode(out2, OUTPUT);
  pinMode(out3, OUTPUT);
  pinMode(out4, OUTPUT);
  pinMode(out5, OUTPUT);

  pinMode(in1, INPUT_PULLUP);
  pinMode(in2, INPUT_PULLUP);
  pinMode(in3, INPUT_PULLUP);
  pinMode(in4, INPUT_PULLUP);
  pinMode(in5, INPUT_PULLUP);

  Ethernet.init(10);
  Ethernet.begin(mac, ip);

  // Note: Local domain names (e.g. "Computer.local" on OSX) are not supported
  // by Arduino. You need to set the IP address directly.
  mqttClient.begin("www.iothook.com", ethClient);
  mqttClient.onMessage(messageReceived);

  connect();

}  // setup


void msg_publish() {

  msg = "{'id':" + SID;
  msg = msg + ",'in1':" + String(state_in1);
  msg = msg + ",'in2':" + String(state_in2);
  msg = msg + ",'in3':" + String(state_in3);
  msg = msg + ",'in4':" + String(state_in4);
  msg = msg + ",'in5':" + String(state_in5);
  msg = msg + ",'adc1':" + String(value_adc1);
  msg = msg + ",'adc2':" + String(value_adc2);
  msg = msg + ",'adc3':" + String(value_adc3);
  msg = msg + ",'adc4':" + String(value_adc4);
  msg = msg + ",'cid':" + id++;
  msg = msg + "}";
  
  Serial.println(msg);

  char temp[msg.length() + 2];

  msg.toCharArray(temp, msg.length() + 1);  //packaging up the data to publish to mqtt whoa...

  mqttClient.publish(topic_publish, msg);

}  // msg_publish


void loop() {

  mqttClient.loop();

  if (!mqttClient.connected()) {
    Serial.println("not connected");
    connect();
  }

  if (out_status1 == true)
    digitalWrite(out1, 1);
  else
    digitalWrite(out1, 0);

  if (out_status2)
    digitalWrite(out2, 1);
  else
    digitalWrite(out2, 0);

  if (out_status3)
    digitalWrite(out3, 1);
  else
    digitalWrite(out3, 0);

  if (out_status4)
    digitalWrite(out4, 1);
  else
    digitalWrite(out4, 0);

  if (out_status5)
    digitalWrite(out5, 1);
  else
    digitalWrite(out5, 0);

  if (millis() - lastMillis > refresh_time) {
    lastMillis = millis();

    Serial.println("msg send");

    state_in1 = digitalRead(in1);
    state_in2 = digitalRead(in2);
    state_in3 = digitalRead(in3);
    state_in4 = digitalRead(in4);
    state_in5 = digitalRead(in5);

    value_adc1 = analogRead(adc1);
    value_adc2 = analogRead(adc2);
    value_adc3 = analogRead(adc3);
    value_adc4 = analogRead(adc4);

    msg_publish();
  }

  if (MSG) {
    // String msg = "{\"id\":\"" + SID + "\",\"msg\":" + "\"ok\"" + ",\"out_status1\":" + String(out_status1) + ",\"out_status2\":" + String(out_status2) + ",\"out_status3\":" + String(out_status3) + ",\"out_status4\":" + String(out_status4) + ",\"out_status5\":" + String(out_status5) + ",\"cid\":" + id++ + "}";
    // msg_publish(msg);

    MSG = false;
  }

}  // loop
