#ifndef UTILS_ATL_MODULE_H
#define UTILS_ATL_MODULE_H

#include <RobotEngine/Module/AbstractModule.h>
#include <RobotEngine/Utils/ArduinoToLinux/CommunicationDriver.h>

namespace reu {
  namespace atl {

  class Module : public rem::AbstractModule {
    public:

      Module();
      ~Module();

      virtual void loop() = 0;
      virtual re::Buffer action(int id, re::Buffer *params_buf) = 0;

      bool read_connection();
      // protocole serie
      void send_infos();
    
    private:

      void send_action_info(re::Uint8 actionId);

      CommunicationDriver _driver;
  };

  }
}

#endif

