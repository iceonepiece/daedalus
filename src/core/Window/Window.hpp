#pragma once

#include "../Application.hpp"
#include <iostream>

class Window
{
public:
  Window(int width, int height): mWidth(width), mHeight(height), mApplication(nullptr) {}
  ~Window() {}

  virtual bool Initialize() = 0;
  virtual void Run() = 0;
  virtual void Destroy() = 0;

  void SetApplication(Application* application) { mApplication = application; }
  int GetWidth() { return mWidth; }
  int GetHeight() { return mHeight; }

protected:
  Application* mApplication;

  int mWidth;
  int mHeight;
};
