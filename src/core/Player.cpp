#include "Player.hpp"
#include "BoxComponent.hpp"
#include "Math.hpp"

Player::Player(Game* game)
:Entity(game)
{
  BoxComponent* box = new BoxComponent(this);
  box->SetPosition(Vector2(100.0f, 200.0f));
};
