#include <RobotEngine/Utils/LinuxToArduino/Module.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

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

void Module::action(int id, re::VariableData **params)
{
  
}

bool Module::get_infos()
{
  unsigned char buf[1000] = {1};
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

    this->get_infos_get_action();
    
  }

  printf("=== fin get_infos ===.\n");

  return 1;
}

void Module::get_infos_get_action()
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

}


