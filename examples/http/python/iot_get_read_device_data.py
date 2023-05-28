"""
  Python ile IoThook REST Api Testi

  IoThook'da her cihazin bir kimlik numarasi APIKEY'i vardir.
  Bu APIKEY kullanilarak veriler IoThook'a GET metodu gonderilir ve cihaz detay verileri alinir.

  Bu ornek IotHook servisine veri almak/gondermek icin baslangic seviyesinde
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

import requests

# demo account API_KEY
# https://iothook.com/en/device/data/650/
# 650 - iot_examples
API_KEY = 'f1403e03949c7f9060a4bdd2'  # read api key
url = 'http://iothook.com/api/device/?api_key=' + API_KEY + "&results=1"

response = requests.get(url)
data = response.json()
print("data", data)
print("len(data)", len(data))
print("data[0]['id']", data[0]['id'])
