#include"MqttClientController.h"


MqttClientController::MqttClientController(char * mqttBrokerHost, int mqttBrokerPort ):mqttClient() {
  this->mqttBrokerHost=mqttBrokerHost;
  this->mqttBrokerPort=mqttBrokerPort;

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
void MqttClientController::subscribeToATopic(String subscribeTopic){
  Serial.println("Subscribing to " + String(subscribeTopic));
  while( !mqttClient.subscribe(subscribeTopic.c_str()))
      standBy();
  Serial.println(" Subscribed!");
}
void MqttClientController::subscribeToTheTopics(){
  for(int i=0;i<SUBSCRIPTIONS_MQTT;i++){
      String topic=SUBSCRIBE_TOPIC+String(i);
      subscribeToATopic(topic);
      mqttClient.setCallback(MqttClientController::callback);
  }
}
void MqttClientController::callback(const char * topic, byte * payload, unsigned int length) {
  String message((char *) payload, length);
  int idLed = Led::getIdLedFromMessage(topic);
  Serial.println(idLed);
  Serial.println(message);
  Esp32::getLeds()[idLed].changeState(message);
}

void MqttClientController::startListening(){
  mqttClient.loop();
}

MqttClientController::~MqttClientController(){
}