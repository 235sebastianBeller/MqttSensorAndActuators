#ifndef WIFICONTROLLER_H
#define WIFICONTROLLER_H
#include <WiFi.h>
#include "constants.h"
class WifiController
{
private:
  char *WifiSsid;
  char *WifiPassword;
  WiFiClient wifiClient;

public:
  WifiController(char *WifiSsid, char *WifiPassword);
  void connectToWifi();
  ~WifiController();
  WiFiClient &getWiFiClient();
};
#endif