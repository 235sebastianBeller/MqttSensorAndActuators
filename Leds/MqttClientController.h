#ifndef MQTTCLIENTCONTROLLER_H
#define MQTTCLIENTCONTROLLER_H
#include <WiFi.h>
#include <PubSubClient.h>
#include"WifiController.h"
#include"Esp32.h"
#include"Led.h"
#include"constants.h"
class MqttClientController {
  private:
      char * mqttBrokerHost ;
      int mqttBrokerPort;
      PubSubClient mqttClient;    

  public:
  MqttClientController(char * mqttBrokerHost, int mqttBrokerPort);
  void setServerForMqtt(WifiController& wifiController);
  void connectWithClientId(String clientId);
  void subscribeToATopic(String subscribeTopic);
  void subscribeToTheTopics();
  void startListening();
  void standBy();
  static void callback(const char * topic, byte * payload, unsigned int length);
  ~MqttClientController();
};
#endif