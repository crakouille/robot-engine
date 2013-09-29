#ifndef MY_COMPONENT_H
#define MY_COMPONENT_H

#include <RobotEngine/Component/Component.h>

class MyComponent : public rec::AbstractEffector {

  public:
    MyComponent(int pin_id);
    ~MyComponent();

    re::VariableData *action(re::VariableData **vars);

    virtual void on_read(void *p, re::Sint16 size);

  private:

    int _pin_id;
};

#endif
