
// 04 Eylul 2017
// Sahin MERSIN
// iothook.com
// postman kullanilarak olusturulmustur

OkHttpClient client = new OkHttpClient();

Request request = new Request.Builder()
  .url("http://iothook.com/api/latest/datas/update?api_key=22dbb35d-9dd5-113c03420ec44bb9&value_1=10&value_2=2&value_3=3")
  .get()
  .addHeader("cache-control", "no-cache")
  .build();

Response response = client.newCall(request).execute();
