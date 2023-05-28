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
