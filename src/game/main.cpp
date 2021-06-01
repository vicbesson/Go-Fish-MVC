#include "../../include/Deck.h"
#include "../../include/GoFish.h"
#include "../../include/Player.h"

int main() {
  GoFish* game = new GoFish(new GoFishUI(), new Deck());
  game->addPlayer(new Player("cpu1"));
  game->addPlayer(new Player("cpu2"));
  game->addPlayer(new Player("cpu3"));
  game->start();
  delete game;
  return 0;
}
