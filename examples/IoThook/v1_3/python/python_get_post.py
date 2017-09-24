# -*- coding: utf-8 -*-

"""
  Python ile IoThook REST Api Testi

  Kod çalıştırıldığında API_KEY ile doğrulama gerçekleştirilir.
  Kanal api_key ile ilgili kanal ve element değerleri IoThook a post edilir.

  Bu ornek IotHook servisine veri almak/gondermek icin baslangic seviyesinde
  testlerin yapilmasini amaclamaktadir.

  04 Eylul 2017
  Sahin MERSIN

  Daha fazlasi icin

  http://www.iothook.com
  ve
  https://github.com/electrocoder/iotHook

  sitelerine gidiniz.

  Sorular ve destek talepleri icin
  https://github.com/electrocoder/iotHook/issues
  sayfasindan veya Meşe Bilişim den yardım alabilirsiniz.

  Yayin ve sahiplik http://mesebilisim.com
"""

import requests
import json
import urllib
import random
import pprint
import time


headers = {'Content-type': 'application/json'}

API_KEY = '4545-96ae-118045454e945457e'

url = 'http://iothook.com/api/latest/datas/update?api_key=' + API_KEY + '&value_1=10&value_2=2&value_3=3'

for i in range(10):
    response = requests.get(url)
    data = response.json()
    print data
    time.sleep(15)
