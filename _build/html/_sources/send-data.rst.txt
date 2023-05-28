*********
Send Data
*********

HTTP Send Data
**************

To send data, you must first add a device. Special read and write "API KEY" when the device is created
Data processing is performed according to the access method (POST, GET, POST/GET) that is generated and determined.

For example; Let our device be in a structure that receives humidity, heat and light values.
For this example, the device named "# 650 - iot_examples" was created on iothook.com.
`IoThook <https://iothook.com/en/device/settings/650/>`_ .

Let the IoT device read the data from the sensors and send this data to us once every 15 seconds, a total of 100 times.

You can access the read and write API Keys created for the #650 iot device from the IoThook dashboard.

The API ENDPOINT address we will use to send data to IoThook servers with Python is *https://iothook.com/api/update/*.
Writing *api_key* information is needed to send data. You can access this KEY from the device **settings** page.

There are 2 required fields to send data. These fields are **api_key** and **field_1** fields. APIKEY your device ownership
*field_1* absolutely must be because it validates and must have at least one data field. Other fields defined
even if they are not sent, they are recorded as **None**.

Send JSON Data in POST with Python
==================================

In this example, JSON data is sent to the device channel named "# 650 - iot_examples" using the HTTP POST method with
Python. When the data is sent successfully, Json REST output of the data is received. You can do this with the
*response.json()* method, we are doing.

Example output:

    >>> {'device': 650, 'field_1': '6', 'field_2': '3.49', 'field_3': '22', 'field_4': None, 'field_5': None, 'field_6': None, 'field_7': None, 'field_8': None, 'id': 502491, 'pub_date': '2019-08-31T01:07:29.438160', 'remote_address': '88.242.135.167&python-requests/2.18.4&HTTP/1.1'}

Send JSON Data in POST with Python Examples:
-------------------------------------------

You can find this example and others at `IoT Examples Github <https://github.com/meseiot/iot-examples/blob/master/http/python/iot_post_json_update_post.py>`_.

.. figure:: _static/python-send-data.png
   :alt: python-send-data.png
   :align: center

.. code-block:: python

    """
    Python ile IoThook REST Api Testi

    IoThook'da her cihazin bir kimlik numarasi APIKEY'i vardir.
    Bu APIKEY kullanilarak veriler IoThook'a POST metodu ile gonderilir.
    5 kere 15 saniyede bir random verileri iothook'a gonderir.

    Bu ornek IotHook servisine veri almak/gondermek icin baslangic seviyesinde
    testlerin yapilmasini amaclamaktadir.

    v1 : 11 Eylul 2017
    v2 : 19 Agustos 2019
    v3 : 31 Ekim 2022

    Sahin MERSIN - electrocoder

    Daha fazlasi icin

    http://www.iothook.com
    https://www.mesebilisim.com
    https://mesemekatronik.com
    https://electrocoder.blogspot.com
    https://github.com/meseiot/iotexamples

    sitelerine gidiniz.

    Yayin : http://mesebilisim.com

    Licensed under the Apache License, Version 2.0 (the "License").
    You may not use this file except in compliance with the License.
    A copy of the License is located at

    http://www.apache.org/licenses/
    """

    import json
    import pprint
    import random
    import time

    import requests

    headers = {'Content-type': 'application/json'}

    # demo account API_KEY
    # https://iothook.com/en/device/data/650/
    # 650 - iot_examples
    API_KEY = '21579c1e874fda7276d94f3c'  # write api key
    url = 'http://iothook.com/api/update/'

    for i in range(5):
    data = {  # write api key
        'api_key': API_KEY,  # demo hesap #650 - iot_examples
        'field_1': random.randint(1, 10),
        'field_2': round(random.uniform(0.0, 10.0), 2),
    }

    data_json = json.dumps(data)

    response = requests.post(url, data=data_json, headers=headers)
    pprint.pprint(response.json())
    time.sleep(15)

Send JSON Data in POST with Python Examples 2:
----------------------------------------------

You can find this example and others at `IoT Examples Github <https://github.com/meseiot/iot-examples/blob/master/http/python/iot_post_json_update_post_1.py>`_.

.. figure:: _static/python-send-data.png
   :alt: python-send-data.png
   :align: center

