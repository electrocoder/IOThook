*******
Veri Al
*******

Iot cihazından gönderilen ısı, nem, voltaj, ışık gibi değerleri iothook data servisinden çekebilmek için öncelikle
cihaz API KEY bilgisine ihtiyaç vardır. Iot cihazından gelen veriler, Arduino, Raspberry Pi, Android, iOS gibi mobil
cihazınızdan veya web sitenizden izlenebilir.

Örneğin; Cihaz adımız "Temperature sensor" olarak belirlenmiş ve cihaz içerisinde bulunacak
sensörlerimiz "temperature" ve "humidity" olsun.

Python 2, Python 3 Json ile Veri Alma
-------------------------------------

Python Json ile Get Örneği:

IOTHOOK sunucusundan *requests.get* metodu kullanılarak *results* ile belirtilen sayı kadar veri okuması yapılmıştır.
*results* değişkeni ile en fazla 99 adet veri okunabilir. *results* değişkeni belirtilmez ise sadece 1 veri okunabilir.
Okunan verinin formatı *json* şeklindedir.

Aşağıdaki Python scriptinin çalıştırılması ile şu çıktı elde edilir.

    >>> [{'id': 502483, 'device': 17, 'field_1': '46', 'field_2': '6.70', 'field_3': None, 'field_4': None, 'field_5': None, 'field_6': None, 'field_7': None, 'field_8': None, 'pub_date': '2019-08-31T00:57:27.086837', 'remote_address': '88.242.132.150&python-requests/2.12.4&HTTP/1.1'}]
    >>> 1
    >>> 502483

Bu örneğe ve diğerlerine `IOTHOOK Git`_ sayfasından ulaşabilirsiniz.

.. _IOTHOOK Git: https://github.com/electrocoder/IOThook/tree/master/examples/

.. code-block:: python

    # -*- coding: utf-8 -*-

    """
      Python 2, Python 3 ile IoThook REST Api Testi

      Bu ornek IotHook servisine veri almak/gondermek icin baslangic seviyesinde
      testlerin yapilmasini amaclamaktadir.

      10 Mayıs 2017
      Guncelleme: 19 Agustos 2019
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

      Licensed under the Apache License, Version 2.0 (the "License").
      You may not use this file except in compliance with the License.
      A copy of the License is located at

      http://www.apache.org/licenses/

    """

    import requests

    # read api key
    API_KEY = 'ceb0024b84ff6fb7527d5506' # demo hesap #17 random test

    url = 'http://iothook.com/api/device/?api_key=' + API_KEY + "&results=1"

    response = requests.get(url)
    data = response.json()
    print(data)
    print(len(data))
    print(data[0]['id'])


Python 2, Python 3 Json ile İlk Veriyi Alma
-------------------------------------------

Python İlk Veriyi Alma, Json ile Get Örneği:

Bu örneğe ve diğerlerine `IOTHOOK Git`_ sayfasından ulaşabilirsiniz.

.. code-block:: python

    # -*- coding: utf-8 -*-

    """
      Python 2, Python 3 ile IoThook REST Api Testi

      Bu ornek IotHook servisine veri almak/gondermek icin baslangic seviyesinde
      testlerin yapilmasini amaclamaktadir.

      10 Mayıs 2017
      Guncelleme: 19 Agustos 2019
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

      Licensed under the Apache License, Version 2.0 (the "License").
      You may not use this file except in compliance with the License.
      A copy of the License is located at

      http://www.apache.org/licenses/

    """

    import requests

    # read api key
    API_KEY = '76d2628fd60903d3c1f7f8a0' # demo hesap #24 Temperature sensor

    url = 'https://iothook.com/api/device/?api_key=' + API_KEY + "&results=2"

    response = requests.get(url)
    data = response.json()
    print(data)
    print(data['datas'][0]['id'])
    print(data['datas'][0]['pub_date'])
    print(data['datas'][1]['id'])
    print(data['datas'][1]['pub_date'])


Python 2, Python 3 Json ile Son Veriyi Alma
-------------------------------------------

Python Son Veriyi Alma, Json ile Get Örneği:

Bu örneğe ve diğerlerine `IOTHOOK Git`_ sayfasından ulaşabilirsiniz.

.. code-block:: python

    # -*- coding: utf-8 -*-

    """
      Python 2, Python 3 ile IoThook REST Api Testi

      Bu ornek IotHook servisine veri almak/gondermek icin baslangic seviyesinde
      testlerin yapilmasini amaclamaktadir.

      10 Mayıs 2017
      Guncelleme: 19 Agustos 2019
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

      Licensed under the Apache License, Version 2.0 (the "License").
      You may not use this file except in compliance with the License.
      A copy of the License is located at

      http://www.apache.org/licenses/

    """

    import requests

    # read api key
    API_KEY = '76d2628fd60903d3c1f7f8a0' # demo hesap #24 Temperature sensor

    url = 'https://iothook.com/api/device/?api_key=' + API_KEY

    response = requests.get(url)
    data = response.json()
    print(data)
    print(data['datas'][0]['id'])
    print(data['datas'][0]['pub_date'])


