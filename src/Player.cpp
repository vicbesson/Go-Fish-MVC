#include <list>
#include "../include/Player.h"

Player::~Player() {
  for (Card* c : hand) {
    delete c;
  }
  hand.clear();
}

void Player::addCard(Card* c) {
  if (c != nullptr)
    hand.push_back(c);
}

Card* Player::removeCard(unsigned int index) {
  Card* c = nullptr;
  if (index < hand.size()) {
    std::list<Card*>::iterator cit = hand.begin();
    std::advance(cit, index);
    c = *cit;
    hand.remove(c);
  }
  return c;
}
