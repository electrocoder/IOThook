.. _mqtt-temp-test-client:

*********************
MQTT Temp Test Client
*********************

Iot MQTT Temp Test Client
Mosquitto Brokera websocket ile gelen temp/random başlığını dinler.

Bu örnek 'test.mosquitto.org' sitesinden alınmıştır. MQTT Temp örneğinin orjinal kaynağına 'desert-home.com' adresinden ve Github üzerinden ulaşabilirsiniz.
MQTT Brokera nasıl mesaj gönderebilirim?

Iothook MQTT brokerına veri göndermek için "temp/random" başlığı gönderilmelidir. Gönderilen değer -20 ile +50 aralığında kayar noktalı (float) veya tamsayı (int) formatında olmalıdır.

MQTT Broker kimlik doğrulama ile çalışır.

Örnek -> Mesaj yayınlama: mosquitto_pub -h iothook.com -p 1883 -t "temp/random" -m "6" -u pub_user -P iothook_pub_user

Örnek -> Mesaja abone olma: mosquitto_sub -h iothook.com -p 1883 -t "temp/random" -u pub_user -P iothook_pub_user

MQTT Brokera için Test Kullanıcıları:

Kullanıcı Adı : pub_user Şifre : iothook_pub_user

Kullanıcı Adı : sub_user Şifre : iothook_sub_user

Kullanıcı Adı : pub_client Şifre : iothook_pub_client

Kullanıcı Adı : sub_client Şifre : iothook_sub_client

.. figure:: _static/mqtt-temp-test.png
   :scale: 65 %
   :alt: mqtt-temp-test.png
   :align: center

   *MQTT Temp Test*

Temp client sayfasına
https://iothook.com/mqtt/mqtt-temp-test/
adresinden ulaşabilirsiniz.