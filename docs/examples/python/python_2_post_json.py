
import requests
import json
import urllib
import urllib2
import random
import pprint
import time


headers = {'Content-type': 'application/json'}
url = 'https://iothook.com/api/v1.2/datas/'
auth=('anonymoususer', 'a12345678')

for i in range(10):
    data={
        'api_key':'F6H8h7dnGggc-9c-R-UahcVV20wbsVg',
        'element_1':'isi', 'value_1':i*10,
        'element_2':'isik', 'value_2':i*20,
        'element_3':'hareket', 'value_3':i*30,
        'element_4':'bar', 'value_4':i*40,
        'element_5':'nem', 'value_5':i*50,
        }

    data_json = json.dumps(data)
    response = requests.post(url, data=data_json, headers=headers, auth=auth)
    print(response)
    print(response.json())
