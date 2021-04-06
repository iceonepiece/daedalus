#include "Entity.hpp"
#include "Game.hpp"
#include "Component.hpp"

Entity::Entity(Game* game)
:mGame(game)
{
  mGame->AddEntity(this);
}

Entity::~Entity()
{
  mGame->RemoveEntity(this);

  while (!mComponents.empty())
  {
    delete mComponents.back();
  }
}

void Entity::AddComponent(Component* component)
{
  mComponents.emplace_back(component);
}

void Entity::RemoveComponent(Component* component)
{
  auto iter = std::find(mComponents.begin(), mComponents.end(), component);
  if (iter != mComponents.end())
  {
    mComponents.erase(iter);
  }
}
