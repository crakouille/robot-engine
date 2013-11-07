#ifndef NATIV_GAMES_STUDIOS_ROBOT_ENGINE_COMMON_ABSTRACTCOMMUNICATIONDRIVER_H
#define NATIV_GAMES_STUDIOS_ROBOT_ENGINE_COMMON_ABSTRACTCOMMUNICATIONDRIVER_H

#include <RobotEngine/Common/Variable.h>

namespace re {

  class AbstractCommunicationDriver {
    public:
  
      virtual ~AbstractCommunicationDriver();

      bool read(re::Buffer *buf); // send false if there is a checksum error
      void send(re::Buffer *buf);

    protected:

      virtual Sint16 read2(void *p, Uint16 maxsize) = 0; // read exactly maxsize
      virtual bool send2(const void *p, Uint16 size) = 0;
  };
}

#endif

