#include <Arduino.h>
#include "MyModule/MyModule.h"

int current_led = 0;

#define NB_ACTIONS 1

MyModule::MyModule()
{
  // définition du module
  _name = strdup("MyModule");
}

MyModule::~MyModule()
{
  
}

void MyModule::loop()
{
}

re::Buffer MyModule::action(int id, re::Buffer *params_buf)
{
  re::Buffer buf = {0};

  

  return buf;
}

