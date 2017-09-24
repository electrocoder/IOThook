/*
  Arduino ile ESP8266 Wifi Modul Testi

  Kod Arduino ya yuklendiginde Arduino IDE nin Serial Monitor u
  ile ESP8266 arasinda haberlesme gozlenebilir.

  Arduino ile ESP8266 arasindaki iletisim Baud ayari
  115200 olmalidir.

  Arduino 0 ile 100 arasinda uretmis oldugu Random sayıyı iothook a gonderir.

  Bu cihaza ait datalar
  https://iothook.com/tr/channel/api/public/240
  adresinden gercek zamanli olarak izlenebilir.

  Bu ornek IoThook servisine veri gondermek icin baslangic ayarlarinin
  yapilmasini amaclamaktadir.

  24 Eylul 2017
  Sahin MERSIN

  Daha fazlasi icin

  http://www.iothook.com
  ve
  https://github.com/electrocoder/IoThook

  sitelerine gidiniz.
  Sorular ve destek talepleri icin
  https://github.com/electrocoder/IoThook/issues
  sayfasina gidiniz.

  Yayin ve sahiplik http://mesebilisim.com
*/

#include "SoftwareSerial.h"

String ssid = "WIFI_ID";
String password = "WIFI_PASSWORD";

SoftwareSerial esp(10, 11);// RX, TX

String data;

String server = "iothook.com";

String uri = "/api/latest/datas/";

void setup() {

  esp.begin(115200);

  Serial.begin(115200);

  Serial.println("Arduino ile ESP8266 Wifi Modul Testi");
  Serial.println("          www.IoThook.com           ");
  Serial.println("");

  reset();

  connectWifi();

}


void reset() {

  esp.println("AT+RST");

  delay(2000);

  if (esp.find("OK") ) Serial.println("Modul Reset yapildi");
  else Serial.println("Module Reset yapılamadi");

}


void connectWifi() {

  String cmd = "AT+CWJAP=\"" + ssid + "\",\"" + password + "\"";

  esp.println(cmd);

  delay(4000);

  if (esp.find("OK")) {

    Serial.println("ESP8266 Wifi ye baglandi");

  }

  else {

    connectWifi();

    Serial.println("ESP8266 Wifi ye baglanamadı!");
  }

}


void loop () {

  data = "{\"api_key\":\"b4301a9f-9854-11790bdf8d320140da\",\"value_1\":" + String(random(0, 100)) + "}";

  httppost();

  delay(5000);

}


void httppost () {

  esp.println("AT+CIPSTART=\"TCP\",\"" + server + "\",80");

  if ( esp.find("OK")) {

    Serial.println("TCP baglanti hazir");

  }
  else
    Serial.println("TCP baglanti hatali");

  delay(3000);

  String postRequest =

    "POST " + uri + " HTTP/1.0\r\n" +

    "Host: " + server + "\r\n" +

    "Accept: *" + "/" + "*\r\n" +

    "Content-Length: " + data.length() + "\r\n" +

    "Content-Type: application/x-www-form-urlencoded\r\n" +

    "\r\n" + data;

  String sendCmd = "AT+CIPSEND=";

  esp.print(sendCmd);

  esp.println(postRequest.length() );

  delay(1500);

  if (esp.find(">")) {
    Serial.println("Gonderiliyor...");
    esp.print(postRequest);

    if ( esp.find("SEND OK")) {
      Serial.println("Gonderildi :)");

      while (esp.available()) {

        String tmpResp = esp.readString();

        Serial.println(tmpResp);

      }

      esp.println("AT+CIPCLOSE");

    }
    else
      Serial.println("Gonderilemedi :(");

  }
  else
    Serial.println("Gonderim hatasi! ESP hazir degil!");
}
