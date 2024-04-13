# Ultrasonic Sensor and Leds with MQTT Broker Project
## Project Description:

This project consists of the implementation of a system that uses an ultrasonic sensor to measure the distance to an object, such distance are published in a MQTT broker so that they can be visualized or processed by other applications. In the same way, a set of LEDs are turned on according to the entries published in different subscription topics of a MQTT broker, the LEDs can be activated in different applications connected to the respective topics (sessions). 

## Considerations:
 1. Install the arduino IDE 
 2. In the arduino IDE install the library PubSubClient by Nick O’Leary. you can review the library documentation here https://pubsubclient.knolleary.net
 
## Changes:

1. The constants files in Leds and Ultrasonic Sensor folder :
    - put YOUR_WIFI_SSID 
    - put YOUR_WIFI_PASS 
    - put YOUR_MQTT_BROKER_HOST 
    - put YOUR_CLIENT_ID 
    - put YOUR_PUBLISH_TOPIC 