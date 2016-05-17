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

from subprocess import call
import json
import urllib
import urllib2
import time
from datetime import datetime

headers = {'content-type': 'application/json'}
API_KEY = "xxxxxxx"
url = 'http://iothook.com/channel/api/' + API_KEY

for i in range(0,5):
	data = {"temperature":"%s" % call(["./osx-cpu-temp"]),"datetime":"%s" % datetime.now(),}
	data = urllib.urlencode(data)
	req = urllib2.Request(url, data)
	response = urllib2.urlopen(req)
	html = response.read()
	print html
	time.sleep(300) # delays for 300 seconds
