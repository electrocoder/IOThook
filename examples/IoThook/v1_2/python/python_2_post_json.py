# -*- coding: utf-8 -*-

"""
  Python 2 ile IoThook REST Api Testi

  Kod çalıştırıldığında auth kullanıcı adı ve şifre ile doğrulama gerçekleştirilir.
  Kanal api_key ile ilgili kanal ve element değerleri IoThook a post edilir.

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

  Yayin ve sahiplik http://mesebilisim.com
"""

import requests
import json
import time


headers = {'Content-type': 'application/json'}

url = 'https://iothook.com/api/v1.2/datas/'


auth=('anonymoususer', 'a12345678')

for i in range(5):
    data={
        'api_key':'F6H8h7dnGggc-9c-R-UahcVV20wbsVg',
        'value_1':i*10,
        'value_2':i*20,
        'value_3':i*30,
        'value_4':i*40,
        'value_5':i*50,
        }

    data_json = json.dumps(data)
    response = requests.post(url, data=data_json, headers=headers, auth=auth)
    print(response)
    print(response.json())
    time.sleep(5)
