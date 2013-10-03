#include <Arduino.h>
#include <RobotEngine/Utils/ArduinoComponents/LED.h>

reu::components::LED *led;

void setup()
{
  led = new reu::components::LED(13);
}

void loop()
{
  led->set(1);
  delay(100);
}