C# ile Json Formatında Veri Alma
--------------------------------

IoThook kullanıcısının cihazına ait veriyi alabilmesi için GET metodu kullanılarak Postman ile üretilmiştir.

Bu örneğe ve diğerlerine `IOTHOOK Git`_ sayfasından ulaşabilirsiniz.

.. code-block:: c#

    /*
      C# ile IoThook REST Api Testi

      Bu örnekde CSharp ile cihaz datalarının get metodu ile alınması gerçekleştirilmiştir.

      Bu ornek IotHook servisine veri almak/gondermek icin baslangic seviyesinde
      testlerin yapilmasini amaclamaktadir.

      29 Temmuz 2017
      Guncelleme: 19 Agustos 2019
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

      Licensed under the Apache License, Version 2.0 (the "License").
      You may not use this file except in compliance with the License.
      A copy of the License is located at

      http://www.apache.org/licenses/
    */

    // demo hesap #24 Temperature sensor

    var client = new RestClient("https://iothook.com/api/device/?api_key=76d2628fd60903d3c1f7f8a0&results=1");
    var request = new RestRequest(Method.GET);
    request.AddHeader("cache-control", "no-cache");
    request.AddHeader("Connection", "keep-alive");
    request.AddHeader("Accept-Encoding", "gzip, deflate");
    request.AddHeader("Host", "iothook.com");
    request.AddHeader("Postman-Token", "ce2f06c2-817e-414a-8c7a-2c2fc59ad043,af31a3d8-02e4-49eb-b78f-05ebdce70149");
    request.AddHeader("Cache-Control", "no-cache");
    request.AddHeader("Accept", "*/*");
    request.AddHeader("User-Agent", "PostmanRuntime/7.15.2");
    IRestResponse response = client.Execute(request);


GO ile IOT Veri Alma
--------------------

IoThook kullanıcısının cihazına ait veriyi alabilmesi için GET metodu kullanılarak Postman ile üretilmiştir.

Bu örneğe ve diğerlerine `IOTHOOK Git`_ sayfasından ulaşabilirsiniz.

.. code-block:: go

    package main

    import (
        "fmt"
        "net/http"
        "io/ioutil"
    )

    func main() {

        url := "https://iothook.com/api/device/?api_key=76d2628fd60903d3c1f7f8a0&results=1"

        req, _ := http.NewRequest("GET", url, nil)

        req.Header.Add("User-Agent", "PostmanRuntime/7.15.2")
        req.Header.Add("Accept", "*/*")
        req.Header.Add("Cache-Control", "no-cache")
        req.Header.Add("Postman-Token", "ce2f06c2-817e-414a-8c7a-2c2fc59ad043,8a0938fc-5c87-459a-9b9f-fa6aebe561f2")
        req.Header.Add("Host", "iothook.com")
        req.Header.Add("Accept-Encoding", "gzip, deflate")
        req.Header.Add("Connection", "keep-alive")
        req.Header.Add("cache-control", "no-cache")

        res, _ := http.DefaultClient.Do(req)

        defer res.Body.Close()
        body, _ := ioutil.ReadAll(res.Body)

        fmt.Println(res)
        fmt.Println(string(body))

    }


JAVA ile IOT Veri Alma
----------------------

IoThook kullanıcısının cihazına ait veriyi alabilmesi için GET metodu kullanılarak Postman ile üretilmiştir.

Bu örneğe ve diğerlerine `IOTHOOK Git`_ sayfasından ulaşabilirsiniz.

.. code-block:: java

    OkHttpClient client = new OkHttpClient();

    Request request = new Request.Builder()
      .url("https://iothook.com/api/device/?api_key=76d2628fd60903d3c1f7f8a0&results=1")
      .get()
      .addHeader("User-Agent", "PostmanRuntime/7.15.2")
      .addHeader("Accept", "*/*")
      .addHeader("Cache-Control", "no-cache")
      .addHeader("Postman-Token", "ce2f06c2-817e-414a-8c7a-2c2fc59ad043,bdcd2494-5109-4621-8256-296e0c6a4fad")
      .addHeader("Host", "iothook.com")
      .addHeader("Accept-Encoding", "gzip, deflate")
      .addHeader("Connection", "keep-alive")
      .addHeader("cache-control", "no-cache")
      .build();

    Response response = client.newCall(request).execute();


PHP ile IOT Veri Alma
---------------------

IoThook kullanıcısının cihazına ait veriyi alabilmesi için GET metodu kullanılarak Postman ile üretilmiştir.

Bu örneğe ve diğerlerine `IOTHOOK Git`_ sayfasından ulaşabilirsiniz.

