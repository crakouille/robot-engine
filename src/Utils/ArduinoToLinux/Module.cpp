#include <RobotEngine/Utils/ArduinoToLinux/Module.h>
#include <Arduino.h>

using namespace reu;
using namespace reu::atl;

Module::Module() : _driver(9600)
{

}

Module::~Module()
{
  
}

bool Module::read_connection()
{
  bool ret = 0;
  re::Uint8 c = 0;
  re::Uint8 *p8;
  int i, n, d;
  re::Buffer buf = {0};
  
  // attente d'une connection
  
  if(Serial.available() > 0){ // si des données entrantes sont présentes, appel non bloquant

    
  digitalWrite(3, HIGH);
    //_driver.read(&c, 1);
    _driver.read(&buf);
    p8 = (re::Uint8 *) buf.datas;
    c = *p8;

    ret = 1;

    switch(c) {

      case 1:
        this->send_infos();
        break;
      case 2:
        _driver.read(&buf);  // on lit le numéro de l'action à exécuter
        p8 = (re::Uint8 *) buf.datas;
        c = *p8;
      
        _driver.read(&buf); // on récupère les paramètres
        
        buf = this->action(c, &buf); // exécution de l'action n
        _driver.send(&buf); // on envoie la valeur de retour

        break;
      default:
        break;
    };
    
  }
  else
    ;

  if(buf.size > 0)
    free(buf.datas);

  return ret;
}

void Module::send_infos()
{
  re::Uint8 count = 0;
  re::Buffer buf = {0};
  char s[] = "no name to this module";

  // écriture du nom du module
  if(_name)
    buf.datas = _name;
  else
    buf.datas = s;
  
  buf.size = strlen((char *) buf.datas) + 1;

  _driver.send(&buf);
}

