#include "WifiController.h"

WifiController::WifiController(char *WifiSsid, char *WifiPassword) : wifiClient()
{
  this->WifiSsid = WifiSsid;
  this->WifiPassword = WifiPassword;
}

void WifiController::connectToWifi()
{
  WiFi.begin(WifiSsid, WifiPassword);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(STAND_BY_DELAY);
    Serial.print(".");
  }
  Serial.println(" Connected to" + String(WifiSsid));
}

WiFiClient &WifiController::getWiFiClient()
{
  return wifiClient;
}

WifiController::~WifiController()
{
}