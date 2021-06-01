/**
* @class Deck
* @brief
* This class is meant to act as a standard deck of cards
* that would be used in a game such as GoFish.
* @author $Author: Victor Besson $
*/

#ifndef DECK_H
#define DECK_H

#include "Card.h"
#include <vector>
#include <string>

class Deck {
 public:
  /**
  * Constructor.
  */
  Deck() {}
  /**
  * Destructor.
  * Deletes all cards from deck and clears deck.
  */
  virtual ~Deck();
  /**
  * Creates 52 card standard deck.
  */
  virtual void createDeck();
  /**
  * Randomly shuffles the deck.
  * https://en.cppreference.com/w/cpp/algorithm/random_shuffle
  */
  virtual void shuffle();
  /**
  * Gets the decks size.
  * @return The decks size.
  */
  virtual unsigned int getSize() { return deck.size(); }
  /**
  * Draws a card from top of deck removing it from deck.
  * @return Top card of deck.
  */
  virtual Card* drawCard();
  /**
  * Adds card to top of deck.
  * @param c Card to be added to top of deck.
  */
  virtual void addCard(Card* c);

 private:
  /**
  * Vector of cards that comprises the deck.
  */
  std::vector<Card*> deck;
};

#endif // DECK_H
