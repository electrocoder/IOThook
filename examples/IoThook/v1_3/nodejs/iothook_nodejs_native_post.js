

// 04 Eylul 2017
// Sahin MERSIN
// iothook.com
// postman kullanilarak olusturulmustur

var http = require("http");

var options = {
  "method": "GET",
  "hostname": "iothook.com",
  "port": null,
  "path": "/api/latest/datas/update?api_key=22dbb35d-9dd5-113200ec44bb9&value_1=10&value_2=2&value_3=3",
  "headers": {
    "cache-control": "no-cache",
    "postman-token": "033da3c8-6196-cd49-f72d-1850a7d18500"
  }
};

var req = http.request(options, function (res) {
  var chunks = [];

  res.on("data", function (chunk) {
    chunks.push(chunk);
  });

  res.on("end", function () {
    var body = Buffer.concat(chunks);
    console.log(body.toString());
  });
});

req.end();
