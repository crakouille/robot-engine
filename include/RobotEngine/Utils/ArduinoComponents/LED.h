#ifndef UTILS_ATL_COMPONENTS_LED_H
#define UTILS_ATL_COMPONENTS_LED_H

#include <RobotEngine/Module/AbstractComponent.h>

namespace reu {
  namespace components {

  class LED : public rem::AbstractComponent {
    public:

      LED(re::Sint16 pin_id, bool analog = 0);
      ~LED();
      
      void set(bool on);
      void set_analog(re::Uint8 value);
    
    protected:
      re::Sint16 _pin_id;
      bool _is_analog;
  };

  }
}

#endif

