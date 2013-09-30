#ifndef MY_MODULE_H
#define MY_MODULE_H

#include <RobotEngine/Module/Module.h>
#include <RobotEngine/Utils/ArduinoToLinux/Module.h>
#include <RobotEngine/Utils/ArduinoComponents/LED.h>
/*
  Le module est en local, il faut utiliser la définition des components 
  de RobotEngine/Utils/ArduinoToLinux
*/

class MyModule : public reu::atl::Module {

  public:
    MyModule();
    ~MyModule();

    void loop();

    re::VariableData action(int id, re::VariableData **params); // pas d'action

    void setLed(re::Sint8 ledId, re::Sint8 on);

  private:

    reu::components::LED *_led;
};

#endif
