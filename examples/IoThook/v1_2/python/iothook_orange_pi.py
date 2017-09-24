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

  Yayin : http://mesebilisim.com

  Licensed under the Apache License, Version 2.0 (the "License").
  You may not use this file except in compliance with the License.
  A copy of the License is located at

  http://www.apache.org/licenses/

"""

import requests
import json
import time

headers = {'Content-type': 'application/json'}

url = 'https://iothook.com/api/v1.2/datas/'

auth = ('test', 'test12345')

for i in range(10):
    data = {
        'api_key': 'ca7ef5fb1c9-774ddt6ec4a',
        'value_1': i * 36,
    }

    data_json = json.dumps(data)
    response = requests.post(url, data=data_json, headers=headers, auth=auth)
    print(response)
    print(response.json())
    time.sleep(15)
