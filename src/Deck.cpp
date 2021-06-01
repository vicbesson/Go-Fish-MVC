#include <string>
#include <algorithm>
#include <random>
#include "../include/Deck.h"

Deck::~Deck() {
  for (unsigned int i = 0; i < deck.size(); i++) {
    delete deck[i];
  }
  deck.clear();
}

void Deck::createDeck() {
  for (unsigned int s = Card::Diamond; s != Card::SLast; s++) {
    for (unsigned int n = Card::Ace; n != Card::NLast; n++) {
      deck.push_back(new Card(Card::Suit(s), Card::Number(n)));
    }
  }
}

Card* Deck::drawCard() {
  Card* c = nullptr;
  if (!deck.empty()) {
    c = deck.back();
    deck.erase(deck.begin() + deck.size() - 1);
  }
  return c;
}

void Deck::addCard(Card* c) {
  if (c != nullptr) {
    deck.push_back(c);
  }
}

void Deck::shuffle() {
  std::random_device rd;
  std::mt19937 g(rd());
  std::shuffle(deck.begin(), deck.end(), g);
}
