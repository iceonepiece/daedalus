#include "Component.hpp"
#include "Entity.hpp"

Component::Component(Entity* owner)
:mOwner(owner)
{
  mOwner->AddComponent(this);
}

Component::~Component()
{
  mOwner->RemoveComponent(this);
}