.. code-block:: python

    """
    Python ile IoThook REST Api Testi

    IoThook'da her cihazin bir kimlik numarasi APIKEY'i vardir.
    Bu APIKEY kullanilarak veriler IoThook'a POST metodu ile gonderilir.
    100 kere 15 saniyede bir random verileri iothook'a gonderir.

    Bu ornek IotHook servisine veri almak/gondermek icin baslangic seviyesinde
    testlerin yapilmasini amaclamaktadir.

    v1 : 11 Eylul 2017
    v2 : 19 Agustos 2019
    v3 : 31 Ekim 2022

    Sahin MERSIN - electrocoder

    Daha fazlasi icin

    http://www.iothook.com
    https://www.mesebilisim.com
    https://mesemekatronik.com
    https://electrocoder.blogspot.com
    https://github.com/meseiot/iotexamples

    sitelerine gidiniz.

    Yayin : http://mesebilisim.com

    Licensed under the Apache License, Version 2.0 (the "License").
    You may not use this file except in compliance with the License.
    A copy of the License is located at

    http://www.apache.org/licenses/
    """

    import json
    import pprint
    import random
    import time

    import requests

    headers = {'Content-type': 'application/json'}

    # demo account API_KEY
    # https://iothook.com/en/device/data/650/
    # 650 - iot_examples
    API_KEY = '21579c1e874fda7276d94f3c'  # write api key
    url = 'http://iothook.com/api/update/'

    for i in range(100):
        data = {  # write api key
            'api_key': API_KEY,  # demo hesap #650 - iot_examples
            'field_1': random.randint(1, 10),
            'field_2': round(random.uniform(0.0, 10.0), 2),
        }

        data_json = json.dumps(data)

        response = requests.post(url, data=data_json, headers=headers)
        pprint.pprint(response.json())
        time.sleep(15)

Send JSON Data in POST with Python Examples 3:
----------------------------------------------

You can find this example and others at `IoT Examples Github <https://github.com/meseiot/iot-examples/blob/master/http/python/iot_post_json_update_post_2.py>`_.

.. figure:: _static/python-send-data.png
   :alt: python-send-data.png
   :align: center

.. code-block:: python

    """
    Python ile IoThook REST Api Testi
    IoThook'da her cihazin bir kimlik numarasi APIKEY'i vardir.
    Bu APIKEY kullanilarak veriler IoThook'a POST metodu ile gonderilir.
    1000 kere 15 saniyede bir random verileri iothook'a gonderir.
    Bu ornek IotHook servisine veri almak/gondermek icin baslangic seviyesinde
    testlerin yapilmasini amaclamaktadir.
    v1 : 11 Eylul 2017
    v2 : 19 Agustos 2019
    v3 : 31 Ekim 2022
    Sahin MERSIN - electrocoder
    Daha fazlasi icin
    http://www.iothook.com
    https://www.mesebilisim.com
    https://mesemekatronik.com
    https://electrocoder.blogspot.com
    https://github.com/meseiot/iotexamples
    sitelerine gidiniz.
    Yayin : http://mesebilisim.com
    Licensed under the Apache License, Version 2.0 (the "License").
    You may not use this file except in compliance with the License.
    A copy of the License is located at
    http://www.apache.org/licenses/
    """

    import json
    import pprint
    import random
    import time

    import requests

    headers = {'Content-type': 'application/json'}

    # demo account API_KEY
    # https://iothook.com/en/device/data/650/
    # 650 - iot_examples
    API_KEY = '21579c1e874fda7276d94f3c'  # write api key
    url = 'http://iothook.com/api/update/'

    for i in range(1000):
        data = {  # write api key
            'api_key': API_KEY,  # demo hesap #650 - iot_examples
            'field_1': random.randint(1, 10),
            'field_2': round(random.uniform(0.0, 10.0), 2),
        }

        data_json = json.dumps(data)

        response = requests.post(url, data=data_json, headers=headers)
        pprint.pprint(response.json())
        time.sleep(15)

Send Data in GET with Python
============================

With the IoThook Api v6 update, it allows sending data with the GET method.

To send data, you must first add a device. Special read and write "API KEY" when the device is created Data processing
is performed according to the access method (POST, GET, POST/GET) that is generated and determined.

