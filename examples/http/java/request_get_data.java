OkHttpClient client = new OkHttpClient();

Request request = new Request.Builder()
    .url("https://iothook.com/api/device/?api_key=9e722c4fc6c834b15ba01e86&results=1")
    .get()
    .addHeader("User-Agent", "PostmanRuntime/7.15.2")
    .addHeader("Accept", "*/*")
    .addHeader("Cache-Control", "no-cache")
    .addHeader("Postman-Token", "ce2f06c2-817e-414a-8c7a-2c2fc59ad043,bdcd2494-5109-4621-8256-296e0c6a4fad")
    .addHeader("Host", "iothook.com")
    .addHeader("Accept-Encoding", "gzip, deflate")
    .addHeader("Connection", "keep-alive")
    .addHeader("cache-control", "no-cache")
    .build();

Response response = client.newCall(request).execute();
