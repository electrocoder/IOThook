
// 04 Eylul 2017
// Sahin MERSIN
// iothook.com
// postman kullanilarak olusturulmustur


package main

import (
	"fmt"
	"net/http"
	"io/ioutil"
)

func main() {

	url := "http://iothook.com/api/latest/datas/update?api_key=22dbb35d-9dd5-113c0200ec44bb9&value_1=10&value_2=2&value_3=3"

	req, _ := http.NewRequest("GET", url, nil)

	req.Header.Add("cache-control", "no-cache")

	res, _ := http.DefaultClient.Do(req)

	defer res.Body.Close()
	body, _ := ioutil.ReadAll(res.Body)

	fmt.Println(res)
	fmt.Println(string(body))

}
