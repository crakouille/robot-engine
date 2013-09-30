#ifndef UTILS_LTA_MODULE_H
#define UTILS_LTA_MODULE_H

#include <RobotEngine/Module/AbstractModule.h>
#include <RobotEngine/Utils/LinuxToArduino/LTACommunicationDriver.h>

namespace reu {
  namespace lta {

  class Module : public rem::AbstractModule {
    public:

      Module(LTACommunicationDriver *driver);
      ~Module();

      re::VariableData action(int id, re::VariableData **params);

      // protocole serie
      bool get_infos();
    
    private:

      rem::Action *get_infos_get_action();

      LTACommunicationDriver *_driver;
  };

  }
}

#endif

