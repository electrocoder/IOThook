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

API_KEY = '587c8454545eeb7b2c232'

url = 'http://iothook.com/api/latest/datas/?api_key=' + API_KEY + '&count=3'

response = requests.get(url)
data = response.json()
print data
print 45*'-'
print data['channel']
print 45*'-'
print data['data']
print 45*'-'
print data['data']['0']['value_1']
print 45*'-'
