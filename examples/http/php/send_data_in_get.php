// 04 Eylul 2017
// Guncelleme: 19 Agustos 2019
// Sahin MERSIN
// iothook.com
// postman kullanilarak olusturulmustur

    <?php

    $request = new HttpRequest();
    $request->setUrl('http://iothook.com/api/update');
    $request->setMethod(HTTP_METH_GET);

	// https://iothook.com/en/device/data/100/
	// #100 - Demo Data HTTP

    $request->setQueryData(array(
      'api_key' => '9e722c4fc6c834b15ba01e86',
      'field_1' => '10',
      'field_2' => '2',
      'field_3' => '3'
    ));

    $request->setHeaders(array(
      'postman-token' => '791ba738-7cb8-a920-0e5c-883cfb3e4498',
      'cache-control' => 'no-cache'
    ));

    try {
      $response = $request->send();

      echo $response->getBody();
    } catch (HttpException $ex) {
      echo $ex;
    }
