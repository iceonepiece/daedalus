#include "Physics.hpp"

Physics::Physics()
:mWorld(b2Vec2(0.0f, 20.0f))
,mVelocityIterations(6)
,mPositionIterations(2)
{

}

void Physics::Update(float deltaTime)
{
  mWorld.Step(deltaTime, mVelocityIterations, mPositionIterations);
}
