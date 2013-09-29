#include <Arduino.h>
#include <RobotEngine/Component/Component.h>
#include "MyModule/MyModule.h"


MyModule::MyModule()
{
  // définition du module
  _name = strdup("MyBlinkModule");
  _actions = 0;

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

void MyModule::action(int id, re::VariableData **params)
{
  
}

