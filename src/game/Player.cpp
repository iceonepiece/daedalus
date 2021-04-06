#include "Player.hpp"
#include "BoxComponent.hpp"
#include "../core/Game.hpp"
#include "../core/Math.hpp"

const int DEFAULT_PLAYER_X = 10.0f;
const int DEFAULT_PLAYER_Y = 10.0f;
const int PLAYER_WIDTH = 4.0f;
const int PLAYER_HEIGHT = 8.0f;

Player::Player(Game* game)
:Entity(game)
{
  BoxComponent* box = new BoxComponent(this);
  box->SetPosition(Vector2(DEFAULT_PLAYER_X, DEFAULT_PLAYER_Y));
  box->SetSize(Vector2(PLAYER_WIDTH, PLAYER_HEIGHT));

  b2BodyDef bodyDef;
  bodyDef.type = b2_dynamicBody;
  bodyDef.position.Set(DEFAULT_PLAYER_X, DEFAULT_PLAYER_Y);

  b2PolygonShape dynamicBox;
  dynamicBox.SetAsBox(PLAYER_WIDTH / 2, PLAYER_HEIGHT / 2);

  b2FixtureDef fixtureDef;
  fixtureDef.shape = &dynamicBox;
  fixtureDef.density = 1.0f;

  box->CreateBody(&bodyDef, &fixtureDef);
};
