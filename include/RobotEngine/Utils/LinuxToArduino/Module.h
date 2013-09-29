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

      void action(int id, re::VariableData **params);

      // protocole serie
      bool get_infos();
    
    private:
      LTACommunicationDriver *_driver;
  };

  }
}

#endif

