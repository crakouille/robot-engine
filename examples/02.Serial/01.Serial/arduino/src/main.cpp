#include <Arduino.h>
#include <RobotEngine/Component/Component.h>
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

  if(!init_ok) {
    if(module->read_connection())
      init_ok = 1;
    else;

    return;
  }

  module->loop();

  //Serial.println("1");

  while(Serial.available() > 0) // si des données entrantes sont présentes
  {
    c = Serial.write((unsigned char *) &c, 1);
  }

  delay(100);

  /*int t = Serial.parseInt();
  module->setT(t);*/
}

