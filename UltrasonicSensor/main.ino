#include "UltrasonicSensor.h"
#include "WifiController.h"
#include "MqttClientController.h"
#include "constants.h"

WifiController wifiController(WIFI_SSID, WIFI_PASS);
MqttClientController mqttController(MQTT_BROKER_HOST, MQTT_BROKER_PORT);
UltrasonicSensor ultrasonicSensor(TRIGGER_PIN, ECHO_PIN);

void setup()
{
  Serial.begin(TRANSMISSION_SPEED);
  wifiController.connectToWifi();
  mqttController.setServerForMqtt(wifiController);
  mqttController.connectWithClientId(CLIENT_ID);
}

int cm = 0;
void loop()
{
  cm = ultrasonicSensor.getTheShortestDistance(SAMPLE_SIZE);
  mqttController.publishOnTopic(String(cm), PUBLISH_TOPIC);
}
