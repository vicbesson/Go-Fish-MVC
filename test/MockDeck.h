#ifndef MOCKDECK_H_INCLUDED
#define MOCKDECK_H_INCLUDED

#include "gmock/gmock.h"
#include "../include/Deck.h"
#include "../include/Card.h"

class MockDeck : public Deck {
 public:
  explicit MockDeck() {}
  virtual ~MockDeck() {}
  MOCK_METHOD0(createDeck, void());
  MOCK_METHOD0(drawCard, Card*());
  MOCK_METHOD0(shuffle, void());
  MOCK_METHOD0(getSize, unsigned int());
  MOCK_METHOD1(addCard, void(Card*));
};

#endif //MOCKDECK_H_INCLUDED
