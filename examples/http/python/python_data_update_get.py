# -*- coding: utf-8 -*-

"""
  Python ile IoThook REST Api Testi

  Kod çalıştırıldığında APIKEY ile doğrulama gerçekleştirilir.
  Cihaz api_key ile ilgili veriler IoThook a post edilir.

  Bu ornek IotHook servisine veri almak/gondermek icin baslangic seviyesinde
  testlerin yapilmasini amaclamaktadir.

  11 Eylul 2017
  Güncelleme : 19 Agustos 2019
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

import pprint
import random
import time

import requests

for i in range(100):  # write api key
    url = 'http://iothook.com/api/update/?api_key=78b0ca6a4a7da7e20f689818&field_1={}&field_2={}'.format(
        random.randint(1, 100), round(random.uniform(0.0, 10.0), 2))

    response = requests.get(url)
    pprint.pprint(response.json())
    time.sleep(15)
