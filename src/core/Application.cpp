#include "Application.hpp"
#include "Window/Window.hpp"

Application::Application(Window* window)
:mIsRunning(false)
,mWindow(window)
{
}

Application::~Application()
{

}

bool Application::Initialize()
{
  if (!mWindow || !mWindow->Initialize())
    return false;

  mWindow->SetApplication(this);

  return true;
}

void Application::Destroy()
{
  mWindow->Destroy();
}

void Application::Run()
{
  mIsRunning = true;

  while (mIsRunning)
  {
    mWindow->Run();
  }
}

void Application::Stop()
{
  mIsRunning = false;
}
