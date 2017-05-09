# Python 3 json post example

import requests
import json
import urllib
import random
import pprint
import time

headers = {'Content-type': 'application/json'}
url = 'http://localhost:8000/api/v1.2/datas/'
auth=('test', 'test12345')

for i in range(10):
    data={
        'api_key':'adfac015d03-1b88c142532',
        'element_1':'fff', 'value_1':i*123,
        'element_2':'vvv', 'value_2':i*456,
        }

    data_json = json.dumps(data)

    response = requests.post(url, data=data_json, headers=headers, auth=auth)
    pprint.pprint(response.json())
    time.sleep(20)
