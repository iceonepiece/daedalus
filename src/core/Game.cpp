#include "Game.hpp"
#include "Entity.hpp"
#include "Player.hpp"
#include "BoxComponent.hpp"

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

  LoadData();
  mTicksCount = SDL_GetTicks();

  return true;
}

void Game::Destroy()
{
  UnloadData();
  SDL_DestroyRenderer(mRenderer);
  SDL_DestroyWindow(mWindow);
  SDL_Quit();
}

void Game::AddEntity(Entity* entity)
{
  mEntities.emplace_back(entity);
}

void Game::RemoveEntity(Entity* entity)
{
  auto iter = std::find(mEntities.begin(), mEntities.end(), entity);
  if (iter != mEntities.end())
  {
    std::iter_swap(iter, mEntities.end() - 1);
    mEntities.pop_back();
  }
}

void Game::AddBoxComponent(class BoxComponent* boxComponent)
{
  mBoxComponents.emplace_back(boxComponent);
}

void Game::RemoveBoxComponent(class BoxComponent* boxComponent)
{
  auto iter = std::find(mBoxComponents.begin(), mBoxComponents.end(), boxComponent);
  mBoxComponents.erase(iter);
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
  for (int i = 0; i < mBoxComponents.size(); i++)
  {
    BoxComponent* box = mBoxComponents[i];
    box->Draw(mRenderer);
  }

  SDL_RenderPresent(mRenderer);
}

void Game::LoadData()
{
  Player* player = new Player(this);
}

void Game::UnloadData()
{
  while (!mEntities.empty())
  {
    delete mEntities.back();
  }
}
