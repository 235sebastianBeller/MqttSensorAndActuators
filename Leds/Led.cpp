#include "Led.h"
Led::Led(int ledPin)
{
  this->ledPin = ledPin;
  pinMode(ledPin, OUTPUT);
}

Led::Led()
{
}

void Led::turnOn()
{
  digitalWrite(ledPin, HIGH);
}

void Led::turnOff()
{
  digitalWrite(ledPin, LOW);
}

bool Led::isLedShouldBeOn(String message)
{
  return message == "LED_ON";
}

void Led::changeState(String message)
{
  if (isLedShouldBeOn(message))
    turnOn();
  else
    turnOff();
}

int Led::getIdLedFromMessage(String message)
{
  int id = 0, i = message.length() - 1, pot = 1;
  Serial.println(message);
  while (message[i] >= '0' && message[i] <= '9')
  {
    id += pot * (message[i--] - '0');
    pot *= 10;
  }
  return id;
}

Led::~Led()
{
}