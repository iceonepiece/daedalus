#pragma once

class Component
{
public:
  Component(class Entity* owner);
  virtual ~Component();

protected:
  class Entity* mOwner;
};
