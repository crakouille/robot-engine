#include <RobotEngine/Utils/LinuxToArduino/Module.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

using namespace reu;
using namespace reu::lta;

Module::Module(LTACommunicationDriver *driver)
{
  //sleep(2); // cf http://playground.arduino.cc/interfacing/python
  // c'est même mis dedans ...

  //char c;
  re::Sint16 ok = 0;
  _driver = driver;

  //while(_driver->read(&c, 1) <= 0) // on attend le premier caractère
  //  ;

  //printf("c = %d\n", c);// -> 42 

  //while(ok <= 0)
  //  ok = this->get_infos();
  this->get_infos();
}

Module::~Module()
{
  
}

re::VariableData Module::action(int id, re::VariableData **params)
{
  re::VariableData ret;

  unsigned char c = 2; // code pour dire que c'est une action à exécuter
  _driver->send(&c, 1); // on dit qu'on envoie une action

  printf("action id: %d\n", id);

  c = (unsigned char) id;

  _driver->send(&c, 1); // on dit qu'on demande l'action 'id'

  // on envoie tous les arguments

  if(params) {
    int i = 0;

    while(params[i]) {
      //printf("hey ! %d\n", i);
      switch(_actions[id]->params[i]) {
        case re::UINT8:
          _driver->send(&(params[i]->u8), 1);
          break;
        default:
          break;
      }
      //printf("setg.\n");
      i ++;
    }

    // récupérer la valeur de retour dans 'ret'
  }

  return ret;
}

bool Module::get_infos()
{
  unsigned char buf[1000] = {1};
  rem::Action *bufAction[1000];
  int i = 0;
  char n = 0;
  int k;

  _driver->send(buf, 1); // demande des infos sur le module
  
  buf[0] = 0;

  // lecture du nom du composant

  // lecture du nom du module
  printf("%d octets lus\n", _driver->read_str(buf, 999));
  printf("Module '%s'\n", buf);

  // lecture du nombre d'actions
  while(_driver->read(&n, 1) <= 0);

  printf("Nombre d'actions: %d\n", n);

  for(i = 0; i < n; i++) { // on lit 
    bufAction[i] = this->get_infos_get_action();
  }

  _actions = (rem::Action **) malloc(sizeof(rem::Action *) * (n + 1));

  for(i = 0; i < n; i++) { // on lit 
    _actions[i] = bufAction[i];
  }

  _actions[n] = nullptr;

  printf("=== fin get_infos ===.\n");

  return 1;
}

rem::Action *Module::get_infos_get_action()
{
  rem::Action *action = new rem::Action;
  unsigned char buf[1000] = {1};
  unsigned char t;

  // on lit le nom de l'action
  _driver->read_str(buf, 999);

  action->name = strdup((const char *) buf);
  
  // on lit le paramètre de retour
  
  while(_driver->read(&t, 1) <= 0);

  action->ret = (re::VariableType) t;

  printf("Action: ");
  switch(t) {
      case re::NONE:
        printf("NONE ");
        break;
      case re::UINT8:
        printf("Uint8 ");
        break;
      case re::UINT16:
        printf("Uint16 ");
        break;
      case re::SINT8:
        printf("Sint8 ");
        break;
      case re::SINT16:
        printf("Sint16 ");
        break;
      case re::STRING:
        printf("string ");
        break;
      default:
        break;
      
  }
  printf("'%s'(", buf);

  // on lit le nombre de paramètres
  
  while(_driver->read(&t, 1) <= 0);

  int nb = t;

  // on lit les paramètres

  action->params = new re::VariableType[t + 1];

  for(int i = 0; i < nb; i++) {
    _driver->read(&t, 1);
    action->params[i] = (re::VariableType) t;

    switch(t) {
      case re::NONE:
        printf("NONE ");
        break;
      case re::UINT8:
        printf("Uint8 ");
        break;
      case re::UINT16:
        printf("Uint16 ");
        break;
      case re::SINT8:
        printf("Sint8 ");
        break;
      case re::SINT16:
        printf("Sint16 ");
        break;
      case re::STRING:
        printf("string ");
        break;
      default:
        break;
      
    }
  }

  printf(")\n");

  return action;
}


