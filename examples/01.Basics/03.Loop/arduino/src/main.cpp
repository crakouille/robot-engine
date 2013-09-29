#include <Arduino.h>
#include <RobotEngine/Utils/ArduinoComponents/LED.h>

reu::components::LED *leds[3];

void setup()
{
  leds[0] = new reu::components::LED(13);
  leds[1] = new reu::components::LED(2);
  leds[2] = new reu::components::LED(3);

}

void loop()
{
  leds[0]->set(1);
  leds[1]->set(0);
  leds[2]->set(0);
  delay(200.);

  leds[0]->set(0);
  leds[1]->set(1);
  leds[2]->set(0);
  delay(200.);

  leds[0]->set(0);
  leds[1]->set(0);
  leds[2]->set(1);
  delay(200.);

}

