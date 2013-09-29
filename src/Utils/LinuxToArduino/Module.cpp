#include <RobotEngine/Utils/LinuxToArduino/Module.h>
#include <stdio.h>
#include <unistd.h>

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
  re::Sint16 j;
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

    j = _driver->read_str(buf, 999);

    printf("Action '%s': \n", buf);
  }

  printf("=== fin get_infos ===.\n");

  return 1;
}

