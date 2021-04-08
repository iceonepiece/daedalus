#pragma once

#include "Window.hpp"

class Editor
{
public:
  Editor(int width, int height);
  ~Editor();

  bool Initialize();
  void Run();
  void Destroy();

private:
  bool mIsRunning;
  int mTicksCount;
  Window mWindow;

  void ProcessInput();
  void Update();
  void Render();
};
