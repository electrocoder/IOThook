*******************************************
Finding location from IoT Device IP address
*******************************************

Finding the precise location of an IoT device based solely on its IP address can be challenging and often
inaccurate. IP addresses are assigned to devices by internet service providers (ISPs) and generally provide
information about the network or region to which the device is connected, rather than its physical location.

However, there are techniques that can be used to estimate the approximate location of an IP address. Here
are a few methods:

1. Geolocation Databases: Some organizations maintain databases that map IP addresses to geographic locations.
These databases are compiled using various sources such as user-reported data, ISP information, and publicly
available data. By querying these databases, it's possible to obtain an approximate location associated with
an IP address.

2. Wi-Fi Network Mapping: In some cases, the IP address of an IoT device may be associated with a Wi-Fi network.
By mapping the known locations of Wi-Fi networks, it's possible to estimate the location of a device connected
to a particular network. This method is typically more accurate in urban areas with denser Wi-Fi coverage.

3. Mobile Network Data: If the IoT device is connected to a mobile network, the IP address can provide
information about the location of the mobile network's serving gateway. However, this location may not
correspond directly to the physical location of the IoT device, as mobile networks can cover large areas.

It's important to note that these methods have limitations and may not always provide precise or reliable
results. IP addresses can be dynamically assigned, and devices may connect through proxies or virtual private
networks (VPNs), which can affect the accuracy of geolocation estimates.

For applications where accurate location information is crucial, IoT devices often incorporate additional
positioning technologies such as GPS or triangulation using cellular tower signals to determine
their precise location.

Getting Location by IoT Device IP Address with IoTHook
------------------------------------------------------

After finding the IP address of the IoT device, to get the Location information from the IP
address https://iothook.com/api/get-ip-to-location-address/ or https://iothook.com/api/get-ip-to-location/ A GET
request is sent to -address/. With the GET request, first the IoT device IP address is found, then the
location is found and the location address is sent.

When a GET request is sent to IoTHook, first the IP address is found and then the location is found. The
location example can be sampled in JSON format as follows. {"location":"Yunusemre,Manisa,TR"}

.. code-block:: c

    /*

      Location by IoT Device IP Address
      electrocoder@gmail.com
      sahin@mesebilisim.com
      mesebilisim.com
      30.05.2023

    */

    #include <SPI.h>
    #include <Ethernet.h>


    byte mac[] = {
      0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED
    };

    IPAddress ip(192, 168, 1, 177);
    IPAddress myDns(192, 168, 1, 1);

    EthernetClient client;

    char server[] = "iothook.com";

    unsigned long lastConnectionTime = 0;
    const unsigned long postingInterval = 20 * 1000;

    void setup() {

      Serial.begin(9600);
      while (!Serial) {
        ;
      }

      Serial.println("Initialize Ethernet with DHCP:");
      if (Ethernet.begin(mac) == 0) {
        Serial.println("Failed to configure Ethernet using DHCP");
        // Check for Ethernet hardware present
        if (Ethernet.hardwareStatus() == EthernetNoHardware) {
          Serial.println("Ethernet shield was not found.  Sorry, can't run without hardware. :(");
          while (true) {
            delay(1);
          }
        }
        if (Ethernet.linkStatus() == LinkOFF) {
          Serial.println("Ethernet cable is not connected.");
        }

        Ethernet.begin(mac, ip, myDns);
        Serial.print("My IP address: ");
        Serial.println(Ethernet.localIP());
      } else {
        Serial.print("  DHCP assigned IP ");
        Serial.println(Ethernet.localIP());
      }

      delay(1000);

    }


    void loop() {

      if (client.available()) {
        char c = client.read();
        Serial.write(c);
      }

      if (millis() - lastConnectionTime > postingInterval) {
        httpRequest();
      }

    }


    void httpRequest() {

      client.stop();


      if (client.connect(server, 80)) {
        Serial.println("connecting...");

        client.println("GET /api/get-ip-to-location-address/ HTTP/1.1");
        client.println("Host: www.iothook.com");
        client.println("User-Agent: arduino-ethernet");
        client.println("Connection: close");
        client.println();


        lastConnectionTime = millis();
      } else {
        Serial.println("connection failed");
      }
    }
