#include <RobotEngine/Utils/ArduinoToLinux/Module.h>
#include <Arduino.h>

using namespace reu;
using namespace reu::atl;

Module::Module()
{
  unsigned char c = 42;
  //Serial.write(&c, 1);
  //Serial.write(42);
}

Module::~Module()
{
  
}

void Module::action(int id, re::VariableData **params)
{
  
}

bool Module::read_connection()
{
  bool ret = 0;
  re::Uint8 c = 0;

  // attente d'une connection
  
  if(Serial.available() > 0){ // si des données entrantes sont présentes {
    c = Serial.read();

    ret = 1;

    /*switch(c) {

      case 1:
      */  this->send_infos();
      /*  break;

      default:
        Serial.write(&c, 1);
        ret = 0;
        break;
    };*/
    
  }
  else
    ;

  return ret;
}

void Module::send_infos()
{
  re::Uint8 count = 0;

  if(_actions) {
    for(; _actions[count] != 0; count ++);
  }

  // écriture du nom du module
  if(_name)
    Serial.write((unsigned char *) _name, strlen(_name));
  else
    Serial.write((unsigned char *) "no name to this module", 22);

  Serial.write(0);

  // écriture du nombre d'actions
  Serial.write(&count, 1);

  for(re::Uint8 i = 0; i < count; i++) {
    Serial.write(_actions[i]->name);
    Serial.write(0); // le \0
  }
}

