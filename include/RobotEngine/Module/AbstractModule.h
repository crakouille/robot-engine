#ifndef NATIV_GAMES_STUDIOS_MODULE_ABSTRACTMODULE_H
#define NATIV_GAMES_STUDIOS_MODULE_ABSTRACTMODULE_H

#include <RobotEngine/Module/AbstractComponent.h>

// Un module ne peut pas demander à un autre module d'agir
// C'est à l'étage au dessus (le controlleur/robot) d'implémenter les 
// signaux / actions entre modules

namespace rem {

  /*
  Une action ne peut pas être ré-appelée tant qu'elle n'est pas terminée,
  cela n'aurait pas de sens.

  Une action ne peut pas pour l'instant être lancée dans un thread,
  donc par exemple on peut définir:
  - une action "activer avancer"
  - une action "désactiver avancer"
  Mais pas d'action:
  - "avancer de tant"
  SAUF s'il n'y a qu'une action dans ce composant ...
  MAIS ce serait bloquant ...
  Conclusion: il faut un moyen de gérer les threads
*/
  struct Action {
    char *name;
    re::VariableType ret;
    re::VariableType *params; // un tableau
  };

  class AbstractModule {
    public:

      AbstractModule(); // initialization
      virtual ~AbstractModule();

      virtual re::VariableData action(int id, re::VariableData **params) = 0; // action ID (0, 1, 2, 3)
      const char *get_name();
      Action **get_actions();

    protected:
      char *_name;
      Action **_actions;
  };
}

#endif

