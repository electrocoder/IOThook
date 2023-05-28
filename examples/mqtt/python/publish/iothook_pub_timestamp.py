

import paho.mqtt.client as paho
import time

broker = "iothook.com"
port = 1883


def on_publish(client, userdata, result):
    print("data published")

while True:
    print(" *** start " * 5)
    try:
        client = paho.Client()
        client.username_pw_set("iothookpublic", "iothookpublic")
        client.on_publish = on_publish
        client.connect(broker, port)

        for i in range(10):
            t = int(time.time())
            print(t)
            ret = client.publish("testtopic", "%s" % t)  # publish
            ret = client.publish("timestamp", "%s" % t)  # publish
            print(ret)
            time.sleep(1)
    except:
        print("conn error")
        time.sleep(10)

