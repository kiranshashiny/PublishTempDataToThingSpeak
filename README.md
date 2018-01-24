# PublishTempDataToThingSpeak
Publishing Temperature (DHT11 sensor) from NodeMCU to Cloud ThingSpeak, and viewing charts

This blog is about publishing the room temperature from the DHT11 sensor connected to NodeMCU, and publishing using HTTP to ThingSpeak Cloud broker.
Thingspeak provides ability to chart, render them with different gauges and easyto configure and hook up.

The Bill of Materials needed :

	-NodeMCU development board
	-DHT11 sensor
	-WiFi router at home which can connect to the NodeMCU
	-A free login account to thingspeak ( thingspeak.com).

Steps :

First, login to thingspeak and create a channel (for free), and note down the API key and the channel ID.

Next, connect the DHT11 signal pin to pin D0 of the NodeMCU.
The Vcc of DHT11 to 3.3v of NodeMCU
The GND of DHT11 to GND of NodeMCU

Copy the code in this repo, to Arduino IDE as a sketch.

Update the respective channel ID and API key in the sketch code.

Upload the code to Arduino IDE.

Set the default publish to be about 15 seconds or more.

In the channel, create the visualization and wait for the data to show up.


Troubleshooting :

Check the API key and the Channel Number in the Arduino Sketch.


Below is my room temperature which is a standard 26 def Centigrades.

![screen shot 2018-01-24 at 5 05 51 pm](https://user-images.githubusercontent.com/14288989/35330269-e47ac5e0-0128-11e8-9e36-7e2c16f23c88.png)
