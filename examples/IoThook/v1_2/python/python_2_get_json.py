# -*- coding: utf-8 -*-

"""
  Python 2 ile IoThook REST Api Testi

  Kod çalıştırıldığında 'data' değişkenine verilen 'all' değişkeni ile
  auth sahipliğindeki tüm veriler alınır.

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

url = 'https://iothook.com/api/v1.2/datas/?data=all'

auth=('test', 'test12345')

response = requests.get(url, auth=auth)
data = response.json()
# print data
