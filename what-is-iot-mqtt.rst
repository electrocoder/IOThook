.. _what-is-iot-mqtt:

Iot Mqtt Nedir?
---------------

**MQTT** Message Queuing Telemetry Transport kelimelerinin baş harfleri ile tanıdığımız bu teknoloji
mesajın karşı tarafa ulaştırılması için kullanılan haberleşme protokolüdür.  Haberleşme için mesaj yayınlayan,
mesaja abone olan ve mesaj trafiğini kontrol eden yöneticiden oluşmaktadır.

Mesaj trafiğini kontrol eden yöneticiye BROKER, mesaj yayınına PUBLISH ve aboneye SUBSCRIBE denir. Mesaj alışverişi
publisher dan subscriber lara doğru yani yayıncılardan abonelere doğru olmaktadır.

.. figure:: _static/mqtt.png
   :scale: 65 %
   :alt: mqtt_org.jpg
   :align: center

   *MQTT*

Mqtt Protokolü Nasıldır?
------------------------

MQTT de asenkron haberleşme protokolü kullanılmaktadır. Mesaj yayıncıları ve mesaj alıcılar arasında
eşzamansız olarak veri taşınmaktadır. Diğer haberleşme yapılarına göre basit oluşu ve
minimum kaynak tüketmesi sebebiyle “machine-to-machine” (M2M)  makineden makineye veri
iletiminde ve (IOT) “Internet of Things” İnternete bağlı nesnelerin mesajlaşmasında tercih edilmektedir.
