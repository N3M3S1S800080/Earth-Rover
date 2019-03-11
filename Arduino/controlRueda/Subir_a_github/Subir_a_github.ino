/*
 * Sketch: ESP8266_LED_Control_02
 * Control an LED from a web browser
 * Intended to be run on an ESP8266
 * 
 * connect to the ESP8266 AP then
 * use web broswer to go to 192.168.4.1
 * 
 */
 
 
#include <ESP8266WiFi.h>

const char* ssid = "NemiRedmi";
const char* password = "123456789";
WiFiClient client;

WiFiServer server(80);


void writeButton(int val){      
    String s = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<!DOCTYPE HTML>\r\n<html>\r\nGPIO is now ";
    s += (val)?"low":"high";
    s += "</html>\n";
    
    client.print(s);                    // Enviar el resultado de val al cliente
    delay(1);
    Serial.println("Client disonnected");
  }

  
void setup()
   {  Serial.begin(115200);
      delay(1500);

      pinMode(2, OUTPUT);      // GPIO2
      digitalWrite(2, LOW);

      Serial.print("Connecting to ");
      Serial.println(ssid);
      WiFi.begin(ssid, password);

      while (WiFi.status() != WL_CONNECTED)
         {   delay(500);
             Serial.print(".");
         }
      Serial.println("WiFi connected");

      server.begin();                                // Iniciamos el servidor
      Serial.println("Server started");
      Serial.println(WiFi.localIP());      // Imprimimos la IP
   }
 
 
void loop() 
{
 
   client = server.available();
if (!client)
     return;

Serial.println("new client");
while(!client.available())
      delay(1);
      
String req = client.readStringUntil('\r');
Serial.println(req);
client.flush();

int val;
if ( req.indexOf("/gpio/0") != -1){
     val = 0;
     writeButton(val);
}
else if (req.indexOf("/gpio/1") != -1){
     val = 1;
     writeButton(val);
}

    client.print("<html>  <head>    <title>LED Control</title>  </head>  <body>    <div id='main'>  <h2>LED Control</h2>    <input class='button' type='submit' value='LED ON' onclick = \"window.location = '/gpio/0';\" />  <br>    <input class='button' type='submit' value='LED OFF' onclick = \"window.location = '/gpio/1';\" /> </div>  </body></html>");

digitalWrite(2, val);

} // void loop()