For example; Let our device be in a structure that receives humidity, heat and light values. For this example,
the device named "# 650 - iot_examples" was created on iothook.com.
`IoThook <https://iothook.com/en/device/settings/650/>`_ .

Let the IoT device read the data from the sensors and send this data to us once every 15 seconds, a total of 100 times.

You can access the read and write API Keys created for the #650 iot device from the IoThook dashboard.

The API ENDPOINT address we will use to send data to IoThook servers with Python is https://iothook.com/api/update/.
Writing api_key information is needed to send data. You can access this KEY from the device settings page.

There are 2 required fields to send data. These fields are api_key and field_1 fields. APIKEY your device ownership
field_1 absolutely must be because it validates and must have at least one data field. Other fields defined even if
they are not sent, they are recorded as None.

Send Data in GET with Python Examples:
--------------------------------------

You can find this example and others at `IoT Examples Github <https://github.com/meseiot/iot-examples/blob/master/http/python/iot_get_write.py>`_.

.. figure:: _static/python-iothook.png
   :alt: python-send-data.png
   :align: center

.. code-block:: python

    """
    Python ile IoThook REST Api Ornegi

    IoThook'da her cihazin bir kimlik numarasi APIKEY'i vardir.
    Bu APIKEY kullanilarak veriler IoThook'a GET metodu ile gonderilir.

    Bu ornek IoThook servisine veri almak/gondermek icin baslangic seviyesinde
    testlerin yapilmasini amaclamaktadir.

    v1 : 20 Eylul 2017
    v2 : 19 Agustos 2019
    v3 : 31 Ekim 2022

    Sahin MERSIN - electrocoder

    Daha fazlasi icin

    http://www.iothook.com
    https://www.mesebilisim.com
    https://mesemekatronik.com
    https://electrocoder.blogspot.com
    https://github.com/meseiot/iotexamples

    sitelerine gidiniz.

    Yayin : http://mesebilisim.com

    Licensed under the Apache License, Version 2.0 (the "License").
    You may not use this file except in compliance with the License.
    A copy of the License is located at

    http://www.apache.org/licenses/
    """

    import pprint
    import requests

    # demo account API_KEY
    # https://iothook.com/en/device/data/650/
    # 650 - iot_examples
    API_KEY = '21579c1e874fda7276d94f3c'  # write api key
    url = 'http://iothook.com/api/update/?api_key=' + API_KEY

    data = url + '&field_1=10&field_2=20&field_3=30'

    response = requests.get(data)
    pprint.pprint(response.json())

Send Data in GET with Python Examples 2:
--------------------------------------

You can find this example and others at `IoT Examples Github <https://raw.githubusercontent.com/meseiot/iot-examples/master/http/python/iot_get_write_1.py>`_.

.. figure:: _static/python-iothook.png
   :alt: python-send-data.png
   :align: center

.. code-block:: python

    """
      Python ile IoThook REST Api Ornegi

      IoThook'da her cihazin bir kimlik numarasi APIKEY'i vardir.
      Bu APIKEY kullanilarak veriler IoThook'a GET metodu ile gonderilir.
      10 kere 15 saniyede bir random verileri iothook'a gonderir.


      Bu ornek IoThook servisine veri almak/gondermek icin baslangic seviyesinde
      testlerin yapilmasini amaclamaktadir.

      v1 : 20 Eylul 2017
      v2 : 19 Agustos 2019
      v3 : 31 Ekim 2022

      Sahin MERSIN - electrocoder

      Daha fazlasi icin

      http://www.iothook.com
      https://www.mesebilisim.com
      https://mesemekatronik.com
      https://electrocoder.blogspot.com
      https://github.com/meseiot/iotexamples

      sitelerine gidiniz.

      Yayin : http://mesebilisim.com

      Licensed under the Apache License, Version 2.0 (the "License").
      You may not use this file except in compliance with the License.
      A copy of the License is located at

      http://www.apache.org/licenses/
    """

    import pprint
    import requests
    import time

    # demo account API_KEY
    # https://iothook.com/en/device/data/650/
    # 650 - iot_examples
    API_KEY = '21579c1e874fda7276d94f3c'  # write api key
    url = 'http://iothook.com/api/update/?api_key=' + API_KEY

    for i in range(10):
        data = url + '&field_1=10&field_2=20&field_3=30'

        response = requests.get(data)
        pprint.pprint(response.json())
        time.sleep(15)

