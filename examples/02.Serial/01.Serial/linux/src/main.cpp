#include <stdio.h>
#include <RobotEngine/Utils/LinuxToArduino/LTACommunicationDriver.h>
#include <RobotEngine/Utils/LinuxToArduino/Module.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv)
{
  reu::lta::Module *module;

  // Le driver pour communiquer avec la carte
  // Nécessitera l'usage de udev pour déterminer les "/dev/ttyACMX"
  reu::lta::LTACommunicationDriver cd("/dev/ttyACM0", 9600);
  sleep(2); // cf http://playground.arduino.cc/interfacing/python

  printf("test\n");

  module = new reu::lta::Module(&cd); // on déclare le module avec ce driver
  
  delete module;

  return 0;
}

