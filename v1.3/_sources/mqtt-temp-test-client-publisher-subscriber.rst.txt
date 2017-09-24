.. _mqtt-temp-test-client-publisher-subscriber:

*************************************
MQTT Test Client Publisher Subscriber
*************************************

MQTT Brokera Mesaj Gönderme ve Abone Olma
Mosquitto Brokera websocket ile gelen temp/random başlığını dinler.

Iothook MQTT brokerına veri göndermek için "temp/random" başlığı gönderilmelidir. Gönderilen veri kayar
noktalı (float), tamsayı (int) veya string (text) formatında olabilir.

MQTT Broker kimlik doğrulama ile çalışır.

Örnek -> Mesaj yayınlama: mosquitto_pub -h iothook.com -p 1883 -t "temp/random" -m "6" -u pub_user -P iothook_pub_user

Örnek -> Mesaja abone olma: mosquitto_sub -h iothook.com -p 1883 -t "temp/random" -u pub_user -P iothook_pub_user

MQTT Brokera için Test Kullanıcıları:

Kullanıcı Adı : pub_user Şifre : iothook_pub_user

Kullanıcı Adı : sub_user Şifre : iothook_sub_user

Kullanıcı Adı : pub_client Şifre : iothook_pub_client

Kullanıcı Adı : sub_client Şifre : iothook_sub_client

.. figure:: _static/mqtt-temp-test-client-publisher-subscriber.png
   :scale: 65 %
   :alt: mqtt-temp-test-client-publisher-subscriber.png
   :align: center

   *MQTT Test Publisher Subscriber*

Temp client sayfasına
https://iothook.com/mqtt/mqtt-temp-test-pub-sub/
adresinden ulaşabilirsiniz.