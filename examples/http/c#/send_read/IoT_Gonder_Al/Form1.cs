﻿using Newtonsoft.Json;
using Newtonsoft.Json.Linq;
using RestSharp.Portable;
using RestSharp.Portable.HttpClient;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Net.Http;
using System.Net.Http.Headers;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace IoT_Gonder_Al
{
    public partial class Form1 : Form
    {

        public Form1()
        {
            InitializeComponent();
        }

        private async void button1_Click(object sender, EventArgs e)
        {

            if (textBox1.Text != "" | textBox2.Text != "" | textBox3.Text != "")
            {

                String url = "http://iothook.com/api/update/";

                HttpClient client = new HttpClient();
                var values = new Dictionary<string, string>
            {
               { "api_key", "9e722c4fc6c834b15ba01e86" }, // #100 - Demo Data HTTP https://iothook.com/en/device/data/100/
               { "field_1", textBox1.Text },
               { "field_2", textBox2.Text },
               { "field_3", textBox3.Text }
            };
                var content = new FormUrlEncodedContent(values);
                var response = await client.PostAsync(
                       url, content);
                var result = await response.Content.ReadAsStringAsync();
                MessageBox.Show(result);
            }

        }

        private async void button2_Click(object sender, EventArgs e)
        {

            // #100 - Demo Data HTTP https://iothook.com/en/device/data/100/
            String url = "http://iothook.com/api/device/?api_key=b5d91b83c85276cddc84eb67&results=2";

            HttpClient client = new HttpClient();
 
            var response = await client.GetAsync(url);
            var result = await response.Content.ReadAsStringAsync();
            Console.WriteLine(result);

            dynamic vv = JsonConvert.DeserializeObject(result);

            textBox6.Text = vv[0]["field_1"];
            textBox5.Text = vv[0]["field_2"];
            textBox4.Text = vv[0]["field_3"];

        }
    }
}

