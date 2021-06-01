#include <list>
#include <vector>
#include <string>
#include "../include/GoFish.h"

GoFish::~GoFish() {
  for (unsigned int i = 0; i < livePlayers.size(); i++) {
    delete livePlayers[i];
  }
  livePlayers.clear();
  for (unsigned int i = 0; i < deadPlayers.size(); i++) {
    delete deadPlayers[i];
  }
  deadPlayers.clear();
  delete ui;
  delete deck;
}

void GoFish::dealCards() {
  if (livePlayers.size() <= 3) {
    for (unsigned int i = 0; i < 7; i++) {
      for (Player* p : livePlayers) {
        p->addCard(deck->drawCard());
      }
    }
  } else {
    for (unsigned int i = 0; i < 5; i++) {
      for (Player* p : livePlayers) {
        p->addCard(deck->drawCard());
      }
    }
  }
  for (Player* p : livePlayers) {
    if (hasBook(p->getHand())) { //Missing coverage
      ui->displayBookMade(p);
    }
  }
}

void GoFish::addPlayer(Player* p) {
  for (Player* i : livePlayers) {
    if (p == i) {
      return;
    }
  }
  livePlayers.push_back(p);
}

void GoFish::start() { //Missing coverage, has io.
  ui->displayWelcomeMessage();
  deck->createDeck();
  deck->shuffle();
  dealCards();
  unsigned int choosenPlayer;
  std::string choosenCard;
  do {
    do {
      beforeAction();
      if (!livePlayers[activePlayer]->getHand()->empty()) {
        choosenPlayer = ui
            ->inputChoosePlayer(livePlayers, activePlayer);
        choosenCard = ui
            ->inputChooseCard(livePlayers[activePlayer]->getHand());
        if (takeCard(choosenCard, livePlayers[activePlayer],
            livePlayers[choosenPlayer])) {
          turnOver = false;
        } else {
          fish(livePlayers[activePlayer]->getHand());
        }
      } else {
        fish(livePlayers[activePlayer]->getHand());
      }
      afterAction();
    } while (turnOver == false);
  } while (gameOver() == false);
  ui->displayEndMessage(deadPlayers);
}

bool GoFish::hasBook(std::list<Card*>* hand) {
  std::list<Card*> remove;
  for (std::list<Card*>::iterator cit = hand->begin();
      cit != hand->end(); ++cit ) {
    remove.clear();
    unsigned int count = 0;
    for (std::list<Card*>::iterator hit = hand->begin();
        hit != hand->end(); ++hit) {
      if ((*cit)->getNumber() == (*hit)->getNumber()) {
        count++;
        remove.push_back(*hit);
      }
    }
    if (count == 4) {
      for (std::list<Card*>::iterator rit = remove.begin();
          rit != remove.end(); ++rit) {
        Card* c = *rit;
        hand->remove(*rit);
        delete c;
      }
      return true;
    }
  }
  return false;
}

bool GoFish::checkIfPlayerLive() {
  for (std::vector<Player*>::iterator pit = livePlayers.begin();
      pit != livePlayers.end(); ++pit) {
    if ((*pit)->getHand()->size() == 0 && deck->getSize() == 0) {
      deadPlayers.push_back(*pit);
      pit = livePlayers.erase(pit);
      return false;
    }
  }
  return true;
}

void GoFish::beforeAction() {
  turnOver = true;
  ui->displayStartTurn(livePlayers[activePlayer]);
  ui->displayPlayerHand(livePlayers[activePlayer]
    ->getHand());
}

bool GoFish::takeCard(const std::string choosenCard,
Player* to, Player* from) {
  std::list<Card*>* fromHand = from->getHand();
  std::list<Card*>* toHand = to->getHand();
  std::list<Card*> taken;
  bool done = false;
  for (std::list<Card*>::iterator hit = fromHand->begin();
      hit != fromHand->end(); ++hit) {
    if ((*hit)->getNumber() == choosenCard) {
      toHand->push_back(*hit);
      taken.push_back(*hit);
      hit = fromHand->erase(hit);
      if (hit != fromHand->begin()) { //Missing coverage (bandaid)
        --hit;
      }
      done = true;
      if (fromHand->empty()) { //Missing coverage (bandaid)
        break;
      }
    }
  }
  if (!taken.empty()) {
    ui->displayCardsTaken(taken, to, from);
  }
  return done;
}

void GoFish::afterAction() {
  if (hasBook(livePlayers[activePlayer]->getHand())) {
    livePlayers[activePlayer]
    ->setScore(livePlayers[activePlayer]->getScore() + 1);
    ui->displayBookMade(livePlayers[activePlayer]);
  }
  while (!checkIfPlayerLive()) {}
  if (turnOver && !livePlayers.empty()) {
    ui->displayEndTurn(livePlayers[activePlayer]);
    activePlayer++;
    activePlayer = activePlayer % livePlayers.size();
    if (activePlayer >= livePlayers.size()) { //Missing coverage (bandaid)
      activePlayer = livePlayers.size() - 1;
    }
  }
}

void GoFish::fish(std::list<Card*>* hand) {
  if (deck->getSize() > 0) {
    ui->displayGoFish(true);
    hand->push_back(deck->drawCard());
  } else {
    ui->displayGoFish(false);
  }
}

bool GoFish::gameOver() {
  if (livePlayers.size() == 0) {
    return true;
  }
  return false;
}
