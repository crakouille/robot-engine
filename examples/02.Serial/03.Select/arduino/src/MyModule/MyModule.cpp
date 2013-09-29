#include <Arduino.h>
#include <RobotEngine/Component/Component.h>
#include "MyModule/MyModule.h"

#define NB_ACTIONS 1

MyModule::MyModule()
{
  // définition du module
  _name = strdup("MyBlinkModule");
  _actions = 0;

  _actions = (rem::Action **) malloc(sizeof(rem::Action *) * (NB_ACTIONS + 1));
  _actions[NB_ACTIONS] = 0;

  _actions[0] = (rem::Action *) malloc(sizeof(rem::Action));

  _actions[0]->name = strdup("setLed");
  _actions[0]->ret = re::UINT8;

  _actions[0]->params = (re::VariableType *) malloc(sizeof(re::VariableType) * 2);
  _actions[0]->params[0] = re::UINT8;
  _actions[0]->params[1] = re::NONE;

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

// Actions

void MyModule::setLed(re::Sint8 ledId, re::Sint8 on)
{  
  //pv = &v;
  //v.s16 = (re::Sint16) on;
  
  switch(ledId) {
    case 0:
      //t1->set();
      break;
    case 1:
      //t2->action(&pv);
      break;
    case 2:
      //t3->action(&pv);
      break;
    default:
      break;
  };
}

