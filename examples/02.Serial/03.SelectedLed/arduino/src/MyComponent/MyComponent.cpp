#include "MyComponent/MyComponent.h"
#include <oacl/oacl.h>

MyComponent::MyComponent(int pin_id)
{
  _pin_id = pin_id;

  pinMode(pin_id, OUTPUT);
}

MyComponent::~MyComponent()
{
  
}
/*
int brightness = 255;    // how bright the LED is
int fadeAmount = -5;    // how many points to fade the LED by*/

re::VariableData *MyComponent::action(re::VariableData **vars)
{
  //analogWrite(_pin_id, (*vars)[0].s16); // int <=> Sint16 en arduino
  digitalWrite(_pin_id, (*vars)[0].s16);

  return NULL;
}

void MyComponent::on_read(void *p, re::Sint16 size)
{
  digitalWrite(_pin_id, HIGH);
}

