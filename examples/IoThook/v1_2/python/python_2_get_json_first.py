# -*- coding: utf-8 -*-

"""
  Python 2 ile IoThook REST Api Testi

  Kod çalıştırıldığında 'data' değişkenine verilen 'first' değişkeni ile
  auth sahipliğindeki ilk veri alınır. 'channel' değişkeni Iothook dashboard
  Kanal oluşturma sırasında otomatik verilen id numarasıdır.

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

url = 'https://iothook.com/api/v1.2/datas/?data=first&channel=106'

auth=('test', 'test12345')

response = requests.get(url, auth=auth)
data = response.json()
# print data
