# 12.10.2022
# timestamp/#
# mqtt_publish_subscribe.py


import paho.mqtt.client as paho
import time
from datetime import datetime
import calendar

broker = "iothook.com"
port = 1883
topic = "timestamp"


def publish():
    print("publish")
    timestamp = calendar.timegm(time.gmtime())
    ret = client.publish(topic, timestamp) 
    time.sleep(1)


def on_publish(client, userdata, result):
    print("on_publish")


def on_connect(client, userdata, flags, rc):
    print("on_connect ", str(rc))
    client.subscribe(topic, qos=0)


def on_message(client, userdata, msg):
    print("on_message", msg.topic, str(msg.payload))
    publish()


client = paho.Client()
client.username_pw_set("iothookpublic", "iothookpublic")
client.on_publish = on_publish
client.on_connect = on_connect
client.on_message = on_message
client.connect(broker, port)

client.loop_forever()

