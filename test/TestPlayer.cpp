#include "gtest/gtest.h"
#include "../include/Player.h"

TEST(TestPlayer, AddCard) {
  Player* p = new Player("player");
  EXPECT_EQ(p->getHand()->size(), 0);
  p->addCard(new Card(Card::Spade, Card::Ace));
  EXPECT_EQ(p->getHand()->size(), 1);
  p->getHand()->push_back(new Card(Card::Spade, Card::Two));
  EXPECT_EQ(p->getHand()->size(), 2);
  Card* c = nullptr;
  p->addCard(c);
  EXPECT_EQ(p->getHand()->size(), 2);
  delete p;
}

TEST(TestPlayer, RemoveCard) {
  Player* p = new Player("player");
  p->addCard(new Card(Card::Spade, Card::Ace));
  p->addCard(new Card(Card::Spade, Card::Two));
  EXPECT_EQ(p->getHand()->size(), 2);
  Card* c = p->removeCard(0);
  EXPECT_TRUE(c->getSuit() == "S" && c->getNumber() == "A");
  EXPECT_EQ(p->getHand()->size(), 1);
  delete c;
  c = p->removeCard(0);
  EXPECT_TRUE(c->getSuit() == "S" && c->getNumber() == "2");
  EXPECT_EQ(p->getHand()->size(), 0);
  delete c;
  delete p;
}

TEST(TestPlayer, GetName) {
  Player* p = new Player("player");
  EXPECT_EQ(p->getName(), "player");
  delete p;
  p = new Player("");
  EXPECT_EQ(p->getName(), "");
  delete p;
}

TEST(TestPlayer, GetScore) {
  Player* p = new Player("player");
  EXPECT_EQ(p->getScore(), 0);
  p->setScore(10);
  EXPECT_EQ(p->getScore(), 10);
  delete p;
}

TEST(TestPlayer, SetScore) {
  Player* p = new Player("player");
  EXPECT_EQ(p->getScore(), 0);
  p->setScore(10);
  EXPECT_EQ(p->getScore(), 10);
  delete p;
}

TEST(TestPlayer, GetHand) {
  Player* p = new Player("player");
  EXPECT_EQ(p->getHand()->size(), 0);
  p->addCard(new Card(Card::Spade, Card::Ace));
  EXPECT_EQ(p->getHand()->size(), 1);
  p->getHand()->push_back(new Card(Card::Spade, Card::Two));
  EXPECT_EQ(p->getHand()->size(), 2);
  delete p->removeCard(1);
  EXPECT_EQ(p->getHand()->size(), 1);
  for (Card* c : *p->getHand()) {
    delete c;
  }
  p->getHand()->clear();
  EXPECT_EQ(p->getHand()->size(), 0);
  delete p;
}
