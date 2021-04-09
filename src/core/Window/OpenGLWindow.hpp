#pragma once

#include <SDL2/SDL.h>
#include <GL/glew.h>
#include "Window.hpp"

class OpenGLWindow : public Window
{
public:
  OpenGLWindow(int width, int height);
  ~OpenGLWindow();

  bool Initialize();
  void Run();
  void Destroy();

private:
  void ProcessInput();
  void Update();
  void Render();

  Uint32 mTicksCount;
  SDL_Window* mWindow;
  SDL_GLContext mContext;
};
