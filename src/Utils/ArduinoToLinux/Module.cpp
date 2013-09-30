#include <RobotEngine/Utils/ArduinoToLinux/Module.h>
#include <Arduino.h>

using namespace reu;
using namespace reu::atl;

Module::Module() : _driver(9600)
{
  unsigned char c = 42;
  //Serial.write(&c, 1);
  //Serial.write(42);
}

Module::~Module()
{
  
}

re::VariableData Module::action(int id, re::VariableData **params)
{
  re::VariableData ret;

  return ret;
}

re::VariableData **datas = 0;
re::VariableData dat[15];

bool Module::read_connection()
{
  bool ret = 0;
  re::Uint8 c = 0;
  int i, n, d;
  
  if(!datas)
    datas = (re::VariableData **) malloc(sizeof(re::VariableData *) * 15);

  // attente d'une connection
  
  if(Serial.available() > 0){ // si des données entrantes sont présentes, appel non bloquant
    c = Serial.read();

    ret = 1;

    switch(c) {

      case 1:
        this->send_infos();
        break;
      case 2:
        _driver.read(&c, 1); // on lit le numéro de l'action à exécuter
        
        // on calcule le nombre de paramètres
        n = 0;

        if(_actions[c]->params) {
          while(_actions[c]->params[n])
            n++;
        }
        
        // on récupère les paramètres
        for(i = 0; i < n; i++) {
          datas[i] = &dat[i];
          //datas[i]->u8 = 0;
          d = _actions[c]->params[i];

          switch(d) {
            case re::NONE:
              //datas[i].u8 = 1;
              break;
            case re::UINT8:
              _driver.read((void *) &(datas[i]->u8), 1); // appel bloquant
              //datas[i].u8 = 1;
              break;
            default:
              //datas[i].u8 = 1;
              break;
          }
        }

        datas[n] = 0;

        // exécution de l'action n
        this->action(c, (re::VariableData **) datas);

        break;
      default:
        break;
    };
    
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
    send_action_info(i);
    
  }
}

void Module::send_action_info(re::Uint8 actionId)
{
  // Le nom de l'action
  Serial.write(_actions[actionId]->name);
  Serial.write(0); // le \0

  // La valeur de retour
  Serial.write((unsigned char *) &_actions[actionId]->ret, 1);

  // on envoie le nb d'arguments après l'avoir compté

  re::Uint8 r = 0;
  
  if(_actions[actionId]->params) {
    int i = -1;
    unsigned char t;

    do {
      i++;
      t = (unsigned char) _actions[actionId]->params[i];
    } while(_actions[actionId]->params[i]);
    
    r = (re::Uint8) i;
  }

  Serial.write(&r, 1);

  // on écrits tous les arguments
  if(_actions[actionId]->params) {
    int i = 0;
    unsigned char t;

    while(_actions[actionId]->params[i]){
      t = (unsigned char) _actions[actionId]->params[i];
      Serial.write(&t, 1);
      i++;
    }
  }
  else {
  }
}

