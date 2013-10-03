#include <Arduino.h>
#include <RobotEngine/Component/Component.h>
#include "MyModule/MyModule.h"

int current_led = 0;

#define NB_ACTIONS 1

MyModule::MyModule()
{
  // définition du module
  _name = strdup("MyModule");
  _actions = 0;
}

MyModule::~MyModule()
{
  
}

void MyModule::loop()
{
}

re::VariableData MyModule::action(int id, re::VariableData **params)
{
  re::VariableData data;

  return data;
}

