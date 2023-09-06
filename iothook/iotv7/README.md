# IoThook iotv7, Simple Django REST framework IoT Web APIs

IoThook
-------
IoThook is a very simple IoT REST API. IoThook is developed using Django and the REST framework.
There are 2 methods in IoThook.

* api/device : Used for read APIs
    * 1-Read Data-All : http://localhost:8000/api/device/?api_key=662ebeaebb31d095c81b2de5
    * 2-Read Data-Result : http://localhost:8000/api/device/?api_key=662ebeaebb31d095c81b2de5&results=2
    * 3-Read Data-Result & Start_Date : http://localhost:8000/api/device/?api_key=662ebeaebb31d095c81b2de5&results=2&start_date=2023-06-20&end_date=2023-07-03
* api/update : Used for write APIs
    * 4-Write Data-GET : http://localhost:8000/api/update/?api_key=f014406b5a218b1904d39b5c&field_1=11&field_2=22
    * 5-Write Data-POST : http://localhost:8000/api/update/

Requirements
------------
* Python 3.11
* django==4.2.2
* djangorestframework
* markdown==3.4.3
* django-filter==23.2
* drf-yasg[validation]

Swagger
-------
IoTHook IoT dashboard Django Rest Framework Swagger generator http://localhost:8000/swagger/

ReDoc
-----
IoTHook IoT dashboard Django Rest Framework redoc generator http://localhost:8000/redoc/

User Groups
-----------
4 user groups have been created.
* Free
* Starter
* Basic
* Pro

Users
-----
* superuser:publicmese
* freeuser:publicmese
* starteruser:publicmese
* basicuser:publicmese
* prouser:publicmese

Thanks
------
Mese Software

