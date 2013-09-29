#include <oacl/oacl.h>
#include <RobotEngine/Component/Component.h>
#include "MyComponent/MyComponent.h"
#include "MyModule/MyModule.h"

/*
  1er exemple: MyModule est un module dont les composants
  sont déclarés et traités par la même arduinos.
*/

MyModule *module;

void setup()
{
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);

  module = new MyModule();
}

int init_ok = 0;


void loop()
{
  char c;

  if(!init_ok) {
    if(module->read_connection())
      init_ok = 1;
    else;

    //digitalWrite(3, HIGH);

    return;
  }

  module->loop();

  //Serial.println("1");

  while(Serial.available() > 0) // si des données entrantes sont présentes
  {
    c = Serial.read();
    digitalWrite(c, HIGH);
  }

  delay(1000);

  /*int t = Serial.parseInt();
  module->setT(t);*/
}

