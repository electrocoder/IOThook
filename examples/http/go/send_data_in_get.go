// 04.05.2023
// GO language send data with GET method

package main

import (
	"io/ioutil"
	"log"
	"net/http"
)

func main() {
	resp, err := http.Get("http://iothook.com/api/update?api_key=9e722c4fc6c834b15ba01e86&field_1=10&field_2=2&field_3=3")
	if err != nil {
		log.Fatalln(err)
	}
	//We Read the response body on the line below.
	body, err := ioutil.ReadAll(resp.Body)
	if err != nil {
		log.Fatalln(err)
	}
	//Convert the body to type string
	sb := string(body)
	log.Printf(sb)
}
