#include <RobotEngine/Module/AbstractModule.h>

using namespace rem;

AbstractModule::AbstractModule()
{
  _name = 0;
  _actions = 0;
}

AbstractModule::~AbstractModule()
{

}

const char *AbstractModule::get_name()
{
  return _name;
}

Action **AbstractModule::get_actions()
{
  return _actions;
}

