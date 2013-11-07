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
  
  re::Uint8 data = 1;
  re::Buffer buf;
  buf.size = 1;
  buf.datas = &data;

  while(1) { // pour laisser l'arduino faire le loop()
    
    module->action(0, &buf);
    usleep(1000 * 200);

    data = !data;
  }

  delete module;

  return 0;
}

