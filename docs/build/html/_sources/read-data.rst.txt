*********
Read Data
*********

We need API KEY information for retrieving the data of temperature, damp, voltage, light etc. values like that which are sending Iot device.Datas which are sending from your Iot device can monitore with mobile devices like Pi, Android, iOs or your website.

For example; Assume that our device's name "Temperature sensor" and it will be in the device additionally assume that our sensors "temperature" and "humidity"

Data Retrieving with Python 2, Python 3 Json
--------------------------------------------

Get Example with Python Json:
The number of data specified by *results* was read,by using the *requests.get* method from the IOTHOOK server
Up to 99 pieces of data can be read with the *results* variable. If the *results* variable is not specified, only 1 data can be read.
The format of readed data is *json*

The following output is obtained, by running the following Python script.

    >>> [{'id': 502483, 'device': 17, 'field_1': '46', 'field_2': '6.70', 'field_3': None, 'field_4': None, 'field_5': None, 'field_6': None, 'field_7': None, 'field_8': None, 'pub_date': '2019-08-31T00:57:27.086837', 'remote_address': '88.242.132.150&python-requests/2.12.4&HTTP/1.1'}]
    >>> 1
    >>> 502483


You can find this example and others on the `IOTHOOK Git`_ page.

.. _IOTHOOK Git: https://github.com/electrocoder/iothookdoc/tree/main/examples/

.. highlight:: py
.. literalinclude:: /../../examples/http/python/get_json.py
    :caption: get_json.py
    :name: get_json.py

Getting the First Data with Python 2, Python 3 Json
---------------------------------------------------

Python Getting the First Data, Get Example with Json:

You can find this example and others on the `IOTHOOK Git`_ page.

.. highlight:: py
.. literalinclude:: /../../examples/http/python/request_get.py
    :caption: request_get.py
    :name: request_get.py

Getting the Last Data with Python 2, Python 3 Json
--------------------------------------------------

Python Getting the Last Data, Get Example with Json:

You can find this example and others on the `IOTHOOK Git`_ page.

.. highlight:: py
.. literalinclude:: /../../examples/http/python/request_get_last_data.py
    :caption: request_get_last_data.py
    :name: request_get_last_data.py

Fetching Data in JSON Format with C#
------------------------------------

It has been produced with the GET method using Postman so that the IoThook user can use the data of his device.

You can find this example and others on the `IOTHOOK Git`_ page.

.. highlight:: cs
.. literalinclude:: /../../examples/http/c#/request_get_data.cs
    :caption: c#/request_get_data.cs
    :name: c#/request_get_data.cs

IOT Data Fetching with GO
-------------------------

It has been produced with the GET method using Postman so that the IoThook user can use the data of his device.

You can find this example and others on the `IOTHOOK Git`_ page.

.. highlight:: go
.. literalinclude:: /../../examples/http/go/request_get_data.go
    :caption: request_get_data.go
    :name: request_get_data.go

IOT Data Fetching with JAVA
---------------------------

It has been produced with the GET method using Postman so that the IoThook user can use the data of his device.

You can find this example and others on the `IOTHOOK Git`_ page.

.. highlight:: java
.. literalinclude:: /../../examples/http/java/request_get_data.java
    :caption: request_get_data.java
    :name: request_get_data.java

IOT Data Fetching with PHP
--------------------------

It has been produced with the GET method using Postman so that the IoThook user can use the data of his device.

You can find this example and others on the `IOTHOOK Git`_ page.

.. highlight:: php
.. literalinclude:: /../../examples/http/php/request_get_data.php
    :caption: request_get_data.php
    :name: request_get_data.php

IOT Data Fetching with Ruby
---------------------------

It has been produced with the GET method using Postman so that the IoThook user can use the data of his device.

You can find this example and others on the `IOTHOOK Git`_ page.

.. highlight:: rb
.. literalinclude:: /../../examples/http/ruby/request_get_data.rb
    :caption: request_get_data.rb
    :name: request_get_data.rb

IOT Data Fetching with Javascript Ajax
--------------------------------------

It has been produced with the GET method using Postman so that the IoThook user can use the data of his device.

You can find this example and others on the `IOTHOOK Git`_ page.

.. highlight:: js
.. literalinclude:: /../../examples/http/javascript/request_get_data.js
    :caption: request_get_data.js
    :name: request_get_data.js

IOT Data Fetching with Python PySide2
-------------------------------------

PySide2 is the official Python module that provides access to the Qt 5.12+ framework for Python projects. Before using PySide2, the following modules need to be installed

    $ pip install matplotlib

    $ pip install numpy

    $ pip install PySide2

The installation of Python libraries has been done using pip. If pip is not installed on your system, you can visit the following address, https://bootstrap.pypa.io/get-pip.py, to download the file to your computer and run it.

Here, we will use PySide2 and Matplotlib to display the incoming data as a graph within a Window.

When the script is executed, we should see a window like the one shown below.

.. figure:: _static/pyside2-matplotlib-iothook.png
   :alt: pyside2-matplotlib-iothook.png
   :align: center

In this example, the interface design was created using *QT Designer*. For the widget,*Promote to ...* option was used with the *MplWidget* class. In prepearing this example *manap.se* `Manap`_ and *yapayzekalabs.blogspot.com* `Yapayzekalabs`_
used this sites. You can find more resources at these sites.

.. _Manap: https://blog.manap.se/pyqt/bolum3/plot.html
.. _Yapayzekalabs: http://yapayzekalabs.blogspot.com/2018/11/pyside2-gui-qt-designer-matplotlib.html

The test process was carried out with a device named *5 channel test* with id number *230* in IoThook.
 This device belongs to demo user

You can find this example and others on the `IOTHOOK Git`_ page.

iothook.ui folder:

.. highlight:: xml
.. literalinclude:: /../../examples/http/python/pyside2/iothook.ui
    :caption: iothook.ui

iothook.py folder:

.. highlight:: py
.. literalinclude:: /../../examples/http/python/pyside2/iothook.py
    :caption: iothook.py



