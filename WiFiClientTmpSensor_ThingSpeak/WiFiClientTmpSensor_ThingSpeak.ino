/*
 *  This sketch sends temperature data to thingspeak.com 
 *
 *  You need to get API Key and channel Number from ThingSpeak and paste them
 *  below.
 *  DHT Libraries have to be included for this demo to work.
 *  This was tested on NodeMCU on MacOS - Sierra.
 *  To debug :
 *     Open the serial monitor 115200 baud and watch the temperature printed.
 *
 */

#include <ESP8266WiFi.h>
#include "ThingSpeak.h"
#include<dht.h>
dht DHT;

#define DHT11_PIN 16

const char* ssid     = "NETGEAR84";  // Replace appropriately
const char* password = "welcome";    // Replace appropriately

const char* host = "api.thingspeak.com";
unsigned long myChannelNumber = 409671;
const char * myWriteAPIKey = "Your API Key here";
WiFiClient client;


void setup() {
  Serial.begin(115200);
  delay(10);

  // We start by connecting to a WiFi network

  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  /* Explicitly set the ESP8266 to be a WiFi-client, otherwise, it by default,
     would try to act as both a client and an access-point and could cause
     network-issues with your other WiFi-devices on your WiFi-network. */
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  ThingSpeak.begin(client);

}

int value = 0;

void loop() {
  delay(5000);
  ++value;

  Serial.print("connecting to ");
  Serial.println(host);
  
  // Use WiFiClient class to create TCP connections
  const int httpPort = 80;
  if (!client.connect(host, httpPort)) {
    Serial.println("connection failed");
    return;
  }
  
  Serial.print  ("Sending current temperature ");
  
  int chk = DHT.read11(DHT11_PIN);

  /*Serial.print (" Humidity " );

  Serial.print (DHT.humidity, 1);
  */
  Serial.print(" Temperature ");

  Serial.println(DHT.temperature, 1);
 
  // This is the field 1 of the ThingSpeak channel. 

  ThingSpeak.setField(1, (int) DHT.temperature);

  // Write the fields that you've set all at once.
  ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);  
  delay (15000);   

}
