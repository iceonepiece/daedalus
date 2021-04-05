#include "core/Game.hpp"

int main(int argc, char** argv)
{
  Game game = Game();
  bool success = game.Initialize(800, 600);

  if (success)
  {
    game.Run();
  }

  game.Destroy();
  return 0;
}
