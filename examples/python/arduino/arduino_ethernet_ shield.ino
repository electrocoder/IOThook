/*

  Server Odasi Sicaklik ve Nem Takibi
  electrocoder@gmail.com
  sahin@mesebilisim.com
  mesebilisim.com
  13.01.2020

*/

#include <SPI.h>
#include <Ethernet.h>


byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED
};

IPAddress ip(192, 168, 1, 177);
IPAddress myDns(192, 168, 1, 1);

EthernetClient client;

char server[] = "iothook.com";

unsigned long lastConnectionTime = 0;
const unsigned long postingInterval = 20 * 1000;

void setup() {

  Serial.begin(9600);
  while (!Serial) {
    ;
  }

  Serial.println("Initialize Ethernet with DHCP:");
  if (Ethernet.begin(mac) == 0) {
    Serial.println("Failed to configure Ethernet using DHCP");
    // Check for Ethernet hardware present
    if (Ethernet.hardwareStatus() == EthernetNoHardware) {
      Serial.println("Ethernet shield was not found.  Sorry, can't run without hardware. :(");
      while (true) {
        delay(1);
      }
    }
    if (Ethernet.linkStatus() == LinkOFF) {
      Serial.println("Ethernet cable is not connected.");
    }

    Ethernet.begin(mac, ip, myDns);
    Serial.print("My IP address: ");
    Serial.println(Ethernet.localIP());
  } else {
    Serial.print("  DHCP assigned IP ");
    Serial.println(Ethernet.localIP());
  }

  delay(1000);

}


void loop() {

  if (client.available()) {
    char c = client.read();
    Serial.write(c);
  }

  if (millis() - lastConnectionTime > postingInterval) {
    httpRequest();
  }

}


void httpRequest() {

  client.stop();


  if (client.connect(server, 80)) {
    Serial.println("connecting...");

    client.println("GET /api/update/?api_key=1c68681&field_1=0 HTTP/1.1");
    client.println("Host: www.iothook.com");
    client.println("User-Agent: arduino-ethernet");
    client.println("Connection: close");
    client.println();


    lastConnectionTime = millis();
  } else {
    Serial.println("connection failed");
  }
}



