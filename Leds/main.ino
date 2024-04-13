#include "Esp32.h"
#include <Arduino.h>
#include "WifiController.h"
#include "constants.h"
#include "MqttClientController.h"
Esp32 esp;
WifiController wifiController(WIFI_SSID, WIFI_PASS);
MqttClientController mqttController(MQTT_BROKER_HOST, MQTT_BROKER_PORT);

void setup()
{
  Serial.begin(TRANSMISSION_SPEED);
  wifiController.connectToWifi();
  esp.initializeLeds();
  mqttController.setServerForMqtt(wifiController);
  mqttController.connectWithClientId(CLIENT_ID);
  mqttController.subscribeToTheTopics();
}

void loop()
{
  mqttController.startListening();
}