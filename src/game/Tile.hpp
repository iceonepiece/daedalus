#pragma once

#include "../core/Math.hpp"
#include "../core/Entity.hpp"

class Tile : public Entity
{
public:
  Tile(class Game* game, Vector2 position);
};
