#include <RobotEngine/Common/AbstractComponent.h>

using namespace re;

AbstractComponent::AbstractComponent()
{
  _infos = 0;
  _vars = 0;
}

AbstractComponent::~AbstractComponent()
{

}

ComponentInfo *AbstractComponent::get_info()
{
  return _infos;
}

VariableData **AbstractComponent::get_variables()
{
  return _vars;
}

