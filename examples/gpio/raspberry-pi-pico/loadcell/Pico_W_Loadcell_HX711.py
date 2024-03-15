from machine import Pin
from hx711 import *

print("start")

with hx711(Pin(6), Pin(5)) as hx:
    hx.set_power(hx711.power.pwr_up)
    hx.set_gain(hx711.gain.gain_128)
    hx711.wait_settle(hx711.rate.rate_10)
    net = hx.get_value()
    print(net, net*2.38)

