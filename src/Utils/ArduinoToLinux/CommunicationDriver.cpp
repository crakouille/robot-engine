#include <RobotEngine/Utils/ArduinoToLinux/CommunicationDriver.h>
#include <Arduino.h>

using namespace reu;
using namespace reu::atl;

CommunicationDriver::CommunicationDriver(int speed)
{
  
}

CommunicationDriver::~CommunicationDriver()
{
}

re::Sint16 CommunicationDriver::read(void *p, re::Uint16 maxsize)
{
  re::Sint16 i = 0;
  char *q = (char *)p;

  while(i < maxsize) // si des données entrantes sont présentes
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
  Serial.write((unsigned char *) p, size);
}

