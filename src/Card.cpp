#include <string>
#include "../include/Card.h"

std::string Card::getSuit() {
  switch (suit) {
    case Diamond:
      return "D";
    case Heart:
      return "H";
    case Club:
      return "C";
    case Spade:
      return "S";
  }
  return "?";
}

std::string Card::getNumber() {
  switch (number) {
    case Ace:
      return "A";
    case Two:
      return "2";
    case Three:
      return "3";
    case Four:
      return "4";
    case Five:
      return "5";
    case Six:
      return "6";
    case Seven:
      return "7";
    case Eight:
      return "8";
    case Nine:
      return "9";
    case Ten:
      return "10";
    case Jack:
      return "J";
    case Queen:
      return "Q";
    case King:
      return "K";
  }
  return "?";
}
