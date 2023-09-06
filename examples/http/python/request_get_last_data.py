# -*- coding: utf-8 -*-

"""
    IoThook REST Api Test with Python 2, Python 3 

    This example is at the beginner level for sending/receiving data to the IotHook service.
    it aims to carry out tests.

    10 May 2017
    Update: 19 August 2019
    Sahin MERSIN

    For more

    http://www.iothook.com
    and
    https://github.com/electrocoder/iotHook

    go to theese sites

    For questions and support requests
    https://github.com/electrocoder/iotHook/issues
    
    you can take support Mese Bilisim or above github page.
    Broadcasting : http://mesebilisim.com

    Licensed under the Apache License, Version 2.0 (the "License").
    You may not use this file except in compliance with the License.
    A copy of the License is located at

    http://www.apache.org/licenses/

"""

import requests

# read api key
API_KEY = 'b5d91b83c85276cddc84eb67' # demo account #100 Demo Data HTTP Temperature sensor

url = 'https://iothook.com/api/device/?api_key=' + API_KEY

response = requests.get(url)
data = response.json()
print(data)
print(data['datas'][0]['id'])
print(data['datas'][0]['pub_date'])
