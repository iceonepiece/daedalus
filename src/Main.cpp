#include <box2d/box2d.h>
#include "./core/Game.hpp"

int main(int argc, char** argv) {
  Game game = Game();

  game.initialize(800, 600);

  while (game.isRunning) {
    game.processInput();
    game.update();
    game.render();
  }

  game.destroy();
}
