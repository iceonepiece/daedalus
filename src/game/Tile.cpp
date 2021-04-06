#include "Tile.hpp"
#include "BoxComponent.hpp"
#include "../core/Math.hpp"

const int TILE_WIDTH = 4.0f;
const int TILE_HEIGHT = 4.0f;

Tile::Tile(Game* game, Vector2 position)
:Entity(game)
{
  BoxComponent* box = new BoxComponent(this);
  box->SetPosition(position);
  box->SetSize(Vector2(TILE_WIDTH, TILE_HEIGHT));

  b2BodyDef bodyDef;
  bodyDef.position.Set(position.x, position.y);

  b2PolygonShape shape;
  shape.SetAsBox(TILE_WIDTH / 2, TILE_HEIGHT / 2);

  box->CreateStaticBody(&bodyDef, &shape);
};
