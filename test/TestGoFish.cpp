#include <vector>
#include <list>
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "MockGoFishUI.h"
#include "MockDeck.h"
#include "../include/Player.h"
#include "../include/Card.h"
#include "../include/GoFish.h"

using namespace ::testing;//NOLINT

TEST(TestGoFish, Destructor) {
  GoFishUI* ui = new GoFishUI();
  Deck* d = new Deck();
  GoFish* game = new GoFish(ui, d);
  delete game;
}

TEST(TestGoFish, DealCardsLess3) {
  MockDeck* d = new MockDeck();
  Expectation createDeck
  = EXPECT_CALL(*d, createDeck())
  .Times(1)
  .WillOnce(Return());
  EXPECT_CALL(*d, drawCard())
  .Times(14)
  .After(createDeck)
  .WillOnce(Return(new Card(Card::Diamond, Card::Ace)))
  .WillOnce(Return(new Card(Card::Diamond, Card::Two)))
  .WillOnce(Return(new Card(Card::Diamond, Card::Three)))
  .WillOnce(Return(new Card(Card::Diamond, Card::Four)))
  .WillOnce(Return(new Card(Card::Diamond, Card::Five)))
  .WillOnce(Return(new Card(Card::Diamond, Card::Six)))
  .WillOnce(Return(new Card(Card::Diamond, Card::Seven)))
  .WillOnce(Return(new Card(Card::Diamond, Card::Eight)))
  .WillOnce(Return(new Card(Card::Diamond, Card::Nine)))
  .WillOnce(Return(new Card(Card::Diamond, Card::Ten)))
  .WillOnce(Return(new Card(Card::Diamond, Card::Jack)))
  .WillOnce(Return(new Card(Card::Diamond, Card::Queen)))
  .WillOnce(Return(new Card(Card::Diamond, Card::King)))
  .WillOnce(Return(new Card(Card::Heart, Card::Ace)));
  MockGoFishUI* ui = new MockGoFishUI();
  d->createDeck();
  GoFish* game = new GoFish(ui, d);
  std::vector<Player*> players {new Player("cpu1"), new Player("cpu2")};
  for (Player* p : players) {
    game->addPlayer(p);
  }
  game->dealCards();
  EXPECT_EQ(7, players[0]->getHand()->size());
  EXPECT_EQ(7, players[1]->getHand()->size());
  delete game;
}

TEST(TestGoFish, DealCardsGreater3) {
  MockDeck* d = new MockDeck();
  Expectation createDeck
  = EXPECT_CALL(*d, createDeck())
  .Times(1)
  .WillOnce(Return());
  EXPECT_CALL(*d, drawCard())
  .Times(20)
  .After(createDeck)
  .WillOnce(Return(new Card(Card::Diamond, Card::Ace)))
  .WillOnce(Return(new Card(Card::Diamond, Card::Two)))
  .WillOnce(Return(new Card(Card::Diamond, Card::Three)))
  .WillOnce(Return(new Card(Card::Diamond, Card::Four)))
  .WillOnce(Return(new Card(Card::Diamond, Card::Five)))
  .WillOnce(Return(new Card(Card::Diamond, Card::Six)))
  .WillOnce(Return(new Card(Card::Diamond, Card::Seven)))
  .WillOnce(Return(new Card(Card::Diamond, Card::Eight)))
  .WillOnce(Return(new Card(Card::Diamond, Card::Nine)))
  .WillOnce(Return(new Card(Card::Diamond, Card::Ten)))
  .WillOnce(Return(new Card(Card::Diamond, Card::Jack)))
  .WillOnce(Return(new Card(Card::Diamond, Card::Queen)))
  .WillOnce(Return(new Card(Card::Diamond, Card::King)))
  .WillOnce(Return(new Card(Card::Heart, Card::Ace)))
  .WillOnce(Return(new Card(Card::Heart, Card::Two)))
  .WillOnce(Return(new Card(Card::Heart, Card::Three)))
  .WillOnce(Return(new Card(Card::Heart, Card::Four)))
  .WillOnce(Return(new Card(Card::Heart, Card::Five)))
  .WillOnce(Return(new Card(Card::Heart, Card::Six)))
  .WillOnce(Return(new Card(Card::Heart, Card::Seven)));
  MockGoFishUI* ui = new MockGoFishUI();
  d->createDeck();
  GoFish* game = new GoFish(ui, d);
  std::vector<Player*> players {new Player("cpu1"),
  new Player("cpu2"),
  new Player("cpu3"),
  new Player("cpu4")};
  for (Player* p : players) {
    game->addPlayer(p);
  }
  game->dealCards();
  EXPECT_EQ(5, players[0]->getHand()->size());
  EXPECT_EQ(5, players[1]->getHand()->size());
  EXPECT_EQ(5, players[2]->getHand()->size());
  EXPECT_EQ(5, players[3]->getHand()->size());
  delete game;
}

