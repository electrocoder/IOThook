
# isi ve nem degerlerini python ile gonderme
# 16.05.2016
# electro

import json
import urllib
import urllib2

headers = {'content-type': 'application/json'}

API_KEY = "11111"

url = 'http://iothook.com/channel/api/' + API_KEY

data = {"temperature":"28.45","humidity":"8",}

data = urllib.urlencode(data)

req = urllib2.Request(url, data)
response = urllib2.urlopen(req)

html = response.read()

print html

