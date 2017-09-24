.. _read-data:

*******
Veri Al
*******

Iot cihazından gönderilen ısı, nem, voltaj, ışık gibi değerleri iothook data
merkezinden çekebilmek için öncelikle kanal üye kullanıcı adı ve giriş şifresineihtiyaç vardır. Iot cihazından gelen veriler, Android, iOS gibi mobil cihazınızdan
veya web sitenizden izlenebilir. Kanalınızın kullanımı genel kullanıma açık ise diğer kullanıcılar
ile de bu verileri paylaşabilirsiniz.

Örneğin; Kanal adımız "Temperature sensor" olarak belirlenmiş ve kanal içerisinde bulunacak
iot cihazımızdan "temperature" ve "humidity" element verileri gönderiliyor olsun.

Python 2, Python 3 Json ile Veri Alma
-------------------------------------

Python Json ile Get Örneği:

Bu örneği http://bit.ly/2jI1FNQ sayfasından inceleyebilirsiniz.

.. code-block:: python

    # -*- coding: utf-8 -*-

    """
      Python 2, Python 3 ile IoThook REST Api Testi

      Kod çalıştırıldığında 'data' değişkenine verilen 'all' değişkeni ile
      auth sahipliğindeki tüm veriler alınır.

      Bu ornek IotHook servisine veri almak/gondermek icin baslangic seviyesinde
      testlerin yapilmasini amaclamaktadir.

      10 Mayıs 2017
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

    API_KEY = '511b0173-95a5-11c814c2297e434c06'

    url = 'https://iothook.com/api/latest/datas/?api_key=' + API_KEY

    response = requests.get(url)
    data = response.json()
    print data

Python 2, Python 3 Json ile İlk Veriyi Alma
-------------------------------------------

Python İlk Veriyi Alma, Json ile Get Örneği:

Bu örneği http://bit.ly/2jI1FNQ sayfasından inceleyebilirsiniz.

.. code-block:: python

    # -*- coding: utf-8 -*-

    """
      Python 2 ile IoThook REST Api Testi

      Kod çalıştırıldığında 'data' değişkenine verilen 'first' değişkeni ile
      auth sahipliğindeki ilk veri alınır. 'channel' değişkeni Iothook dashboard
      Kanal oluşturma sırasında otomatik verilen id numarasıdır.

      Bu ornek IotHook servisine veri almak/gondermek icin baslangic seviyesinde
      testlerin yapilmasini amaclamaktadir.

      10 Mayıs 2017
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

    API_KEY = '511b0173-95a5-11c814c2297e434c06'

    url = 'https://iothook.com/api/latest/datas/?data=first&api_key=' + API_KEY

    response = requests.get(url)
    data = response.json()
    print data

Python 2, Python 3 Json ile Son Veriyi Alma
-------------------------------------------

Python Son Veriyi Alma, Json ile Get Örneği:

Bu örneği http://bit.ly/2jI1FNQ sayfasından inceleyebilirsiniz.

.. code-block:: python

    # -*- coding: utf-8 -*-

    """
      Python 2 ile IoThook REST Api Testi

      Kod çalıştırıldığında 'data' değişkenine verilen 'last' değişkeni ile
      auth sahipliğindeki en son veri alınır. 'channel' değişkeni Iothook dashboard
      Kanal oluşturma sırasında otomatik verilen id numarasıdır.

      Bu ornek IotHook servisine veri almak/gondermek icin baslangic seviyesinde
      testlerin yapilmasini amaclamaktadir.

      10 Mayıs 2017
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


    API_KEY = '516b0073-95a5-11c814c2597e434c06'

    url = 'https://iothook.com/api/latest/datas/?data=last&api_key=' + API_KEY

    response = requests.get(url)
    data = response.json()
    print data

Python 2, Python 3 Json ile Veriye Ait Detay Alma
-------------------------------------------------

Python veriye ait detay alma örneği:

Bu örneği http://bit.ly/2jI1FNQ sayfasından inceleyebilirsiniz.

.. code-block:: python

    # -*- coding: utf-8 -*-

    """
      Python 2, 3 ile IoThook REST Api Testi

      Kod çalıştırıldığında datas url yapısına parametre olarak verilen
      değer Kanal ve Element içerisinde tanımlı datanın ayrıntılarını getirir.

      Bu ornek IotHook servisine veri almak/gondermek icin baslangic seviyesinde
      testlerin yapilmasini amaclamaktadir.

      10 Mayıs 2017
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

    API_KEY = '516b0073-95a5-11c814c2297e434c06'

    url = 'https://iothook.com/api/latest/datas/4545/?api_key=' + API_KEY

    response = requests.get(url)
    data = response.json()
    print data

C# ile Json Formatında Veri Alma
--------------------------------

IoThook kullanıcısının tüm kanallarına ait veriyi alabilmesi için GET metodu ile '?data=last' değişkeninin gönderilmesi gereklidir.
Aynı örnekdeki data değişkeninin alabileceği değerler:

    * ?data=all     : Kullanıcının tüm datalarını getir
    * ?data=first   : Kullanıcının ilk datasını getir
    * ?data=last    : Kullanıcının son datasını getir

CSharp örneğinde *HttpWebRequest* metodu kullanılmıştır.

Bu örneği http://bit.ly/2jI1FNQ Github sayfasından inceleyebilirsiniz.

.. code-block:: c#

    /*
      C# ile IoThook REST Api Testi

      Bu örnek ile CSharp ve Request metodu ile kullanıcının datalarının get metodu ile alınması gerçekleştirilmiştir.
      'autorization' ile kullanıcı adı ve parola değeri verilmelidir.

      Bu ornek IotHook servisine veri almak/gondermek icin baslangic seviyesinde
      testlerin yapilmasini amaclamaktadir.

      29 Temmuz 2017
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

    using System;
    using System.IO;
    using System.Net;

    namespace Iothook
    {
        class Program
        {
            static void Main(string[] args)
            {
                string url = "";
                url = "https://iothook.com/api/v1.2/datas/?data=all"; // for all data

                var webRequest = (HttpWebRequest)WebRequest.Create(url);

                webRequest.Method = "GET";
                webRequest.ContentType = "application/json";
                webRequest.UserAgent = "Mozilla/5.0 (Windows NT 5.1; rv:28.0) Gecko/20100101 Firefox/28.0";
                webRequest.ContentLength = 0;

                string autorization = "USERNAME" + ":" + "PASSWORD";
                byte[] binaryAuthorization = System.Text.Encoding.UTF8.GetBytes(autorization);
                autorization = Convert.ToBase64String(binaryAuthorization);
                autorization = "Basic " + autorization;
                webRequest.Headers.Add("AUTHORIZATION", autorization);

                var webResponse = (HttpWebResponse)webRequest.GetResponse();

                if (webResponse.StatusCode != HttpStatusCode.OK)
                    Console.WriteLine(webResponse.Headers.ToString());

                using (StreamReader reader = new StreamReader(webResponse.GetResponseStream()))
                {
                    Console.WriteLine(reader.ReadToEnd());
                    reader.Close();
                    webRequest.Abort();
                }

                Console.ReadLine();
            }
        }
    }


