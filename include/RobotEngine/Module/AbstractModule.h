#ifndef NATIV_GAMES_STUDIOS_MODULE_ABSTRACTMODULE_H
#define NATIV_GAMES_STUDIOS_MODULE_ABSTRACTMODULE_H

#include <RobotEngine/Module/AbstractComponent.h>

namespace rem {

  class AbstractModule {
    public:

      AbstractModule(); // initialization
      virtual ~AbstractModule();

      virtual re::Buffer action(int id, re::Buffer *params_buf) = 0; // action ID (0, 1, 2, 3)
      const char *get_name();
      
    protected:
      char *_name;
  };
}

#endif

