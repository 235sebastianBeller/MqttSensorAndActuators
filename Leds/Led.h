#ifndef LED_H
#define LED_H
#include <Arduino.h>
#include <sstream>
using namespace std;
class Led
{
private:
  int ledPin;

public:
  Led();
  Led(int ledPin);
  void turnOn();
  void turnOff();
  void changeState(String message);
  bool isLedShouldBeOn(String message);
  static int getIdLedFromMessage(String message);
  ~Led();
};
#endif