
// 04 Eylul 2017
// Sahin MERSIN
// iothook.com
// postman kullanilarak olusturulmustur

HttpResponse<String> response = Unirest.get("http://iothook.com/api/latest/datas/update?api_key=22dbb35d-9dd5-113c0342c44bb9&value_1=10&value_2=2&value_3=3")
  .header("cache-control", "no-cache")
  .asString();
