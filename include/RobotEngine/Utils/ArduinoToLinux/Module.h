#ifndef UTILS_ATL_MODULE_H
#define UTILS_ATL_MODULE_H

#include <RobotEngine/Module/AbstractModule.h>

namespace reu {
  namespace atl {

  class Module : public rem::AbstractModule {
    public:

      Module();
      ~Module();

      virtual void loop() = 0;
      virtual void action(int id, re::VariableData **params) = 0;

      bool read_connection();
      // protocole serie
      void send_infos();
    
    private:
  };

  }
}

#endif

