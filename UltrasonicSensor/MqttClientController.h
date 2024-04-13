#ifndef MQTTCLIENTCONTROLLER_H
#define MQTTCLIENTCONTROLLER_H
#include <WiFi.h>
#include <PubSubClient.h>
#include "WifiController.h"
#include "constants.h"
class MqttClientController
{
private:
  char *mqttBrokerHost;
  int mqttBrokerPort;
  PubSubClient mqttClient;
  unsigned long previousPublishMillis;

public:
  MqttClientController(char *mqttBrokerHost, int mqttBrokerPort);
  void setServerForMqtt(WifiController &wifiController);
  void connectWithClientId(String clientId);
  void standBy();
  void publishOnTopic(String data, String publishTopic);
  bool isTime(unsigned long previousMillis, unsigned long nowMillis);
  ~MqttClientController();
};
#endif