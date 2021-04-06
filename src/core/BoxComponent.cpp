#include "BoxComponent.hpp"
#include "Entity.hpp"
#include "Game.hpp"

BoxComponent::BoxComponent(Entity* owner)
:Component(owner)
,mPosition(Vector2(0.0f, 0.0f))
,mSize(Vector2(32.0f, 32.0f))
{
  mOwner->GetGame()->AddBoxComponent(this);
}

BoxComponent::~BoxComponent()
{
  mOwner->GetGame()->RemoveBoxComponent(this);
}

void BoxComponent::Draw(SDL_Renderer* renderer)
{
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

  SDL_Rect rect;
  rect.x = static_cast<int>(mPosition.x);
  rect.y = static_cast<int>(mPosition.y);
  rect.w = static_cast<int>(mSize.x);
  rect.h = static_cast<int>(mSize.y);

  SDL_RenderFillRect(renderer, &rect);
}
