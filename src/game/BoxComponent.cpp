#include "BoxComponent.hpp"
#include "../core/Entity.hpp"
#include "../core/Game.hpp"

const int MET2PIX = 10;

BoxComponent::BoxComponent(Entity* owner)
:Component(owner)
,mPosition(Vector2(0.0f, 0.0f))
,mSize(Vector2(0.0f, 0.0f))
,mBody(nullptr)
{
  mOwner->GetGame()->AddBoxComponent(this);
}

BoxComponent::~BoxComponent()
{
  mOwner->GetGame()->RemoveBoxComponent(this);
}

void BoxComponent::Draw(SDL_Renderer* renderer)
{
  if (mBody) {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    b2Vec2 position = mBody->GetPosition();

    SDL_Rect rect;
    rect.x = static_cast<int>((position.x - mSize.x / 2) * MET2PIX);
    rect.y = static_cast<int>((position.y - mSize.y / 2) * MET2PIX);
    rect.w = static_cast<int>(mSize.x * MET2PIX);
    rect.h = static_cast<int>(mSize.y * MET2PIX);

    /*
    SDL_Rect box;
    box.w = static_cast<int>(4.0f * MET2PIX);
    box.h = static_cast<int>(4.0f * MET2PIX);
    box.x = static_cast<int>(body->GetPosition().x * MET2PIX);
    box.y = static_cast<int>(-(body->GetPosition().y + 2.0f) * MET2PIX);
    */

    SDL_RenderFillRect(renderer, &rect);
  }
}

void BoxComponent::CreateBody(b2BodyDef* bodyDef, b2FixtureDef* fixtureDef)
{
  mBody = mOwner->GetGame()->GetPhysics()->GetWorld()->CreateBody(bodyDef);
  mBody->CreateFixture(fixtureDef);
}

void BoxComponent::CreateStaticBody(b2BodyDef* bodyDef, b2PolygonShape* shape)
{
  mBody = mOwner->GetGame()->GetPhysics()->GetWorld()->CreateBody(bodyDef);
  mBody->CreateFixture(shape, 0.0f);
}
