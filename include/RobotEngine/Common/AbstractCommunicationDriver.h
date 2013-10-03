#ifndef NATIV_GAMES_STUDIOS_ROBOT_ENGINE_COMMON_ABSTRACTCOMMUNICATIONDRIVER_H
#define NATIV_GAMES_STUDIOS_ROBOT_ENGINE_COMMON_ABSTRACTCOMMUNICATIONDRIVER_H

#include <RobotEngine/Common/Variable.h>

namespace re {

  class AbstractCommunicationDriver {
    public:
  
      virtual ~AbstractCommunicationDriver();

      virtual Sint16 read(void *p, Uint16 maxsize) = 0; // read exactly maxsize
      virtual bool send(const void *p, Uint16 size) = 0;

      VariableData read_data(re::VariableType type);
      void send_data(VariableData *data, re::VariableType type);
  };
}

#endif

