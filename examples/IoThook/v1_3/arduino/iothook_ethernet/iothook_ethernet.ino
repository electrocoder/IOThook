/*
  IoThook REST Api Testi

  Kod çalıştırıldığında data değişkenine yüklenen json formatındaki
  value_1 , value_2 ve value_3 değerleri random üretilerek iothook sunucusuna
  gönderilir.

  Bu ornek IotHook servisine veri almak/gondermek icin baslangic seviyesinde
  testlerin yapilmasini amaclamaktadir.

  15 Eylül 2017
  Sahin MERSIN

  Daha fazlasi icin

  http://www.iothook.com
  ve
  https://github.com/electrocoder/iotHook

  sitelerine gidiniz.

  Sorular ve destek talepleri icin
  https://github.com/electrocoder/iotHook/issues
  sayfasindan veya Meşe Bilişim den yardım alabilirsiniz.

  Yayin : http://mesebilisim.com

  Ornek dani tarafından geliştirilmiştir. 
  
  Lisans haklarına ayrıca bakınız.
*/

// Simple demo for feeding some random data to Pachube.
// 2011-07-08 <jc@wippler.nl> http://opensource.org/licenses/mit-license.php

// Handle returning code and reset ethernet module if needed
// 2013-10-22 hneiraf@gmail.com

// Arduino pro-mini 5V/16MHz, ETH modul on SPI with CS on pin 10.
// Also added a few changes found on various forums. Do not know what the
// res variable is for, tweaked it so it works faster for my application
// 2015-11-09 dani.lomajhenic@gmail.com

#include <EtherCard.h>

// change these settings to match your own setup
//#define FEED "000"
#define APIKEY "J8Z1C22ELNI9X5LO" // put your key here
#define ethCSpin 10 // put your CS/SS pin here.

// ethernet interface mac address, must be unique on the LAN
static byte mymac[] = { 0x74, 0x69, 0x69, 0x2D, 0x30, 0x31 };
const char website[] PROGMEM = "iothook.com";
byte Ethernet::buffer[700];
uint32_t timer;
Stash stash;
byte session;

//timing variable
int res = 100; // was 0



void setup () {
  Serial.begin(9600);
  Serial.println("\n[IoT example]");

  //Initialize Ethernet
  initialize_ethernet();
}


void loop () {
  //if correct answer is not received then re-initialize ethernet module
  if (res > 220) {
    initialize_ethernet();
  }

  res = res + 1;

  ether.packetLoop(ether.packetReceive());

  //200 res = 10 seconds (50ms each res)
  if (res == 200) {


    //Generate random info
    float demo = random(0, 500);
    word one = random(0, 500);
    String msje;

    if (demo < 250) {
      msje = "low";
    }
    else {
      msje = "high";
    }

    // generate two fake values as payload - by using a separate stash,
    // we can determine the size of the generated message ahead of time
    // field1=(Field 1 Data)&field2=(Field 2 Data)&field3=(Field 3 Data)&field4=(Field 4 Data)&field5=(Field 5 Data)&field6=(Field 6 Data)&field7=(Field 7 Data)&field8=(Field 8 Data)&lat=(Latitude in Decimal Degrees)&long=(Longitude in Decimal Degrees)&elevation=(Elevation in meters)&status=(140 Character Message)
    byte sd = stash.create();

    String data = "{\"api_key\":\"9bbba1428aba49df8d52d94c2e75e8b049108da3\",\"value_1\":" + String(random(0, 10)) + ",\"value_2\":" + String(random(0, 10)) + ",\"value_3\":" + String(random(0, 10)) + "}";

    stash.print(data);
    stash.save();

    //Display data to be sent
    Serial.println(demo);


    // generate the header with payload - note that the stash size is used,
    // and that a "stash descriptor" is passed in as argument using "$H"
    Stash::prepare(PSTR("POST /api/latest/datas/ HTTP/1.1" "\r\n"
                        "Host: $F" "\r\n"
                        "Connection: close" "\r\n"
                        "Content-Type: application/json\r\n"
                        "Content-Length: $D" "\r\n"
                        "\r\n"
                        "$H"),
                   website, stash.size(), sd);

    // send the packet - this also releases all stash buffers once done
    session = ether.tcpSend();

    // added from: http://jeelabs.net/boards/7/topics/2241
    int freeCount = stash.freeCount();
    if (freeCount <= 3) {
      Stash::initMap(56);
    }
  }

  const char* reply = ether.tcpReply(session);

  if (reply != 0) {
    res = 0;
    Serial.println(F(" >>>REPLY recieved...."));
    Serial.println(reply);
  }
  delay(300);
}



void initialize_ethernet(void) {
  for (;;) { // keep trying until you succeed
    //Reinitialize ethernet module
    //pinMode(5, OUTPUT);  // do notknow what this is for, i ve got something elso on pin5
    //Serial.println("Reseting Ethernet...");
    //digitalWrite(5, LOW);
    //delay(1000);
    //digitalWrite(5, HIGH);
    //delay(500);

    if (ether.begin(sizeof Ethernet::buffer, mymac, ethCSpin) == 0) {
      Serial.println( "Failed to access Ethernet controller");
      continue;
    }

    if (!ether.dhcpSetup()) {
      Serial.println("DHCP failed");
      continue;
    }

    ether.printIp("IP:  ", ether.myip);
    ether.printIp("GW:  ", ether.gwip);
    ether.printIp("DNS: ", ether.dnsip);

    if (!ether.dnsLookup(website))
      Serial.println("DNS failed");

    ether.printIp("SRV: ", ether.hisip);

    //reset init value
    res = 180;
    break;
  }
}

