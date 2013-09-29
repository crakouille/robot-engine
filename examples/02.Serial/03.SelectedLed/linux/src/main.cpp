#include <stdio.h>
#include <RobotEngine/Utils/LinuxToArduino/LTACommunicationDriver.h>
#include <RobotEngine/Utils/LinuxToArduino/Module.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv)
{
  reu::lta::Module *module;
  char buf[1000] = {0};
  reu::lta::LTACommunicationDriver cd("/dev/ttyACM0", 9600);
  
  module = new reu::lta::Module(&cd); // on déclare le module avec ce driver
  // --
  char c[] = {2, 3, 13};
  while(1) {
    memset(buf, 0, 1000);
    cd.read(buf, 999);
    cd.send(c, 3);
    printf("<%s>", buf);
    sleep(1);
  }

  //close(device);

  return 0;
}

