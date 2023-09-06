<?php

$request = new HttpRequest();
$request->setUrl('https://iothook.com/api/device/');
$request->setMethod(HTTP_METH_GET);

$request->setQueryData(array(
    'api_key' => 'b5d91b83c85276cddc84eb67',
    'results' => '1'
));

$request->setHeaders(array(
    'cache-control' => 'no-cache',
    'Connection' => 'keep-alive',
    'Accept-Encoding' => 'gzip, deflate',
    'Host' => 'iothook.com',
    'Postman-Token' => 'ce2f06c2-817e-414a-8c7a-2c2fc59ad043,dfad2e87-d4a1-4657-a5b6-183c4604c818',
    'Cache-Control' => 'no-cache',
    'Accept' => '*/*',
    'User-Agent' => 'PostmanRuntime/7.15.2'
));

try {
    $response = $request->send();

    echo $response->getBody();
} catch (HttpException $ex) {
    echo $ex;
}
