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
# https://iothook.com/en/device/data/100/
# 100 - Demo Data HTTP
API_KEY = '9e722c4fc6c834b15ba01e86'  # write api key
url = 'http://iothook.com/api/update/'

for i in range(1000):
    data = {  # write api key
        'api_key': API_KEY,  # demo hesap #100 - Demo Data HTTP
        'field_1': random.randint(0, 100),
        'field_2': random.randint(0, 100),
        'field_3': random.randint(0, 100),
        'field_4': random.randint(0, 100),
        'field_5': random.randint(0, 100),
        'field_6': random.randint(0, 100),
        'field_7': random.randint(0, 100),
        'field_8': random.randint(0, 100),
    }

    data_json = json.dumps(data)

    response = requests.post(url, data=data_json, headers=headers)
    pprint.pprint(response.json())
    time.sleep(15)
