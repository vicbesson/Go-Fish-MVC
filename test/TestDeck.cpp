#include "gtest/gtest.h"
#include "../include/Deck.h"

TEST(TestDeck, CreateDeck) {
  Deck* d = new Deck();
  d->createDeck();
  EXPECT_EQ(52, d->getSize());
  delete d;
}

TEST(TestDeck, DrawCard) {
  Deck* d = new Deck();
  d->createDeck();
  EXPECT_EQ(52, d->getSize());
  delete d->drawCard();
  EXPECT_EQ(51, d->getSize());
  delete d;
}

TEST(TestDeck, AddCard) {
  Deck* d = new Deck();
  d->createDeck();
  EXPECT_EQ(52, d->getSize());
  Card* c = new Card(Card::Diamond, Card::Ace);
  d->addCard(c);
  EXPECT_EQ(53, d->getSize());
  c = nullptr;
  d->addCard(c);
  EXPECT_EQ(53, d->getSize());
  delete d;
}

TEST(TestDeck, DrawFromEmptyDeck) {
  Deck* d = new Deck();
  d->createDeck();
  EXPECT_EQ(52, d->getSize());
  unsigned int size = d->getSize();
  for (unsigned int i = 0; i < size; i++) {
    delete d->drawCard();
  }
  EXPECT_EQ(0, d->getSize());
  Card* c = d->drawCard();
  EXPECT_TRUE(c == nullptr);
  EXPECT_EQ(0, d->getSize());
  delete d;
  delete c;
}

TEST(TestDeck, Shuffle) {
  Deck* d = new Deck();
  d->createDeck();
  Card* c = d->drawCard();
  EXPECT_TRUE(c->getSuit() == "S" && c->getNumber() == "K");
  d->addCard(c);
  d->shuffle();
  c = d->drawCard();
  EXPECT_FALSE(c->getSuit() == "S" && c->getNumber() == "K");
  delete c;
  delete d;
}
