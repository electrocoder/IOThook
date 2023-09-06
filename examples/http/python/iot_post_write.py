"""
  Python ile IoThook REST Api Testi

  IoThook'da her cihazin bir kimlik numarasi APIKEY'i vardir.
  Bu APIKEY kullanilarak veriler IoThook'a POST metodu ile gonderilir.

  Bu ornek IotHook servisine veri almak/gondermek icin baslangic seviyesinde
  testlerin yapilmasini amaclamaktadir.

  v1 : 20 Eylul 2017
  v2 : 19 Agustos 2019
  v3 : 21 Ekim 2021
  v4 : 31 Ekim 2022

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
import requests

headers = {'Content-type': 'application/json'}

# demo account API_KEY
# https://iothook.com/en/device/data/100/
# 100 - Demo Data HTTP
API_KEY = '9e722c4fc6c834b15ba01e86'  # write api key
url = 'http://iothook.com/api/update/'

data = {
    'api_key': API_KEY,
    'field_1': random.randint(1, 10),
    'field_2': round(random.uniform(0.0, 10.0), 2),
    'field_3': round(random.uniform(0.0, 10.0), 2),
}

data_json = json.dumps(data)

response = requests.post(url, data=data_json, headers=headers)
pprint.pprint(response.json())
