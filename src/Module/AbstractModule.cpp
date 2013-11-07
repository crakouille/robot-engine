#include <RobotEngine/Module/AbstractModule.h>

using namespace rem;

AbstractModule::AbstractModule()
{
  _name = 0;
}

AbstractModule::~AbstractModule()
{

}

const char *AbstractModule::get_name()
{
  return _name;
}

