#ifndef NATIV_GAMES_STUDIOS_ROBOT_ENGINE_MODULE_DISTANTCOMPONENT_H
#define NATIV_GAMES_STUDIOS_ROBOT_ENGINE_MODULE_DISTANTCOMPONENT_H

/*
  A utiliser si le composant est sur une autre carte.
  Si le composant est
*/

#include <RobotEngine/Common/AbstractComponent.h>
#include <RobotEngine/Common/AbstractCommunicationDriver.h>

namespace rem {

  class DistantComponent : public re::AbstractComponent {
    public:
  
      DistantComponent(re::AbstractCommunicationDriver *driver);
      virtual ~DistantComponent();

      re::AbstractCommunicationDriver *get_driver();

      // protocole serie
      virtual void get_infos() = 0;

    private:

      re::AbstractCommunicationDriver *_driver;
  };
}

#endif

