/**
* @class Card
* @brief
* This class is meant to act as a card that would be in a
* standard deck of cards.
* @author $Author: Victor Besson $
*/

#ifndef CARD_H
#define CARD_H

#include <string>
#include <iostream>

class Card {
 public:
  /**
  * Enum used for creation of card,
  * used as card suit.
  */
  enum Suit {Diamond, Heart, Club, Spade, SLast};
  /**
  * Enum used for creation of card,
  * used as card number/rank.
  */
  enum Number {Ace, Two, Three, Four, Five, Six, Seven, Eight, Nine,
    Ten, Jack, Queen, King, NLast};
  /**
  * Constructor.
  * @param s The suit of the card to be created.
  * @param n The number of the card to be created.
  */
  Card(Suit s, Number n) : suit(s), number(n) {}
  /**
  * Destructor.
  */
  virtual ~Card() {}
  /**
  * Gets the suit of the card.
  * @return The string value of the cards suit.
  */
  std::string getSuit();
  /**
  * Gets the number of the card.
  * @return The string value of the cards number.
  */
  std::string getNumber();

 private:
  /**
  * Suit value of the card.
  */
  const Suit suit;
  /**
  * Number value of the card.
  */
  const Number number;
};

#endif // CARD_H
