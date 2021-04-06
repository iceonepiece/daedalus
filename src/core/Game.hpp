#pragma once

#include <vector>
#include <SDL2/SDL.h>

class Game
{
public:
  Game();
  ~Game();

  bool Initialize(int width, int height);
  void Run();
  void Destroy();

  void AddEntity(class Entity* entity);
  void RemoveEntity(class Entity* entity);

  // Game specific
  void AddBoxComponent(class BoxComponent* boxComponent);
  void RemoveBoxComponent(class BoxComponent* boxComponent);

private:
  bool mIsRunning;
  SDL_Window* mWindow;
  SDL_Renderer* mRenderer;
  Uint32 mTicksCount;

  std::vector<class Entity*> mEntities;

  void ProcessInput();
  void Update();
  void Render();
  void LoadData();
  void UnloadData();

  // Game specific
  std::vector<class BoxComponent*> mBoxComponents;
};
