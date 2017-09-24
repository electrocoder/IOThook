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

url = 'http://iothook.com/api/latest/datas/'

for i in range(10):
    data = {
        'api_key': '0610ff97202d4e62609cf91-91f1-3',
        'value_1': i*1,
        }

    data_json = json.dumps(data)

    response = requests.post(url, data=data_json, headers=headers)
    pprint.pprint(response.json())
    time.sleep(15)
