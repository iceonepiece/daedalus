#pragma once

#include <iostream>
#include <SDL2/SDL.h>
#include <box2d/box2d.h>

class Scene {
public:
  Scene();
  ~Scene();

  void update(float deltaTime);
  void render(SDL_Renderer* renderer);
  void ProcessKeyboard(const uint8_t* state);

private:
  b2World world;
  b2Body* groundBody;
  b2Body* body;
};
