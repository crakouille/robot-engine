#include <RobotEngine/Common/AbstractCommunicationDriver.h>
#include <string.h>
#include <stdlib.h>

using namespace re;

AbstractCommunicationDriver::~AbstractCommunicationDriver()
{
  
}

bool AbstractCommunicationDriver::read(re::Buffer *buf)
{
  if(buf->size != 0)
    free(buf->datas);

  this->read2(&buf->size, 2);

  buf->datas = malloc(buf->size);
  
  this->read2(buf->datas, buf->size);

  // checksum todo

  return true;
}

void AbstractCommunicationDriver::send(re::Buffer *buf)
{
  this->send2(&buf->size, 2);
  this->send2(buf->datas, buf->size);

  // checksum todo
}

