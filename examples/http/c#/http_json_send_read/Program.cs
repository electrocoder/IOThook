using System;

namespace HelloWorld
{
    class Program
    {
        public static async Task Main(string[] args)
        {
            // # 650 - iot_examples https://iothook.com/en/device/data/650/

            HttpClient client = new HttpClient();

            // send
            String send_url = "http://iothook.com/api/update/";
            var values = new Dictionary<string, string>
            {
                { "api_key", "21579c1e874fda7276d94f3c" }, 
                { "field_1", "1" },
                { "field_2", "2" },
                { "field_3", "3" }
            };
            var content = new FormUrlEncodedContent(values);
            var response_send = await client.PostAsync(send_url, content);
            var result_send = await response_send.Content.ReadAsStringAsync();
            Console.WriteLine(result_send);

            // read
            String read_url = "http://iothook.com/api/device/?api_key=f1403e03949c7f9060a4bdd2&results=1";
            var response_read = await client.GetAsync(read_url);
            var result_read = await response_read.Content.ReadAsStringAsync();
            Console.WriteLine(result_read);
        }
    }
}
