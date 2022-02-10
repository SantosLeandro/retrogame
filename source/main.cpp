#include "allegro/game.h"

int main(){
  AllegroGame *game = new AllegroGame();
  game->init();
  game->run();
  game->quit();
}
