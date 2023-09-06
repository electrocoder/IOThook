    // 04 Eylul 2017
    // Guncelleme: 19 Agustos 2019
    // Sahin MERSIN
    // iothook.com
    // postman kullanilarak olusturulmustur

    var settings = {
      "async": true,
      "crossDomain": true,
      "url": "http://iothook.com/api/update?api_key=9e722c4fc6c834b15ba01e86&field_1=10&field_2=2&field_3=3",
      "method": "GET",
      "headers": {
        "cache-control": "no-cache",
      }
    }

    $.ajax(settings).done(function (response) {
      console.log(response);
    });
    