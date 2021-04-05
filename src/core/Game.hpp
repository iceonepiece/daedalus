#pragma once

#include <SDL2/SDL.h>

class Game
{
public:
  Game();
  ~Game();

  bool Initialize(int width, int height);
  void Run();
  void Destroy();

private:
  bool mIsRunning;
  SDL_Window* mWindow;
  SDL_Renderer* mRenderer;
  Uint32 mTicksCount;

  void ProcessInput();
  void Update();
  void Render();
};
