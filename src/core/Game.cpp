#include "Game.hpp"

Game::Game()
:mIsRunning(true)
,mWindow(nullptr)
,mRenderer(nullptr)
{

}

Game::~Game()
{

}

bool Game::Initialize(int width, int height)
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
    width,
    height,
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

  mTicksCount = SDL_GetTicks();

  return true;
}


void Game::Run()
{
  while (mIsRunning)
  {
    ProcessInput();
    Update();
    Render();
  }
}

void Game::ProcessInput()
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

  const Uint8* state = SDL_GetKeyboardState(NULL);
  if (state[SDL_SCANCODE_ESCAPE])
  {
    mIsRunning = false;
  }
}

void Game::Update()
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

void Game::Render()
{
  SDL_SetRenderDrawColor(mRenderer, 0, 0, 0, 255);
  SDL_RenderClear(mRenderer);

  // Do something here

  SDL_RenderPresent(mRenderer);
}

void Game::Destroy()
{
  SDL_DestroyRenderer(mRenderer);
  SDL_DestroyWindow(mWindow);
  SDL_Quit();
}
