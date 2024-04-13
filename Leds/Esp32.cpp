#include "Esp32.h"
Led Esp32::leds[LEDS_COUNT];

Esp32::Esp32()
{
}

void Esp32::initializeLeds()
{
  for (int i = 0; i < LEDS_COUNT; i++)
    leds[i] = Led(ledPins[i]);
}

Led *Esp32::getLeds()
{
  return leds;
}

Esp32::~Esp32()
{
}