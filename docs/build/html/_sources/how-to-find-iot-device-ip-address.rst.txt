*********************************
How to Find IoT Device IP Address
*********************************

The IP address of the IoT (Internet of Things) device is the unique identifier of the device on the network. The
IP address allows the device to connect to the network and allows it to communicate with other devices. In
some cases, we need the Global IP address of the IoT device. In order to PING the device and monitor the device, it
is necessary to know the IP address.

Here are some important functions of the IP address of the IoT device:

1. Communication: The IP address allows the IoT device to communicate with other devices. Using this
address, the device can exchange data, receive commands or send data to other devices.

2. Authentication: The IP address provides the unique identity of an IoT device on the network. Other
devices on the network can perform and confirm authentication processes using the IP address of the IoT device.

3. Discovery and Access: An IoT device's IP address makes it easy to find and access by other devices
on the network. Other devices can communicate and exchange data with it using the device's IP address.

4. Management: The IP address can be used for the management of the IoT device. Administrative functions
such as accessing the device's configuration settings or receiving updates can be performed via the IP address.

5. Remote Access: Most IoT devices allow users to access their devices remotely. The IP address allows
users to remotely access the device so that the device can be controlled or data monitored.

To summarize, the IP address of the IoT device provides the device's unique identity on the network
and able to communicate with other devices. It also simplifies device discovery, management, and remote access.

IoTHook IoT Device Get Global IP Address API
============================================

To find the IP address of the IoT device, you need to send a GET request from your Device to the IoTHook site.
You can find the IoT IP address by making a GET request to https://iothook.com/api/find-ip-address/ or
http://iothook.com/api/find-ip-address/ .

When IoTHook requests a GET, it can sample the IP address from JSON format as follows. {"ip":"184.53.56.28"}

IoTHook IoT Device Get Global IP Address API Arduino Ethernet Shield
--------------------------------------------------------------------

.. literalinclude:: /../../examples/http/arduino/arduino_ethernet_shield_get_ip.ino
    :language: c
    :caption: arduino_ethernet_shield_get_ip.ino
    :name: arduino_ethernet_shield_get_ip.ino
