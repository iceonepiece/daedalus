#pragma once

#include "Entity.hpp"
#include "Game.hpp"

class Player : public Entity
{
public:
  Player(Game* game);
};