Arduino and ESP8266
===================

Arduino and ESP8266 HTTP POST Send Data
---------------------------------------

In this example, Arduino code is given for sending data to iothook with ESP8266 connected to Arduino Uno with RX and TX.
In the example, random numbers between 0-100 were generated and the device was sent to the device with
"# 650 - iot_examples" on iothook.

You can find this example and others at `IoT Examples Github <https://github.com/meseiot/iot-examples/blob/master/http/arduino/esp8266/arduino_esp8266_post_send_data.ino>`_.

.. code-block:: c

    /*
      Arduino ile ESP8266 Wifi Modul Testi

      Kod Arduino ya yuklendiginde Arduino IDE nin Serial Monitor u
      ile ESP8266 arasinda haberlesme gozlenebilir.

      Arduino ile ESP8266 arasindaki iletisim Baud ayari
      115200 olmalidir.

      Arduino 0 ile 100 arasinda uretmis oldugu Random sayıyı iothook a gonderir.

      Bu cihaza ait datalar
      https://iothook.com/en/device/data/19/
      adresinden gercek zamanli olarak izlenebilir.

      Bu ornek IOThook servisine veri gondermek icin baslangic ayarlarinin
      yapilmasini amaclamaktadir.

      24 Eylul 2017
      Güncelleme : 19 Agustos 2019
      Sahin MERSIN

      Daha fazlasi icin

      http://www.iothook.com
      ve
      https://github.com/electrocoder/IOThook

      sitelerine gidiniz.
      Sorular ve destek talepleri icin
      https://github.com/electrocoder/IOThook/issues
      sayfasina gidiniz.

      Yayin ve sahiplik http://mesebilisim.com
    */

    #include "SoftwareSerial.h"

    String ssid = "WIFI_ID";
    String password = "WIFI_PASSWORD";

    SoftwareSerial esp(10, 11);// RX, TX

    String data;

    String server = "iothook.com";

    String uri = "/api/update/";

    void setup() {

      esp.begin(115200);

      Serial.begin(115200);

      Serial.println("Arduino ile ESP8266 Wifi Modul Testi");
      Serial.println("          www.IOThook.com           ");
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

      data = "{\"api_key\":\"58088bb005633bb39cdf3b7d\",\"field_1\":" + String(random(0, 100)) + "}";

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

Arduino and ESP8266 HTTP POST Send Data 2
-----------------------------------------

In this example, Arduino code is given for sending data to iothook with ESP8266 connected to Arduino Uno with RX and TX.
In the example, random numbers between 0-100 were generated and the device was sent to the device with
"# 650 - iot_examples" on iothook.

You can find this example and others at `IoT Examples Github <https://github.com/meseiot/iot-examples/blob/master/http/arduino/esp8266/arduino_esp8266_post_send_data.ino>`_.


.. code-block:: c

    /*
      Arduino ile ESP8266 Wifi Modul Testi

      Kod Arduino ya yuklendiginde Arduino IDE nin Serial Monitor u
      ile ESP8266 arasinda haberlesme gozlenebilir.

      Arduino ile ESP8266 arasindaki iletisim Baud ayari
      115200 olmalidir.

      Arduino 0 ile 100 arasinda uretmis oldugu 2 adet Random sayıyı iothook a gonderir.
      Bu sayılar 'data' değişkeni içerisinde field_1 ve field_2 değerleridir. Bu değerler
      sensör olarak kullanılmaktadır. Sıcaklık  ve Nem gibi sensörlerinizi bu alanlara
      gönderebilirsiniz.

      Bu cihaza ait datalar
      https://iothook.com/en/device/data/12/
      adresinden gercek zamanli olarak izlenebilir.

      Bu ornek IOThook servisine veri gondermek icin baslangic ayarlarinin
      yapilmasini amaclamaktadir.

      24 Eylul 2017
      Sahin MERSIN

      Daha fazlasi icin

      http://www.iothook.com
      ve
      https://github.com/electrocoder/IOThook

      sitelerine gidiniz.
      Sorular ve destek talepleri icin
      https://github.com/electrocoder/IOThook/issues
      sayfasina gidiniz.

      Yayin ve sahiplik http://mesebilisim.com
    */

    #include "SoftwareSerial.h"

    String ssid = "WIFI_SSID";
    String password = "WIFI_PASSWORD";

    SoftwareSerial esp(10, 11);// RX, TX

    String data;

    String server = "iothook.com";

    String uri = "/api/update/";

    void setup() {

      esp.begin(115200);

      Serial.begin(115200);

      Serial.println("Arduino ile ESP8266 Wifi Modul Testi");
      Serial.println("          www.IOThook.com           ");
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

      data = "{\"api_key\":\"58088bb005633bb39cdf3b7d\",\"field_1\":" + String(random(0, 100)) + ",\"field_2\":" + String(random(0, 100)) + "}";

      httppost();

      delay(8000);

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


Arduino, ESP8266, Nodemcu GET Metodu ile Veri Gönderme
======================================================

IOThook Api v1.4 güncellemesi ile GET metodu ile veri göndermeye izin vermektedir.

Bu örneğe ve diğerlerine `IOTHOOK Git`_ sayfasından ulaşabilirsiniz.

Bu örnekde Arduino, ESP8266 ve NodeMCU ile ile Get metodu kullanarak veri gönderme örneği verilmiştir:

.. code-block:: c

    // 18.09.2017
    // Guncelleme : 19.08.2019
    // nodemcu ile sicaklik ve nem takibi
    // electrocoder@gmail.com
    // sahin mersin
    // v1

    #include <ESP8266WiFi.h>          //https://github.com/esp8266/Arduino

    //needed for library
    #include <DNSServer.h>
    #include <ESP8266WebServer.h>
    #include <WiFiManager.h>          //https://github.com/tzapu/WiFiManager

    //for LED status
    #include <Ticker.h>

    #include <ESP8266HTTPClient.h>

    #include "DHT.h"

    #define DHTPIN 4     // what digital pin we're connected to   // D2 - GPIO4
    #define DHTTYPE DHT11

    DHT dht(DHTPIN, DHTTYPE);

    Ticker ticker;

    void tick()
    {
      //toggle state
      int state = digitalRead(BUILTIN_LED);  // get the current state of GPIO1 pin
      digitalWrite(BUILTIN_LED, !state);     // set pin to the opposite state
    }

    //gets called when WiFiManager enters configuration mode
    void configModeCallback (WiFiManager *myWiFiManager) {
      Serial.println("Entered config mode");
      Serial.println(WiFi.softAPIP());
      //if you used auto generated SSID, print it
      Serial.println(myWiFiManager->getConfigPortalSSID());
      //entered config mode, make led toggle faster
      ticker.attach(0.2, tick);
    }


    void setup() {
      // put your setup code here, to run once:
      Serial.begin(115200);

      //set led pin as output
      pinMode(BUILTIN_LED, OUTPUT);

      // start ticker with 0.5 because we start in AP mode and try to connect
      ticker.attach(0.6, tick);

      //WiFiManager
      //Local intialization. Once its business is done, there is no need to keep it around
      WiFiManager wifiManager;
      //reset settings - for testing
      //wifiManager.resetSettings();

      //set callback that gets called when connecting to previous WiFi fails, and enters Access Point mode
      wifiManager.setAPCallback(configModeCallback);

      //fetches ssid and pass and tries to connect
      //if it does not connect it starts an access point with the specified name
      //here  "AutoConnectAP"
      //and goes into a blocking loop awaiting configuration
      if (!wifiManager.autoConnect("MeseIoT", "MeseIoT**")) {
        Serial.println("failed to connect and hit timeout");
        //reset and try again, or maybe put it to deep sleep
        ESP.reset();
        delay(1000);
      }

      //if you get here you have connected to the WiFi
      Serial.println("connected...yeey :)");
      ticker.detach();
      //keep LED on
      digitalWrite(BUILTIN_LED, LOW);

      dht.begin();
    }


    void loop() {
      // Wait a few seconds between measurements.
      delay(2000);

      // Reading temperature or humidity takes about 250 milliseconds!
      // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
      float h = dht.readHumidity();
      // Read temperature as Celsius (the default)
      float t = dht.readTemperature();
      // Read temperature as Fahrenheit (isFahrenheit = true)
      float f = dht.readTemperature(true);

      // Check if any reads failed and exit early (to try again).
      if (isnan(h) || isnan(t) || isnan(f)) {
        Serial.println("Failed to read from DHT sensor!");
        return;
      }

      // Compute heat index in Fahrenheit (the default)
      float hif = dht.computeHeatIndex(f, h);
      // Compute heat index in Celsius (isFahreheit = false)
      float hic = dht.computeHeatIndex(t, h, false);

      Serial.print("Humidity: ");
      Serial.print(h);
      Serial.print(" %\t");
      Serial.print("Temperature: ");
      Serial.print(t);
      Serial.print(" *C ");
      Serial.print(f);
      Serial.print(" *F\t");
      Serial.print("Heat index: ");
      Serial.print(hic);
      Serial.print(" *C ");
      Serial.print(hif);
      Serial.println(" *F");

      ///
      HTTPClient http;

      // configure server and url
      http.begin("http://iothook.com/api/update/?api_key=58088bb005633bb39cdf3b7d&field_1=" + String(t) + "&field_2=" + String(h) + "");
      //http.begin("192.168.1.12", 80, "/test.html");

      Serial.print("[HTTP] GET...\n");
      // start connection and send HTTP header
      int httpCode = http.GET();
      if (httpCode > 0) {
        // HTTP header has been send and Server response header has been handled
        Serial.printf("[HTTP] GET... code: %d\n", httpCode);

        // file found at server
        if (httpCode == HTTP_CODE_OK) {

          // get lenght of document (is -1 when Server sends no Content-Length header)
          int len = http.getSize();

          // create buffer for read
          uint8_t buff[128] = { 0 };

          // get tcp stream
          WiFiClient * stream = http.getStreamPtr();

          // read all data from server
          while (http.connected() && (len > 0 || len == -1)) {
            // get available data size
            size_t size = stream->available();

            if (size) {
              // read up to 128 byte
              int c = stream->readBytes(buff, ((size > sizeof(buff)) ? sizeof(buff) : size));

              // write it to Serial
              Serial.write(buff, c);

              if (len > 0) {
                len -= c;
              }
            }
            delay(1);
          }

          Serial.println();
          Serial.print("[HTTP] connection closed or file end.\n");

        }
      } else {
        Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
      }

      http.end();
      ////
      delay(13000);
    }


GO GET Metodu ile Veri Gönderme
===============================

IOThook Api v1.4 güncellemesi ile GET metodu ile veri göndermeye izin vermektedir.

Bu örneğe ve diğerlerine `IOTHOOK Git`_ sayfasından ulaşabilirsiniz.

Bu örnekde GO dili ile ile Get metodu kullanarak veri gönderme örneği verilmiştir:

.. code-block:: go

    // 04 Eylul 2017
    // Guncelleme: 19 Agustos 2019
    // Sahin MERSIN
    // iothook.com
    // postman kullanilarak olusturulmustur


    package main

    import (
        "fmt"
        "net/http"
        "io/ioutil"
    )

    func main() {

        url := "http://iothook.com/api/update?api_key=58088bb005633bb39cdf3b7d&field_1=10&field_2=2&field_3=3"

        req, _ := http.NewRequest("GET", url, nil)

        req.Header.Add("cache-control", "no-cache")

        res, _ := http.DefaultClient.Do(req)

        defer res.Body.Close()
        body, _ := ioutil.ReadAll(res.Body)

        fmt.Println(res)
        fmt.Println(string(body))

    }


PHP GET Metodu ile Veri Gönderme
================================

IOThook Api v1.4 güncellemesi ile GET metodu ile veri göndermeye izin vermektedir.

Bu örneğe ve diğerlerine `IOTHOOK Git`_ sayfasından ulaşabilirsiniz.

Bu örnekde PHP dili ile ile Get metodu kullanarak veri gönderme örneği verilmiştir:

.. code-block:: php

    // 04 Eylul 2017
    // Guncelleme: 19 Agustos 2019
    // Sahin MERSIN
    // iothook.com
    // postman kullanilarak olusturulmustur

    <?php

    $request = new HttpRequest();
    $request->setUrl('http://iothook.com/api/update');
    $request->setMethod(HTTP_METH_GET);

    $request->setQueryData(array(
      'api_key' => '58088bb005633bb39cdf3b7d',
      'field_1' => '10',
      'field_2' => '2',
      'field_3' => '3'
    ));

    $request->setHeaders(array(
      'postman-token' => '791ba738-7cb8-a920-0e5c-883cfb3e4498',
      'cache-control' => 'no-cache'
    ));

    try {
      $response = $request->send();

      echo $response->getBody();
    } catch (HttpException $ex) {
      echo $ex;
    }


NodeJS GET Metodu ile Veri Gönderme
===================================

IOThook Api v1.4 güncellemesi ile GET metodu ile veri göndermeye izin vermektedir.

Bu örneğe ve diğerlerine `IOTHOOK Git`_ sayfasından ulaşabilirsiniz.

Bu örnekde NodeJS Native metodu kullanarak veri gönderme örneği verilmiştir:

.. code-block:: js

    // 04 Eylul 2017
    // Guncelleme: 19 Agustos 2019
    // Sahin MERSIN
    // iothook.com
    // postman kullanilarak olusturulmustur

    var http = require("http");

    var options = {
      "method": "GET",
      "hostname": "iothook.com",
      "port": null,
      "path": "/api/update?api_key=58088bb005633bb39cdf3b7d&field_1=10&field_2=2&field_3=3",
      "headers": {
        "cache-control": "no-cache",
        "postman-token": "033da3c8-6196-cd49-f72d-1850a7d18500"
      }
    };

    var req = http.request(options, function (res) {
      var chunks = [];

      res.on("data", function (chunk) {
        chunks.push(chunk);
      });

      res.on("end", function () {
        var body = Buffer.concat(chunks);
        console.log(body.toString());
      });
    });

    req.end();


Javascript Jquery Ajax GET Metodu ile Veri Gönderme
===================================================

IOThook Api v1.4 güncellemesi ile GET metodu ile veri göndermeye izin vermektedir.

Bu örneğe ve diğerlerine `IOTHOOK Git`_ sayfasından ulaşabilirsiniz.

Bu örnekde NodeJS Native metodu kullanarak veri gönderme örneği verilmiştir:

.. code-block:: js

    // 04 Eylul 2017
    // Guncelleme: 19 Agustos 2019
    // Sahin MERSIN
    // iothook.com
    // postman kullanilarak olusturulmustur

    var settings = {
      "async": true,
      "crossDomain": true,
      "url": "http://iothook.com/api/update?api_key=58088bb005633bb39cdf3b7d&field_1=10&field_2=2&field_3=3",
      "method": "GET",
      "headers": {
        "cache-control": "no-cache",
      }
    }

    $.ajax(settings).done(function (response) {
      console.log(response);
    });


Java Unirest GET Metodu ile Veri Gönderme
=========================================

IOThook Api v1.4 güncellemesi ile GET metodu ile veri göndermeye izin vermektedir.

Bu örneğe ve diğerlerine `IOTHOOK Git`_ sayfasından ulaşabilirsiniz.

Bu örnekde NodeJS Native metodu kullanarak veri gönderme örneği verilmiştir:

.. code-block:: java

    // 04 Eylul 2017
    // Guncelleme: 19 Agustos 2019
    // Sahin MERSIN
    // iothook.com
    // postman kullanilarak olusturulmustur

    HttpResponse<String> response = Unirest.get("http://iothook.com/api/update?api_key=58088bb005633bb39cdf3b7d&field_1=10&field_2=2&field_3=3")
      .header("cache-control", "no-cache")
      .asString();


Java Unirest GET Metodu ile Veri Gönderme
=========================================

IOThook Api v1.4 güncellemesi ile GET metodu ile veri göndermeye izin vermektedir.

Bu örneğe ve diğerlerine `IOTHOOK Git`_ sayfasından ulaşabilirsiniz.

Bu örnekde NodeJS Native metodu kullanarak veri gönderme örneği verilmiştir:

.. code-block:: java

    // 04 Eylul 2017
    // Guncelleme: 19 Agustos 2019
    // Sahin MERSIN
    // iothook.com
    // postman kullanilarak olusturulmustur

    OkHttpClient client = new OkHttpClient();

    Request request = new Request.Builder()
      .url("http://iothook.com/api/update?api_key=58088bb005633bb39cdf3b7d&field_1=10&field_2=2&field_3=3")
      .get()
      .addHeader("cache-control", "no-cache")
      .build();

    Response response = client.newCall(request).execute();

