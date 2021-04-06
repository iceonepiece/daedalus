#include "Player.hpp"
#include "BoxComponent.hpp"
#include "../core/Math.hpp"

Player::Player(Game* game)
:Entity(game)
{
  BoxComponent* box = new BoxComponent(this);
  box->SetPosition(Vector2(100.0f, 200.0f));
  box->SetSize(Vector2(32.0f, 64.0f));
};
