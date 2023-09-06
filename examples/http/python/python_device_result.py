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


