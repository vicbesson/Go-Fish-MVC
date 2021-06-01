/**
* @class Player
* @brief
* This class is meant to act as a player to be used
* in a card game that would use a standard deck of cards.
* @author $Author: Victor Besson $
*/

#ifndef PLAYER_H
#define PLAYER_H

#include "Card.h"
#include <string>
#include <list>

class Player {
 public:
  /**
  * Default Constructor
  * @param n Sets players name to n.
  */
  explicit Player(const std::string &n) : name(n) {}
  /**
  * Destructor
  * Deletes all cards in hand and clears hand.
  */
  virtual ~Player();
  /**
  * Adds card to players hand.
  * @param c Card to add to hand.
  */
  void addCard(Card* c);
  /**
  * Removes card from hand at index in hand vector.
  * @param index The index in the hand for the card to be removed.
  * @return Card that is removed from hand.
  */
  Card* removeCard(unsigned int index);
  /**
  * Pointer to the players hand to be used for manipulation
  * @return Pointer to the players hand.
  */
  std::list<Card*>* getHand() { return &hand; }
  /**
  * Get the players name.
  * @return Name of player.
  */
  std::string getName() { return name; }
  /**
  * Get the players score.
  * @return Score of player.
  */
  unsigned int getScore() { return score; }
  /**
  * Sets players score to specified value.
  * @param s Value to set players score to.
  */
  void setScore(unsigned int s) { score = s; }

 private:
  /**
  * Players name.
  */
  const std::string name;
  /**
  * List of cards that comprises the players hand.
  */
  std::list<Card*> hand;
  /**
  * Players score in game.
  */
  unsigned int score = 0;
};

#endif // PLAYER_H
