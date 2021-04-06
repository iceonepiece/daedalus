#pragma once

#include <box2d/box2d.h>

class Physics
{
public:
  Physics();
  void Update(float deltaTime);
  b2World* GetWorld() { return &mWorld; }

private:
  b2World mWorld;
  int32 mVelocityIterations;
  int32 mPositionIterations;
};
