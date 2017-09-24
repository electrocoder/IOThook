/*
  Arduino DUE ile ESP8266 Wifi Modul Testi

 Kod Arduino ya yuklendiginde Arduino IDE nin Seriai Monitor u
 ile ESP8266 arasinda RX-TX hatti uzerinden haberlesme yapilir.

 Serial Monitorun veri gonderme kutusuna sirasiyla

  * AT // OK
  * AT+RST  // OK Ai-Thinker Technology Co.,Ltd.
  * AT+GMR // SDK version:1.3.0
  * AT+CWLAP // +CWLAP:(4,"SUPERONLINE_123",-88,"f4:e3:fb:86:bc:69",1,-22)
  * AT+CWJAP="Wifi_Ismi","Wifi_Sifresi" // OK    WIFI CONNECTED    WIFI GOT IP
  * AT+CIFSR // +CIFSR:STAIP,"192.168.1.104"

 komutlari yazilir. Gonderme islemi icin Serial Monitorun Baud ayari
 115200 olmalidir. Karakter ekleme secenegi ise Both NL & CR olmalidir.
  
 Bu ornek IotHook servisine veri gondermek icin baslangic ayarlarinin
 yapilmasini amaclamaktadir.
 
 21 Aralik 2016
 Sahin MERSIN

 Daha fazlasi icin

 http://www.iothook.com 
 ve 
 https://github.com/electrocoder/iotHook

 sitelerine gidiniz.
 Sorular ve destek talepleri icin
 https://github.com/electrocoder/iotHook/issues
 sayfasina gidiniz.

 Yayin ve sahiplik http://mesebilisim.com
 */
 
void setup() {
  Serial.begin(115200);
  Serial3.begin(115200);

  Serial.write("Hazir"); 
}

void loop() {
  while (Serial.available() > 0) {
    char c = Serial.read();
    Serial3.write(c);
  }
}

void serialEvent3() {
  while (Serial3.available() > 0) {
    char c = Serial3.read();
    Serial.write(c);
  }
}

