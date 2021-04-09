#pragma once

class Application
{
public:
  Application(class Window* window);
  ~Application();

  bool Initialize();
  void Destroy();
  void Run();
  void Stop();

private:
  bool mIsRunning;
  class Window* mWindow;
};