TEST(TestGoFish, HasBookTrue) {
  std::list<Card*>* hand = new std::list<Card*>();
  hand->push_back(new Card(Card::Diamond, Card::Ace));
  hand->push_back(new Card(Card::Club, Card::Ace));
  hand->push_back(new Card(Card::Spade, Card::Ace));
  hand->push_back(new Card(Card::Heart, Card::Ace));
  hand->push_back(new Card(Card::Diamond, Card::Two));
  hand->push_back(new Card(Card::Diamond, Card::Three));
  hand->push_back(new Card(Card::Diamond, Card::Four));
  MockDeck* d = new MockDeck();
  MockGoFishUI* ui = new MockGoFishUI();
  GoFish* game = new GoFish(ui, d);
  EXPECT_TRUE(game->hasBook(hand));
  for (Card* c : *hand) {
    delete c;
  }
  hand->clear();
  delete hand;
  delete game;
}

TEST(TestGoFish, HasBookFalse) {
  std::list<Card*>* hand = new std::list<Card*>();
  hand->push_back(new Card(Card::Diamond, Card::Ace));
  hand->push_back(new Card(Card::Club, Card::Two));
  hand->push_back(new Card(Card::Spade, Card::Three));
  hand->push_back(new Card(Card::Heart, Card::Four));
  hand->push_back(new Card(Card::Diamond, Card::Two));
  hand->push_back(new Card(Card::Diamond, Card::Three));
  hand->push_back(new Card(Card::Diamond, Card::Four));
  MockDeck* d = new MockDeck();
  MockGoFishUI* ui = new MockGoFishUI();
  GoFish* game = new GoFish(ui, d);
  EXPECT_FALSE(game->hasBook(hand));
  for (Card* c : *hand) {
    delete c;
  }
  hand->clear();
  delete hand;
  delete game;
}

TEST(TestGoFish, CheckIfPlayerLiveFalse) {
  std::vector<Player*> players {new Player("cpu1"), new Player("cpu2")};
  players[0]->addCard(new Card(Card::Diamond, Card::Ace));
  MockDeck* d = new MockDeck();
  EXPECT_CALL(*d, getSize())
  .Times(1)
  .WillOnce(Return(0));
  MockGoFishUI* ui = new MockGoFishUI();
  GoFish* game = new GoFish(ui, d);
  for (Player* p : players) {
    game->addPlayer(p);
  }
  EXPECT_FALSE(game->checkIfPlayerLive());
  players.clear();
  delete game;
}

TEST(TestGoFish, CheckIfPlayerLiveTrue) {
  std::vector<Player*> players {new Player("cpu1"), new Player("cpu2")};
  players[0]->addCard(new Card(Card::Diamond, Card::Ace));
  players[1]->addCard(new Card(Card::Diamond, Card::Two));
  MockDeck* d = new MockDeck();
  EXPECT_CALL(*d, getSize())
  .Times(0);
  MockGoFishUI* ui = new MockGoFishUI();
  GoFish* game = new GoFish(ui, d);
  for (Player* p : players) {
    game->addPlayer(p);
  }
  EXPECT_TRUE(game->checkIfPlayerLive());
  players.clear();
  delete game;
}

TEST(TestGoFish, BeforeAction) {
  Player* p = new Player("cpu1");
  p->addCard(new Card(Card::Diamond, Card::Ace));
  p->addCard(new Card(Card::Diamond, Card::Two));
  MockDeck* d = new MockDeck();
  MockGoFishUI* ui = new MockGoFishUI();
  Expectation displayturn =
  EXPECT_CALL(*ui, displayStartTurn(p))
  .Times(1)
  .WillOnce(Return());
  EXPECT_CALL(*ui, displayPlayerHand(p->getHand()))
  .Times(1)
  .After(displayturn)
  .WillOnce(Return());
  GoFish* game = new GoFish(ui, d);
  game->addPlayer(p);
  game->beforeAction();
  delete game;
}

TEST(TestGoFish, TakeCardTrue) {
  Player* p1 = new Player("cpu1");
  Player* p2 = new Player("cpu2");
  p1->addCard(new Card(Card::Diamond, Card::Ace));
  p1->addCard(new Card(Card::Diamond, Card::Two));
  p2->addCard(new Card(Card::Club, Card::Ace));
  MockDeck* d = new MockDeck();
  MockGoFishUI* ui = new MockGoFishUI();
  EXPECT_CALL(*ui, displayCardsTaken(_, p2, p1))
  .Times(1)
  .WillOnce(Return());
  GoFish* game = new GoFish(ui, d);
  game->takeCard("A", p2, p1);
  EXPECT_EQ(p2->getHand()->size(), 2);
  EXPECT_EQ(p1->getHand()->size(), 1);
  delete p1;
  delete p2;
  delete game;
}

