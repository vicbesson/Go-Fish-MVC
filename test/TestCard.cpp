#include <string>
#include "gtest/gtest.h"
#include "../include/Card.h"

std::string testSuit(unsigned int i) {
  switch (i) {
    case 0:
      return "D";
    case 1:
      return "H";
    case 2:
      return "C";
    case 3:
      return "S";
  }
  return "?";
}

std::string testNumber(unsigned int i) {
  switch (i) {
    case 0:
      return "A";
    case 1:
      return "2";
    case 2:
      return "3";
    case 3:
      return "4";
    case 4:
      return "5";
    case 5:
      return "6";
    case 6:
      return "7";
    case 7:
      return "8";
    case 8:
      return "9";
    case 9:
      return "10";
    case 10:
      return "J";
    case 11:
      return "Q";
    case 12:
      return "K";
  }
  return "?";
}

TEST(TestCard, GetSuit) {
  for (unsigned int s = Card::Diamond; s != Card::SLast; s++) {
    for (unsigned int n = Card::Ace; n != Card::NLast; n++) {
      std::string ts = testSuit(s);
      Card* c = new Card(Card::Suit(s), Card::Number(n));
      EXPECT_TRUE(c->getSuit() == ts);
      delete c;
    }
  }
}

TEST(TestCard, getNumber) {
  for (unsigned int s = Card::Diamond; s != Card::SLast; s++) {
    for (unsigned int n = Card::Ace; n != Card::NLast; n++) {
      std::string tn = testNumber(n);
      Card* c = new Card(Card::Suit(s), Card::Number(n));
      EXPECT_TRUE(c->getNumber() == tn);
      delete c;
    }
  }
}

TEST(TestCard, GetSuitEndOfEnum) {
  Card* c = new Card(Card::SLast, Card::Ace);
  EXPECT_EQ(c->getSuit(), "?");
  delete c;
}

TEST(TestCard, GetNumberEndOfEnum) {
  Card* c = new Card(Card::Spade, Card::NLast);
  EXPECT_EQ(c->getNumber(), "?");
  delete c;
}
