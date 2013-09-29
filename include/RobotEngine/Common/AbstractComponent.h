#ifndef NATIV_GAMES_STUDIOS_ROBOT_ENGINE_COMMON_ABSTRACTCOMPONENT_H
#define NATIV_GAMES_STUDIOS_ROBOT_ENGINE_COMMON_ABSTRACTCOMPONENT_H

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

namespace re {

  class ComponentInfo {
    public:
      ComponentInfo();
      virtual ~ComponentInfo();
  
      bool get_type(); // 0 = effecteur, 1 = capteur
      void set_name(const char *name);
      void set_variables_infos(VariableInfo **vars);
      void set_fn_params_infos(VariableInfo **params); // action or signal
      void set_fn_return_type(VariableType type);
  
      const char *get_name();
      const VariableInfo **get_variables_infos();
      const VariableInfo **get_fn_params_infos();
      VariableType get_fn_return_type();
      //void set_action_params_types(VariableInfo **params);
  
    private:
      
      bool _type;
      char *_name;
      VariableInfo **_variables_types;
  };
 
  class AbstractComponent {
    public:
  
      AbstractComponent();
      virtual ~AbstractComponent();
  
      /*
        call:
        for an effector: execute an action
        for a sensor: get a signal
      */
      virtual re::VariableData *call(re::VariableData **vars) = 0;

      ComponentInfo *get_info();
      VariableData **get_variables();
 
    protected:
  
      ComponentInfo *_infos; // Les infos sur le composant
      VariableData **_vars;  // Les variables 
  };

}
  
#endif

