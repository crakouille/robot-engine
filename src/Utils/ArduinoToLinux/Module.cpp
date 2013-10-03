#include <RobotEngine/Utils/ArduinoToLinux/Module.h>
#include <Arduino.h>

using namespace reu;
using namespace reu::atl;

Module::Module() : _driver(9600)
{
  unsigned char c = 42;
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
  re::VariableData t;
  
  if(!datas)
    datas = (re::VariableData **) malloc(sizeof(re::VariableData *) * 15);

  // attente d'une connection
  
  if(Serial.available() > 0){ // si des données entrantes sont présentes, appel non bloquant
    _driver.read(&c, 1);

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

          t = _driver.read_data((re::VariableType) d);
          datas[i]->u8 = t.u8;
        }

        datas[n] = 0;

        // exécution de l'action n
        t = this->action(c, (re::VariableData **) datas);
        _driver.send_data(&t, _actions[c]->ret);

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
  re::VariableData data;
  char s[] = "no name to this module";

  if(_actions) {
    for(; _actions[count] != 0; count ++);
  }

  // écriture du nom du module
  if(_name)
    data.s = _name;
    //Serial.write((unsigned char *) _name, strlen(_name));
  else
    data.s = s;
    //Serial.write((unsigned char *) "no name to this module", 22);

  _driver.send_data(&data, re::STRING);
  //Serial.write(0);

  // écriture du nombre d'actions
  Serial.write(&count, 1);

  for(re::Uint8 i = 0; i < count; i++) {
    send_action_info(i);
    
  }
}

void Module::send_action_info(re::Uint8 actionId)
{
  re::VariableData v;
  
  v.s = _actions[actionId]->name;
  _driver.send_data(&v, re::STRING);
  // Le nom de l'action
  //Serial.write(_actions[actionId]->name);
  //Serial.write(0); // le \0

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

