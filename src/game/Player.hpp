#pragma once

#include <box2d/box2d.h>
#include "../core/Entity.hpp"

class Player : public Entity
{
public:
  Player(class Game* game);
};