.. code-block:: php

    <?php

    $request = new HttpRequest();
    $request->setUrl('https://iothook.com/api/device/');
    $request->setMethod(HTTP_METH_GET);

    $request->setQueryData(array(
      'api_key' => '76d2628fd60903d3c1f7f8a0',
      'results' => '1'
    ));

    $request->setHeaders(array(
      'cache-control' => 'no-cache',
      'Connection' => 'keep-alive',
      'Accept-Encoding' => 'gzip, deflate',
      'Host' => 'iothook.com',
      'Postman-Token' => 'ce2f06c2-817e-414a-8c7a-2c2fc59ad043,dfad2e87-d4a1-4657-a5b6-183c4604c818',
      'Cache-Control' => 'no-cache',
      'Accept' => '*/*',
      'User-Agent' => 'PostmanRuntime/7.15.2'
    ));

    try {
      $response = $request->send();

      echo $response->getBody();
    } catch (HttpException $ex) {
      echo $ex;
    }


Ruby ile IOT Veri Alma
----------------------

IoThook kullanıcısının cihazına ait veriyi alabilmesi için GET metodu kullanılarak Postman ile üretilmiştir.

Bu örneğe ve diğerlerine `IOTHOOK Git`_ sayfasından ulaşabilirsiniz.

.. code-block:: ruby

    require 'uri'
    require 'net/http'

    url = URI("https://iothook.com/api/device/?api_key=76d2628fd60903d3c1f7f8a0&results=1")

    http = Net::HTTP.new(url.host, url.port)

    request = Net::HTTP::Get.new(url)
    request["User-Agent"] = 'PostmanRuntime/7.15.2'
    request["Accept"] = '*/*'
    request["Cache-Control"] = 'no-cache'
    request["Postman-Token"] = 'ce2f06c2-817e-414a-8c7a-2c2fc59ad043,8fe93ff6-b857-4978-838e-2d8efac2e6b6'
    request["Host"] = 'iothook.com'
    request["Accept-Encoding"] = 'gzip, deflate'
    request["Connection"] = 'keep-alive'
    request["cache-control"] = 'no-cache'

    response = http.request(request)
    puts response.read_body


Javascript Ajax ile IOT Veri Alma
---------------------------------

IoThook kullanıcısının cihazına ait veriyi alabilmesi için GET metodu kullanılarak Postman ile üretilmiştir.

Bu örneğe ve diğerlerine `IOTHOOK Git`_ sayfasından ulaşabilirsiniz.

.. code-block:: javascript

    var settings = {
      "async": true,
      "crossDomain": true,
      "url": "https://iothook.com/api/device/?api_key=76d2628fd60903d3c1f7f8a0&results=1",
      "method": "GET",
      "headers": {
        "User-Agent": "PostmanRuntime/7.15.2",
        "Accept": "*/*",
        "Cache-Control": "no-cache",
        "Postman-Token": "ce2f06c2-817e-414a-8c7a-2c2fc59ad043,27a5bb35-4b13-48b2-8dbd-efe7188a68c6",
        "Host": "iothook.com",
        "Accept-Encoding": "gzip, deflate",
        "Connection": "keep-alive",
        "cache-control": "no-cache"
      }
    }

    $.ajax(settings).done(function (response) {
      console.log(response);
    });


Python PySide2 ile IOT Veri Alma
---------------------------------

PySide2, Qt nin Python projelerinde Qt 5.12+ framework e erişimini sağlayan resmi Python modülüdür. PySide2 yi
kullanmadan önce yüklenmesi gereken modüller şu şekildedir.

    $ pip install matplotlib

    $ pip install numpy

    $ pip install PySide2

Python kütüphanelerinin yükleme işlemi pip ile yapılmıştır. Sisteminizde pip yüklü değil ise https://bootstrap.pypa.io/get-pip.py
adresine giderek dosyayı bilgisayarınıza kaydediniz ve çalıştırınız.

Biz burada PySide2 ve matplotlib kullanarak oluşturduğumuz Window içerisinde gelen verileri grafik olarak göstereceğiz.

Script çalıştırıldığında aşağıdaki gibi bir pencere görmemiz gerekiyor.

.. figure:: _static/pyside2-matplotlib-iothook.png
   :alt: pyside2-matplotlib-iothook.png
   :align: center

Bu örnekde *QT Designer* kullanılarak arayüz tasarımı yapılmıştır. Widget için *Promote to ...* seçeneği ile *MplWidget*
sınıfı kullanılmıştır. Bu örneği hazırlamada *manap.se* `Manap`_ ve *yapayzekalabs.blogspot.com* `Yapayzekalabs`_
sitelerinden faydalandım. Bu sitelerde daha fazla kaynak bulabilirsiniz.

.. _Manap: https://blog.manap.se/pyqt/bolum3/plot.html
.. _Yapayzekalabs: http://yapayzekalabs.blogspot.com/2018/11/pyside2-gui-qt-designer-matplotlib.html

Test işlemi IoThook da bulunan *230* id numaralı *5 channel test* isimli cihaz ile yapılmıştır.
 Bu cihaz demo kullanıcısına aittir.

Bu örneğe ve diğerlerine `IOTHOOK Git`_ sayfasından ulaşabilirsiniz.

iothook.ui dosyası:

.. literalinclude:: examples/python/pyside2/iothook.ui
    :caption: iothook.ui
    :name: iothook.ui


iothook.py dosyası:

.. literalinclude:: examples/python/pyside2/iothook.py
    :caption: iothook.py
    :name: iothook.py



