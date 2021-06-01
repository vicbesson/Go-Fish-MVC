/**
* @class GoFish
* @brief
* This class is meant to act as the controller for the game
* GoFish.
* @author $Author: Victor Besson $
*/

#ifndef GOFISH_H
#define GOFISH_H

#include "GoFishUI.h"
#include "Player.h"
#include "Deck.h"
#include <vector>
#include <list>
#include <string>

class GoFish {
 public:
  /**
  * Constructor.
  * @param gui The view to be used for GoFish.
  * @param d The deck to be used in GoFish
  */
  GoFish(GoFishUI* gui, Deck* d) : ui(gui), deck(d) {}
  /**
  * Destructor.
  * Deletes and clears: players, ui, deck.
  */
  virtual ~GoFish();
  /**
  * Deals cards to players based on rules from
  * https://bicyclecards.com/how-to-play/go-fish/
  * also displays any books made.
  */
  void dealCards();
  /**
  * Add player to game.
  * @param p The player to be added to the game.
  */
  void addPlayer(Player* p);
  /**
  * Runs the game.
  * Main loop where game is ran.
  */
  void start();
  /**
  * Checks a players hand for book and removes book
  * returning true if book is present.
  * @param hand The hand to be checked for book.
  * @return Will return True if hand has book else will return false.
  */
  bool hasBook(std::list<Card*>* hand);
  /**
  * Checks each player and adds them to deadplayers if
  * deck is empty and player has no cards left in hand.
  * @return Will return true if player is out else will return false.
  */
  bool checkIfPlayerLive();
  /**
  * What needs to be done automatically before activePlayers action.
  */
  void beforeAction();
  /**
  * Takes choosenCard from choosenPlayer.
  * @param choosenCard The string value of the
  *  choosen cards number.
  * @param to The player recieving the cards.
  * @param from The player who the cards were taken.
  * @return Will return true if card(s) was taken.
  */
  bool takeCard(std::string choosenCard,
  Player* to, Player* from);
  /**
  * What needs to be done automatically after activePlayers action.
  */
  void afterAction();
  /**
  * Makes the player draw a card from the deck.
  * @param hand The hand to give the drawn card to.
  */
  void fish(std::list<Card*>* hand);
  /**
  * Checks each player and adds them to deadplayers if
  * @return Will return true if no players are live else false.
  */
  bool gameOver();
  /**
  * Getter for live players.
  * @return Vector of live players.
  */
  std::vector<Player*> getLivePlayers() { return livePlayers; }

 private:
  /**
  * View to be used for GoFish controller.
  */
  GoFishUI* ui;
  /**
  * Deck to be used for the game.
  */
  Deck* deck;
  /**
  * Index of player whose turn it is.
  */
  unsigned int activePlayer = 0;
  /**
  * True if activePlayers turn is done False if it is not.
  */
  bool turnOver = 1;
  /**
  * Vector of players that are out of the game.
  */
  std::vector<Player*> deadPlayers;
  /**
  * Vector of players are still in the game.
  */
  std::vector<Player*> livePlayers;
};

#endif // GOFISH_H
