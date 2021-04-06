#pragma once

#include <SDL2/SDL.h>
#include <box2d/box2d.h>
#include "../core/Math.hpp"
#include "../core/Component.hpp"

class BoxComponent : public Component
{
public:
  BoxComponent(class Entity* owner);
  ~BoxComponent();

  void SetPosition(Vector2 position) { mPosition = position; }
  void SetSize(Vector2 size) { mSize = size; }
  void Draw(SDL_Renderer* renderer);

  void CreateBody(b2BodyDef* bodyDef, b2FixtureDef* fixtureDef);
  void CreateStaticBody(b2BodyDef* bodyDef, b2PolygonShape* shape);
  b2Body* GetBody() { return mBody; }

private:
  Vector2 mPosition;
  Vector2 mSize;
  b2Body* mBody;
};
