.. _full-featured-mqtt-client:

*************************
Full Featured MQTT Client
*************************

MQTT Brokera Mesaj Gönderme ve Alma


MQTT Broker kimlik doğrulama ile çalışır.

Örnek -> Mesaj yayınlama: mosquitto_pub -h iothook.com -p 1883 -t “temp/random” -m “6” -u pub_user -P iothook_pub_user

Örnek -> Mesaja abone olma: mosquitto_sub -h iothook.com -p 1883 -t “temp/random” -u pub_user -P iothook_pub_user


MQTT Brokera için Test Kullanıcıları:

Kullanıcı Adı : pub_user Şifre : iothook_pub_user

Kullanıcı Adı : sub_user Şifre : iothook_sub_user

Kullanıcı Adı : pub_client Şifre : iothook_pub_client

Kullanıcı Adı : sub_client Şifre : iothook_sub_client



Websockets Client Uygulaması Apache License Version 2.0 ile HiveMQ http://www.hivemq.com/ tarafından dağıtılmaktadır. Lisans hakkında ayrıca bilgi alınız.


Temp client sayfasına
https://iothook.com/mqtt/full-featured-mqtt-client/
adresinden ulaşabilirsiniz.
