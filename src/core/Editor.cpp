#include "Editor.hpp"

Editor::Editor(int width, int height)
:mIsRunning(true)
,mWindow(width, height)
{

}

Editor::~Editor()
{

}

bool Editor::Initialize()
{
  return mWindow.Initialize();
}

void Editor::Run()
{
  while (mIsRunning)
  {
    ProcessInput();
    Update();
    Render();
  }
}

void Editor::Destroy()
{
  mWindow.Destroy();
}

void Editor::ProcessInput()
{
  SDL_Event event;
  while (SDL_PollEvent(&event))
  {
    switch (event.type)
    {
      case SDL_QUIT:
        mIsRunning = false;
        break;
    }
  }
}

void Editor::Update()
{

}

void Editor::Render()
{
  mWindow.Render();
}
