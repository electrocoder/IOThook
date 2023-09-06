/*
    Testing IoThook REST Api with C#

    In this example, device data is retrieved with CSharp with the get method.

    This example is at the beginner level for sending/receiving data to the IotHook service.
    it aims to carry out tests.

    29 July 2017
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
*/

// demo account #100 Demo Data HTTP

var client = new RestClient("https://iothook.com/api/device/?api_key=9e722c4fc6c834b15ba01e86&results=1");
var request = new RestRequest(Method.GET);
request.AddHeader("cache-control", "no-cache");
request.AddHeader("Connection", "keep-alive");
request.AddHeader("Accept-Encoding", "gzip, deflate");
request.AddHeader("Host", "iothook.com");
request.AddHeader("Postman-Token", "ce2f06c2-817e-414a-8c7a-2c2fc59ad043,af31a3d8-02e4-49eb-b78f-05ebdce70149");
request.AddHeader("Cache-Control", "no-cache");
request.AddHeader("Accept", "*/*");
request.AddHeader("User-Agent", "PostmanRuntime/7.15.2");
IRestResponse response = client.Execute(request);
