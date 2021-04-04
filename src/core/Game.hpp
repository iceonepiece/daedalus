#pragma once

#include <iostream>
#include <SDL2/SDL.h>
#include <box2d/box2d.h>
#include "Scene.hpp"

class Game {
private:
  SDL_Window *window;
  SDL_Renderer *renderer;
  Uint32 mTicksCount;
  Scene* scene;

public:
  bool isRunning;

  Game();
  ~Game();

  void initialize(int width, int height);
  void processInput();
  void update();
  void render();
  void destroy();
};
