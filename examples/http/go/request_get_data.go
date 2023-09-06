// Go HTTP GET

package main

import (
    "fmt"
    "net/http"
    "io/ioutil"
)

func main() {

    url := "https://iothook.com/api/device/?api_key=9e722c4fc6c834b15ba01e86&results=1"

    req, _ := http.NewRequest("GET", url, nil)

    req.Header.Add("User-Agent", "PostmanRuntime/7.15.2")
    req.Header.Add("Accept", "*/*")
    req.Header.Add("Cache-Control", "no-cache")
    req.Header.Add("Postman-Token", "ce2f06c2-817e-414a-8c7a-2c2fc59ad043,8a0938fc-5c87-459a-9b9f-fa6aebe561f2")
    req.Header.Add("Host", "iothook.com")
    req.Header.Add("Accept-Encoding", "gzip, deflate")
    req.Header.Add("Connection", "keep-alive")
    req.Header.Add("cache-control", "no-cache")

    res, _ := http.DefaultClient.Do(req)

    defer res.Body.Close()
    body, _ := ioutil.ReadAll(res.Body)

    fmt.Println(res)
    fmt.Println(string(body))

}
