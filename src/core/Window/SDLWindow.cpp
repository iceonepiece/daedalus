#include "SDLWindow.hpp"

SDLWindow::SDLWindow(int width, int height)
:Window(width, height)
{}

SDLWindow::~SDLWindow()
{}

bool SDLWindow::Initialize()
{
  if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO) != 0)
  {
    SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
    return false;
  }

  mWindow = SDL_CreateWindow(
    NULL,
    SDL_WINDOWPOS_CENTERED,
    SDL_WINDOWPOS_CENTERED,
    mWidth,
    mHeight,
    NULL
  );

  if (!mWindow)
  {
    SDL_Log("Failed to create window: %s", SDL_GetError());
    return false;
  }

  mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if (!mRenderer)
  {
    SDL_Log("Failed to create renderer: %s", SDL_GetError());
    return false;
  }

  return true;
}

void SDLWindow::Destroy()
{
  SDL_DestroyRenderer(mRenderer);
  SDL_DestroyWindow(mWindow);
  SDL_Quit();
}

void SDLWindow::Run()
{
  ProcessInput();
  Update();
  Render();
}

void SDLWindow::ProcessInput()
{
  SDL_Event event;
  while (SDL_PollEvent(&event))
  {
    switch (event.type)
    {
      case SDL_QUIT:
        mApplication->Stop();
        break;
    }
  }

  const Uint8* state = SDL_GetKeyboardState(NULL);
  if (state[SDL_SCANCODE_ESCAPE])
  {
    mApplication->Stop();
  }

  // Do something here
}

void SDLWindow::Update()
{
  while (!SDL_TICKS_PASSED(SDL_GetTicks(), mTicksCount + 16));

  float deltaTime = (SDL_GetTicks() - mTicksCount) / 1000.0f;
  if (deltaTime > 0.05f)
  {
    deltaTime = 0.05f;
  }
  mTicksCount = SDL_GetTicks();

  // Do something here
}

void SDLWindow::Render()
{
  SDL_SetRenderDrawColor(mRenderer, 0, 0, 0, 255);
  SDL_RenderClear(mRenderer);

  // Do something here

  SDL_RenderPresent(mRenderer);
}
