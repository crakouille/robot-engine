#include <Arduino.h>
#include "MyModule/MyModule.h"

/*
  1er exemple: MyModule est un module dont les composants
  sont déclarés et traités par la même arduinos.
*/

MyModule *module;

void setup()
{
  module = new MyModule();

  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

int init_ok = 0;


void loop()
{
  char c;

  if(module->read_connection())
    init_ok = 1;
  else;

  // Tant que ce n'est pas chargé
  if(!init_ok) {
    return;
  }

  // Une fois que c'est chargé

  module->loop();
}

