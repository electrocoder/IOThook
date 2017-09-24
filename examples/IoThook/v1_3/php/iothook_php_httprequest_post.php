

// 04 Eylul 2017
// Sahin MERSIN
// iothook.com
// postman kullanilarak olusturulmustur

<?php

$request = new HttpRequest();
$request->setUrl('http://iothook.com/api/latest/datas/update');
$request->setMethod(HTTP_METH_GET);

$request->setQueryData(array(
  'api_key' => '22dbb35d-9dd5-12300ec44bb9',
  'value_1' => '10',
  'value_2' => '2',
  'value_3' => '3'
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
