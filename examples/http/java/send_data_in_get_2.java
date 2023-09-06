// 04 Eylul 2017
// Guncelleme: 19 Agustos 2019
// Sahin MERSIN
// iothook.com
// postman kullanilarak olusturulmustur

OkHttpClient client = new OkHttpClient();

Request request = new Request.Builder()
  .url("http://iothook.com/api/update?api_key=9e722c4fc6c834b15ba01e86&field_1=10&field_2=2&field_3=3")
  .get()
  .addHeader("cache-control", "no-cache")
  .build();

Response response = client.newCall(request).execute();
