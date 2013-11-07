#ifndef NATIV_GAMES_STUDIOS_MODULE_ABSTRACTCOMPONENT_H
#define NATIV_GAMES_STUDIOS_MODULE_ABSTRACTCOMPONENT_H

/*
  AbstractComponent désigne tout composant de base:
  - Effecteur
  - Capteur
*/

#include <RobotEngine/Common/Variable.h>

namespace rem {

  class AbstractComponent {
    public:
  
      AbstractComponent();
      virtual ~AbstractComponent();
  };

}
  
#endif

