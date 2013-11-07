#include <Arduino.h>
#include "MyModule/MyModule.h"

#define NB_ACTIONS 1

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
  
}

re::Buffer MyModule::action(int id, re::Buffer *params_buf) // pas d'action
{
  re::Buffer ret = {0};

  re::Uint8 *p = (re::Uint8 *) params_buf->datas;

  if(id == 0) {
    _led->set(p[0]); // soit 1 soit 0
  }

  return ret;
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

