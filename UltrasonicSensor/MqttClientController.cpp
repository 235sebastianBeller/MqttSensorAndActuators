#include"MqttClientController.h"


MqttClientController::MqttClientController(char * mqttBrokerHost, int mqttBrokerPort ):mqttClient() {
  this->mqttBrokerHost=mqttBrokerHost;
  this->mqttBrokerPort=mqttBrokerPort;
  previousPublishMillis = 0;

}

void MqttClientController::setServerForMqtt(WifiController& wifiController){
  mqttClient.setClient(wifiController.getWiFiClient());
  mqttClient.setServer(mqttBrokerHost, mqttBrokerPort);
}
void MqttClientController::standBy(){
      delay(STAND_BY_DELAY);
      Serial.print("*");
}
void MqttClientController::connectWithClientId(String clientId){
  Serial.println("Connecting to " + String(clientId));
  mqttClient.disconnect();
  mqttClient.connect(clientId.c_str());
  while (mqttClient.state()!=MQTT_CONNECTED) 
      standBy();
  Serial.println(" Connected!");
}
bool MqttClientController::isTime(unsigned long previousMillis, unsigned long nowMillis){
  return nowMillis- previousPublishMillis >= LIMIT_DELAY;
}
void MqttClientController::publishOnTopic(String data,String publishTopic){
    if (!mqttClient.connected()) {
        Serial.println("MQTT broker not connected!");
        delay(LIMIT_DELAY);
      return;
    }
    unsigned long now = millis();
    if (isTime(previousPublishMillis,now)) {
      previousPublishMillis = now;
      mqttClient.publish(publishTopic.c_str(), data.c_str());
    }
  }

MqttClientController::~MqttClientController(){
}