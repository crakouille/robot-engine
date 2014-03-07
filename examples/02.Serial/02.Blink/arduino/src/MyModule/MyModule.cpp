#include <Arduino.h>
#include "MyModule/MyModule.h"


MyModule::MyModule()
{
  // définition du module
  _name = strdup("MyBlinkModule");

  _led = new reu::components::LED(13);
}

MyModule::~MyModule()
{
  delete _led;
}

void MyModule::loop()
{
  _led->set(1);
  delay(200.);

  _led->set(0);
  delay(200.);
}

re::Buffer MyModule::action(int id, re::Buffer *params_buf)
{
  re::Buffer buf = {0};

  return buf;
}

