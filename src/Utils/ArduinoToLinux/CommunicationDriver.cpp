#include <RobotEngine/Utils/LinuxToArduino/CommunicationDriver.h>
#include <oacl/oacl.h>

using namespace reu;
using namespace reu::atl;

CommunicationDriver::CommunicationDriver(const char *device, int speed)
{
  
}

CommunicationDriver::~CommunicationDriver()
{
}

re::Uint16 CommunicationDriver::read(void *p, re::Uint16 maxsize)
{
  re::Uint16 i = 0;
  char *q = (char *)p;

  while(i < size) // si des données entrantes sont présentes
  {
    if(Serial.available() > 0) {
      q[i] = Serial.read();
      i ++;
    }
    else
      if (serialEventRun) serialEventRun();
  }

  return i;
}

// if (serialEventRun) serialEventRun();

bool CommunicationDriver::send(const void *p, re::Uint16 size)
{
  Serial.write((unsigned int *) p, size);
}

