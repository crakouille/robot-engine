#ifndef MY_MODULE_H
#define MY_MODULE_H

#include <RobotEngine/Module/Module.h>
#include <RobotEngine/Utils/ArduinoToLinux/Module.h>
/*
  Le module est en local, il faut utiliser la définition des components 
  de RobotEngine/Component/
*/

class MyModule : public reu::atl::Module {

  public:
    MyModule();
    ~MyModule();

    void loop();

    void action(int id, re::VariableData **params);

    // Actions

    void setLed(re::Sint8 ledId, re::Sint8 on);

  private:

    
};

#endif
