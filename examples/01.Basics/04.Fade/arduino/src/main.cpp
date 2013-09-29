#include <Arduino.h>
#include <RobotEngine/Utils/ArduinoComponents/LED.h>

/*
  Ne marche qu'avec les pins analogiques de la partie "DIGITAL" de l'arduino.
  Pour les vrais pins analogiques, on passera de Uint8 à Uint16. 
*/

reu::components::LED *led;
re::Uint8 t, sens;

void setup()
{
  led = new reu::components::LED(3, true); // true pour ANALOG
  t = 0;
  sens = 1;
}

void loop()
{

  if(sens) {
    t ++;

    if(t == 255)
      sens = 0;
    else;
  }
  else {
    t --;
    
    if(t == 0)
      sens = 1;
    else;
  }

  led->set_analog(t);
  delay(3.);
}


