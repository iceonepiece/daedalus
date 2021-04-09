#pragma once

#include <SDL2/SDL.h>
#include "Window.hpp"

class SDLWindow : public Window
{
public:
  SDLWindow(int width, int height);
  ~SDLWindow();

  bool Initialize();
  void Run();
  void Destroy();

private:
  void ProcessInput();
  void Update();
  void Render();

  Uint32 mTicksCount;
  SDL_Window* mWindow;
  SDL_Renderer* mRenderer;
};
