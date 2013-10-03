#include <RobotEngine/Common/AbstractCommunicationDriver.h>
#include <string.h>
#include <stdlib.h>

using namespace re;

AbstractCommunicationDriver::~AbstractCommunicationDriver()
{

}

VariableData AbstractCommunicationDriver::read_data(re::VariableType type)
{
  VariableData data = {0};
  char c;
  char buf[256] = {0};
  int n = 0;
  re::Uint16 size;

  switch(type) {
    case NONE:
      break;
    case UINT8:
      this->read(&data.u8, 1);
      break;
    case UINT16:
      this->read(&data.u16, 2);
      break;
    case SINT8:
      this->read(&data.s8, 1);
      break;
    case SINT16:
      this->read(&data.s16, 2);
      break;
    case STRING:
      
      this->read(&size, 2);
      data.s = (char *) malloc(size + 1);
      data.s[size] = 0;
      this->read(data.s, size);

      break;
    default:
      break;
  }

  return data;
}

void AbstractCommunicationDriver::send_data(VariableData *data, re::VariableType type)
{
  char c = 0;
  re::Uint16 size;

  switch(type) {
    case NONE:
      break;
    case UINT8:
      this->send(&data->u8, 1);
      break;
    case UINT16:
      this->send(&data->u16, 2);
      break;
    case SINT8:
      this->send(&data->s8, 1);
      break;
    case SINT16:
      this->send(&data->s16, 2);
      break;
    case STRING:
      size = (re::Uint16) strlen(data->s);
      this->send(&size, 2);
      this->send(data->s, size);
      break;
    default:
      break;
  }

  return;
}

