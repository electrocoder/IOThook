# -*- coding: utf-8 -*-

"""
  Python 2 ile IoThook REST Api Testi

  Kod çalıştırıldığında datas url yapısına parametre olarak verilen
  değer Kanal ve Element içerisinde tanımlı datanın ayrıntılarını getirir.

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

url = 'https://iothook.com/api/v1.2/datas/8864/'

auth=('test', 'test12345')

response = requests.get(url, auth=auth)
data = response.json()
# print data
