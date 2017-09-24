# Python 3 json post example

import requests
import json
import urllib
import random
import pprint
import time

headers = {'Content-type': 'application/json'}
url = 'https://iothook.com/api/v1.2/datas/'
auth=('test', 'test12345')

for i in range(1):
    data={
        'api_key':'f8c4a4d07a6-dc92f27f7b2',
        'element_1':'sicaklik', 'value_1':i*100,
        'element_2':'isik', 'value_2':i*200,
        'element_3':'hareket', 'value_3':i*300,
        'element_4':'bar', 'value_4':i*400,
        'element_5':'nem', 'value_5':i*500,
        }

    data_json = json.dumps(data)

    response = requests.post(url, data=data_json, headers=headers, auth=auth)
    pprint.pprint(response.json())
    # time.sleep(1)
