#include "core/Application.hpp"
#include "core/Window/SDLWindow.hpp"

int main(int argc, char** argv)
{
  Application app = Application(new SDLWindow(800, 600));

  bool success = app.Initialize();

  if (success)
  {
    app.Run();
  }

  app.Destroy();

  return 0;
}
