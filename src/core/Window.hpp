#pragma once

#include <SDL2/SDL.h>
#include <GL/glew.h>
#include "../vendor/imgui/imgui.h"
#include "../vendor/imgui/imgui_impl_sdl.h"
#include "../vendor/imgui/imgui_impl_opengl3.h"

class Window
{
public:
  Window(int width, int height);
  ~Window();

  bool Initialize();
  void Render();
  void Destroy();

  unsigned int GetWidth() { return mWidth; }
  unsigned int GetHeight() { return mHeight; }

private:
  SDL_Window* mWindow;
  SDL_GLContext mContext;

  bool show_demo_window;

  unsigned int mWidth;
  unsigned int mHeight;
};
