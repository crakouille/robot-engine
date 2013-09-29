#include <RobotEngine/Module/DistantComponent.h>

using namespace rem;

DistantComponent::DistantComponent(re::AbstractCommunicationDriver *driver)
{
  _driver = 0;
}

DistantComponent::~DistantComponent()
{
  delete _driver;
}

re::AbstractCommunicationDriver *DistantComponent::get_driver()
{
  return _driver;
}