TEST(TestGoFish, TakeCardFalse) {
  Player* p1 = new Player("cpu1");
  Player* p2 = new Player("cpu2");
  p1->addCard(new Card(Card::Diamond, Card::Three));
  p1->addCard(new Card(Card::Diamond, Card::Two));
  p2->addCard(new Card(Card::Club, Card::Ace));
  MockDeck* d = new MockDeck();
  MockGoFishUI* ui = new MockGoFishUI();
  EXPECT_CALL(*ui, displayCardsTaken(_, p2, p1))
  .Times(0);
  GoFish* game = new GoFish(ui, d);
  game->takeCard("A", p2, p1);
  EXPECT_EQ(p2->getHand()->size(), 1);
  EXPECT_EQ(p1->getHand()->size(), 2);
  delete p1;
  delete p2;
  delete game;
}

TEST(TestGoFish, AfterAction) {
  Player* p1 = new Player("cpu1");
  p1->addCard(new Card(Card::Diamond, Card::Ace));
  p1->addCard(new Card(Card::Club, Card::Ace));
  p1->addCard(new Card(Card::Spade, Card::Ace));
  p1->addCard(new Card(Card::Heart, Card::Ace));
  p1->addCard(new Card(Card::Diamond, Card::Two));
  p1->addCard(new Card(Card::Diamond, Card::Three));
  p1->addCard(new Card(Card::Diamond, Card::Four));
  MockDeck* d = new MockDeck();
  MockGoFishUI* ui = new MockGoFishUI();
  Expectation score =
  EXPECT_CALL(*ui, displayBookMade(p1))
  .Times(1)
  .WillOnce(Return());
  EXPECT_CALL(*ui, displayEndTurn(p1))
  .Times(1)
  .After(score)
  .WillOnce(Return());
  GoFish* game = new GoFish(ui, d);
  game->addPlayer(p1);
  game->afterAction();
  EXPECT_EQ(p1->getHand()->size(), 3);
  delete game;
}

TEST(TestGoFish, FishEmptyDeck) {
  std::list<Card*>* hand = new std::list<Card*>();
  MockDeck* d = new MockDeck();
  EXPECT_CALL(*d, getSize())
  .Times(1)
  .WillOnce(Return(0));
  MockGoFishUI* ui = new MockGoFishUI();
  EXPECT_CALL(*ui, displayGoFish(false))
  .Times(1)
  .WillOnce(Return());
  GoFish* game = new GoFish(ui, d);
  game->fish(hand);
  EXPECT_TRUE(hand->empty());
  hand->clear();
  delete hand;
  delete game;
}

TEST(TestGoFish, Fish) {
  std::list<Card*>* hand = new std::list<Card*>();
  MockDeck* d = new MockDeck();
  Expectation create =
  EXPECT_CALL(*d, createDeck())
  .Times(1)
  .WillOnce(Return());
  Expectation size =
  EXPECT_CALL(*d, getSize())
  .Times(1)
  .After(create)
  .WillOnce(Return(52));
  EXPECT_CALL(*d, drawCard())
  .Times(1)
  .After(size)
  .WillOnce(Return(new Card(Card::Diamond, Card::Ace)));
  MockGoFishUI* ui = new MockGoFishUI();
  EXPECT_CALL(*ui, displayGoFish(true))
  .Times(1)
  .WillOnce(Return());
  d->createDeck();
  GoFish* game = new GoFish(ui, d);
  game->fish(hand);
  EXPECT_EQ(hand->size(), 1);
  for (Card* c : *hand) {
    delete c;
  }
  hand->clear();
  delete hand;
  delete game;
}

TEST(TestGoFish, GameOverTrue) {
  MockDeck* d = new MockDeck();
  MockGoFishUI* ui = new MockGoFishUI();
  GoFish* game = new GoFish(ui, d);
  EXPECT_TRUE(game->gameOver());
  delete game;
}

TEST(TestGoFish, GameOverFalse) {
  MockDeck* d = new MockDeck();
  MockGoFishUI* ui = new MockGoFishUI();
  GoFish* game = new GoFish(ui, d);
  game->addPlayer(new Player("cpu1"));
  EXPECT_TRUE(!game->gameOver());
  delete game;
}

TEST(TestGoFish, AddPlayerExisting) {
  Player* p = new Player("cpu1");
  MockDeck* d = new MockDeck();
  MockGoFishUI* ui = new MockGoFishUI();
  GoFish* game = new GoFish(ui, d);
  game->addPlayer(p);
  game->addPlayer(p);
  EXPECT_EQ(game->getLivePlayers().size(), 1);
  delete game;
}

TEST(TestGoFish, GetLivePlayers) {
  MockDeck* d = new MockDeck();
  MockGoFishUI* ui = new MockGoFishUI();
  GoFish* game = new GoFish(ui, d);
  game->addPlayer(new Player("cpu1"));
  game->addPlayer(new Player("cpu2"));
  EXPECT_EQ(game->getLivePlayers().size(), 2);
  delete game;
}
