# Publish Room Temperature from sensor (DHT11) connected to NodeMCU microcontroller to cloud broker ThingSpeak.com


This blog is about publishing the room temperature from the DHT11 sensor connected to NodeMCU, and publishing using HTTP to ThingSpeak Cloud broker.
Thingspeak provides ability to chart, render them with different gauges and easyto configure and hook up.

The Bill of Materials needed :

	-NodeMCU development board
	-DHT11 sensor
	-WiFi router at home which can connect to the NodeMCU
	-A free login account to thingspeak ( thingspeak.com).

![screen shot 2018-01-24 at 5 42 42 pm](https://user-images.githubusercontent.com/14288989/35331640-0e68e530-012e-11e8-92ce-a7c50671ebe2.png)

![screen shot 2018-01-24 at 5 42 21 pm](https://user-images.githubusercontent.com/14288989/35331642-0ea2405a-012e-11e8-96e1-fe46435df380.png)

Steps :

First, login to thingspeak and create a channel (for free), and note down the API key and the channel ID.

Next, connect the DHT11 signal pin to pin D0 of the NodeMCU.
The Vcc of DHT11 to 3.3v of NodeMCU
The GND of DHT11 to GND of NodeMCU

Copy the code in this repo, to Arduino IDE as a sketch.

Update the respective channel ID and API key in the sketch code.

	unsigned long myChannelNumber = 409671;
	const char * myWriteAPIKey = "Your API Key here";

If this is the first time, then the API key can get got from Thingspeak -> API key tab

![screen shot 2018-01-24 at 5 38 03 pm](https://user-images.githubusercontent.com/14288989/35331460-722137a4-012d-11e8-81e5-2fa5b4503685.png)


Upload the code to Arduino IDE.

Set the default publish to be about 15 seconds or more.

In the channel, create the visualization and wait for the data to show up.


Troubleshooting :

Check the API key and the Channel Number in the Arduino Sketch.


Below is my room temperature which is a standard 26 deg Centigrades.

![screen shot 2018-01-24 at 5 05 51 pm](https://user-images.githubusercontent.com/14288989/35330269-e47ac5e0-0128-11e8-9e36-7e2c16f23c88.png)



