#include <WiFi.h>
#include "DHT.h"
#include <Wire.h>
#define DHTPIN 13     
#define DHTTYPE DHT11  

DHT dht(DHTPIN, DHTTYPE);
const char* ssid     = "Rendy"; // Your ssid
const char* password = "12345678"; // Your Password
char status;
WiFiServer server(80);

void setup() {
  Serial.begin(115200);
  delay(100);
  dht.begin();
   
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi is connected");
  server.begin();
  Serial.println("Server started");
  Serial.println(WiFi.localIP());
}

void loop() { 
  int ldrValue = analogRead(14); // read analog input pin 0
  Serial.println(ldrValue); // prints the value read
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);
  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print(" *C ");
  Serial.print(f);
  Serial.print(" *F\t");
  WiFiClient client = server.available();

  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println("Connection: close");  // the connection will be closed after completion of the response
  client.println("Refresh: 10");  // update the page after 10 sec
  client.println();
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
  client.println("<head>");
  client.println("<style>html { font-family: Fantasy; display: block; margin: 0px auto; text-align: center;color: #333333; background-color: #ccffb3;}");
  client.println("body{margin-top: 50px;}");
  client.println("h1 {margin: 50px auto 30px; font-size: 50px; text-align: center;}");
  client.println(".side_adjust{display: inline-block;vertical-align: middle;position: relative;}");
  client.println(".text1{font-weight: 180; padding-left: 15px; font-size: 50px; width: 170px; text-align: left; color: #3498db;}");
  client.println(".data1{font-weight: 180; padding-left: 80px; font-size: 50px;color: #3498db;}");
  client.println(".text2{font-weight: 180; font-size: 50px; width: 170px; text-align: left; color: #3498db;}");
  client.println(".data2{font-weight: 180; padding-left: 150px; font-size: 50px;color: #3498db;}");
  client.println(".data{padding: 10px;}");
  client.println("</style>");
  client.println("</head>");
  client.println("<body>");
  client.println("<div id=\"webpage\">");   
  client.println("<h1>ESP32 Weather Station</h1>");
  client.println("<div class=\"data\">");
  client.println("<div class=\"side_adjust text1\">Humidity:</div>");
  client.println("<div class=\"side_adjust data1\">");
  client.print(h);
  client.println("<div class=\"side_adjust text1\">%</div>");
  client.println("</div>");
  client.println("<div class=\"data\">");
  client.println("<div class=\"side_adjust text2\">Temperature:</div>");
  client.println("<div class=\"side_adjust data2\">");
  client.print(t);
  client.println("<div class=\"side_adjust text2\">*C</div>");
  client.print(f);
  client.println("<div class=\"side_adjust text1\">*F</div>");
  client.println("</div>");
  client.println("<div class=\"data\">");
  client.println("<div class=\"side_adjust text2\">Luminiousity:</div>");
  client.println("<div class=\"side_adjust data2\">");
  client.print(ldrValue);
  client.println("</div>");
  client.println("</div>");
  client.println("</body>");
  client.println("</html>");
}
