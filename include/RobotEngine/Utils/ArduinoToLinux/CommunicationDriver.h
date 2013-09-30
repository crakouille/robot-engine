#ifndef NATIV_GAMES_STUDIOS_ROBOT_ENGINE_UTILS_ARDUINOTOLINUX_COMMUNICATIONDRIVER_H
#define NATIV_GAMES_STUDIOS_ROBOT_ENGINE_UTILS_ARDUINOTOLINUX_COMMUNICATIONDRIVER_H

#include <RobotEngine/Common/AbstractCommunicationDriver.h>

namespace reu {
  namespace atl {

    class CommunicationDriver: public re::AbstractCommunicationDriver {
      public:
    
      /*
        speed:
        - 0
        - 50
        - 75
        - 110
        - 134
        - 150
        - 200
        - 300
        - 600
        - 1200
        - 1800
        - 2400
        - 4800
        - 9600
        - 19200
        - 38400
        - 57600
        - 115200
        - 230400 
      */

        CommunicationDriver(int speed);
        virtual ~CommunicationDriver();

        virtual re::Sint16 read(void *p, re::Uint16 maxsize);
        virtual bool send(const void *p, re::Uint16 size);

      private:
    };
  }
}

#endif

