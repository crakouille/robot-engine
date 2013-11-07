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

  _driver = driver;

  this->get_infos();
}

Module::~Module()
{
  
}

re::Buffer Module::action(int id, re::Buffer *params_buf)
{
  re::Buffer ret = {0};
  re::Buffer buf = {0};

  // code pour dire que c'est une action à exécuter

  unsigned char c = 2;
  buf.datas = &c;
  buf.size = 1;

  _driver->send(&buf); // on dit qu'on envoie une action

  // on envoie le numéro de l'action
//  printf("action id: %d\n", id);

  c = (unsigned char) id;

  _driver->send(&buf); // on dit qu'on demande l'action 'id'

  // on envoie tous les arguments

  _driver->send(params_buf);
  
  // récupérer la valeur de retour dans 'ret'
  _driver->read(&ret);

  return ret;
}

bool Module::get_infos()
{
  re::Buffer buf = {0};
  unsigned char c = 1;
  int i = 0;
  char n = 0;
  int k;

  buf.datas = &c;
  buf.size = 1;

  _driver->send(&buf); // demande les infos 
  buf.size = 0;
  buf.datas = 0;

  _driver->read(&buf); // demande des infos sur le module

  //printf("Module '%s'\n", (char *) (buf.datas));

  return 1;
}

