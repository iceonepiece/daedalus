#pragma once

#include <vector>
#include <string>

class Entity
{
public:
  Entity(class Game* game);
  virtual ~Entity();

  class Game* GetGame() { return mGame; }
  void AddComponent(class Component* component);
  void RemoveComponent(class Component* component);

private:
  class Game* mGame;
  std::vector<class Component*> mComponents;
};
