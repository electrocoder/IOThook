# iothook.com

import paho.mqtt.client as mqtt
import time

broker = "iothook.com"
port = 1883


def on_message(client, userdata, message):
    print("message received ", str(message.payload.decode("utf-8")))
    print("message topic=", message.topic)
    print("message qos=", message.qos)
    print("message retain flag=", message.retain)


client = mqtt.Client("client-id-subscribe-1234567")
client.username_pw_set("iothookpublic", "iothookpublic")
client.on_message = on_message

print("connecting to broker")
client.connect(broker, port)

client.subscribe("timestamp/#")

client.loop_forever()
