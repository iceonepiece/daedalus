#pragma once

#include <SDL2/SDL.h>
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

  Vector2 mPosition;
  Vector2 mSize;
};
