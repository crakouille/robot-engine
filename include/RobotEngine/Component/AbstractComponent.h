#ifndef NATIV_GAMES_STUDIOS_COMPONENT_ABSTRACTCOMPONENT_H
#define NATIV_GAMES_STUDIOS_COMPONENT_ABSTRACTCOMPONENT_H

/*
  Component désigne un composant du robot.
  Chaque composant dispose de:
  - variables
  - signaux
  - actions
  - fonctions de base

  Lorsqu'un composant est branché au robot,
  il envoie son nom de composant sous forme de chaine ("roue" par exemple).
  L'élément est instancié et la fonction init() est appelée,
  pour configurer le composant correctement.

  Chaque action doit pouvoir être arrêtée en cours.
*/

#include <RobotEngine/Common/Variable.h>
#include <RobotEngine/Common/AbstractComponent.h>

namespace rec {

  class AbstractComponent : public re::AbstractComponent {
    public:
  
      AbstractComponent();
      virtual ~AbstractComponent();
  
      //virtual void start() = 0; // commence la lecture des informations

      virtual re::VariableData *call(re::VariableData **vars) = 0;
  };

}
  
#endif

