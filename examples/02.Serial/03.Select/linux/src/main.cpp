#include <stdio.h>
#include <RobotEngine/Utils/LinuxToArduino/LTACommunicationDriver.h>
#include <RobotEngine/Utils/LinuxToArduino/Module.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
  reu::lta::Module *module;

  // Le driver pour communiquer avec la carte
  // Nécessitera l'usage de udev pour déterminer les "/dev/ttyACMX"
  reu::lta::LTACommunicationDriver cd("/dev/ttyACM0", 9600);
  sleep(2); // cf http://playground.arduino.cc/interfacing/python

  module = new reu::lta::Module(&cd); // on déclare le module avec ce driver
  
  re::VariableData **params = (re::VariableData **) malloc(sizeof(re::VariableData *) * 2);
  params[0] = (re::VariableData *) malloc(sizeof(re::VariableData));
  params[0]->u8 = 1;
  params[1] = nullptr;  

  while(1) { // pour laisser l'arduino faire le loop()
    
    module->action(0, params);
    usleep(1000 * 500);

    /*module->action(1, params);        
    usleep(1000 * 500);*/

    params[0]->u8 = !params[0]->u8;
  }

  delete module;

  return 0;
}

