#include <oacl/oacl.h>
#include <RobotEngine/Component/Component.h>
#include "MyComponent/MyComponent.h"
#include "MyModule/MyModule.h"

MyComponent *t1;
MyComponent *t2;
MyComponent *t3;

int current_led = 0;

#define NB_ACTIONS 1

MyModule::MyModule()
{
  // définition du nom
  _name = strdup("my module");

  // Déclaration des actions
  _actions = (re::Action **) malloc(sizeof(re::Action *) * (NB_ACTIONS + 1));
  _actions[NB_ACTIONS] = 0;

  _actions[0] = (re::Action *) malloc(sizeof(re::Action));

  _actions[0]->name = strdup("test");
  _actions[0]->ret = 0;
  _actions[0]->params = 0;

  // code métier pour l'initialisation

  t1 = new MyComponent(13);
  t2 = new MyComponent(2);
  t3 = new MyComponent(3);
}

MyModule::~MyModule()
{
  
}

void MyModule::loop()
{
  this->setLed(0, 0 == current_led);
  this->setLed(1, 1 == current_led);
  this->setLed(2, 2 == current_led);

  current_led ++;
  current_led = current_led % 3;

  delay(500.);
}

void MyModule::action(int id, re::VariableData **params)
{
  
}

// Actions

re::VariableData v;
re::VariableData *pv;

void MyModule::setLed(re::Sint8 ledId, re::Sint8 on)
{  
  pv = &v;
  v.s16 = (re::Sint16) on;
  
  switch(ledId) {
    case 0:
      t1->action(&pv);
      break;
    case 1:
      t2->action(&pv);
      break;
    case 2:
      t3->action(&pv);
      break;
    default:
      break;
  };
}

