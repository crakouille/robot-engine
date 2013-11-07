#include <RobotEngine/Utils/ArduinoComponents/LED.h>
#include <Arduino.h>

using namespace reu;
using namespace reu::components;

LED::LED(re::Sint16 pin_id, bool analog)
{
  _pin_id = pin_id;
  _is_analog = analog;
  
  pinMode(pin_id, OUTPUT);  
}

LED::~LED()
{

}

void LED::set(bool on)
{
  digitalWrite(_pin_id, (!on) ? LOW : HIGH);
}

void LED::set_analog(re::Uint8 value)
{
  analogWrite(_pin_id, value);
}

