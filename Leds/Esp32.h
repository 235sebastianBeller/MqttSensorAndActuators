#ifndef ESP32_H
#define ESP32_H
#include "constants.h"
#include "Led.h"
class Esp32
{
private:
  static Led leds[LEDS_COUNT];

public:
  Esp32();
  static Led *getLeds();
  void initializeLeds();
  ~Esp32();
};
#endif