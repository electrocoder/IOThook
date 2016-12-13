#!/usr/bin/python
#-*- coding: utf-8 -*-

# mac os x, temperature, cpu,
# 18.05.2016
# electro

# Source 
# Apple System Management Control (SMC) Tool 
# Copyright (C) 2006
# Inspiration 
#  * http://www.eidac.de/smcfancontrol/
#  * https://github.com/hholtmann/smcFanControl/tree/master/smc-command

import subprocess
import json
import urllib
import urllib2
import time
from datetime import datetime

headers = {'content-type': 'application/json'}
API_KEY = "*****"
url = 'https://iothook.com/channel/api/' + API_KEY

for i in range(5):
	p = subprocess.Popen(['./osx-cpu-temp',], stdout=subprocess.PIPE, stderr=subprocess.PIPE)
	out, err = p.communicate()
	data = {"temperature":"%d" % float(out[:4]),"datetime":"%s" % datetime.now(),}
	data = urllib.urlencode(data)
	req = urllib2.Request(url, data)
	response = urllib2.urlopen(req)
	html = response.read()
	print html
	print i
	time.sleep(10) # delays for 10 seconds
