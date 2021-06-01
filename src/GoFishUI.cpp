#include <list>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include "../include/GoFishUI.h"

void GoFishUI::displayWelcomeMessage() {
  std::cout << "Welcome to Go Fish!" << std::endl;
}

void GoFishUI::displayPlayerHand(std::list<Card*>* hand) {
  std::cout << "Your hand:" << std::endl;
  for (std::list<Card*>::iterator hit = hand->begin();
      hit != hand->end(); ++hit) {
    if (hit != hand->end()) {
      std::cout << "("
      << (*hit)->getSuit()
      << ")"
      << (*hit)->getNumber()
      << " ";
    } else {
      std::cout << "("
      << (*hit)->getSuit()
      << ")"
      << (*hit)->getNumber();
    }
  }
  std::cout << std::endl << std::endl;
}

void GoFishUI::displayGoFish(bool fishable) {
  if (fishable) {
    std::cout << "Go Fish!" << std::endl << std::endl;
  } else {
    std::cout << "The deck is empty!" << std::endl << std::endl;
  }
}

void GoFishUI::displayBookMade(Player* p) {
  std::cout << p->getName()
  << " has made a book!"
  << std::endl << std::endl;
}

void GoFishUI::displayStartTurn(Player* p) {
  std::cout << p->getName()
  << "'s turn:"
  << std::endl << std::endl;
}

void GoFishUI::displayCardsTaken(
std::list<Card*> taken,
Player* to,
Player*from) {
  std::cout << to->getName()
  << " has obtained ";
  for (std::list<Card*>::iterator hit = taken.begin();
      hit != taken.end(); ++hit) {
    std::cout << "("
    << (*hit)->getSuit()
    << ")"
    << (*hit)->getNumber()
    << " ";
  }
  std::cout << "from "
  << from->getName()
  << std::endl << std::endl;
}

void GoFishUI::displayEndTurn(Player* p) {
  std::cout
  << p->getName()
  << "'s turn has ended."
  << std::endl << std::endl;
}

void GoFishUI::displayEndMessage(std::vector<Player*> players) {
  std::cout << "Game Over! Here are the numbers:" << std::endl;
  unsigned int count = 0;
  for (Player* p : players) {
    count++;
    std::cout << std::to_string(count)
    << ". "
    << p->getName()
    << " - "
    << p->getScore()
    << std::endl;
  }
}

unsigned int GoFishUI::inputChoosePlayer(
std::vector<Player*> players, unsigned int currentPlayer) {
  unsigned int selected;
  bool valid;
  std::string command;
  unsigned int index = 0;
  std::cout << "Choose the player number you want to take from:"
  << std::endl;
  for (Player* p : players) {
    index++;
    if ((index - 1) != currentPlayer) {
      std::cout << std::to_string(index)
      << " - "
      << p->getName()
      << std::endl;
    }
  }
  do {
    valid = true;
    command.clear();
    std::cout << ">>";
    getline(std::cin, command);
    if (is_number(command)) {
      selected = std::stoi(command);
      if (selected < 1 || selected > index
      || (selected - 1) == currentPlayer) {
        std::cerr << "Not a valid player number. "
        << "Please try again." << std::endl;
        valid = false;
      }
    } else {
      std::cerr << "Not a valid number. "
      << "Please try again." << std::endl;
      valid = false;
    }
  } while (valid == false);
  std::cout << std::endl;
  return selected - 1;
}

std::string GoFishUI::inputChooseCard(std::list<Card*>* hand) {
  std::string command;
  bool valid;
  std::cout << "Choose a rank from a card in your hand:"
  << std::endl;
  do {
    valid = true;
    command.clear();
    std::cout << ">>";
    getline(std::cin, command);
    if (!handContains(command, hand)) {
      std::cerr << "You currently do not have this rank. "
      << "Please try again." << std::endl;
      valid = false;
    }
  } while (valid == false);
  std::cout << std::endl;
  return toUpper(command);
}

bool GoFishUI::handContains(const std::string selected,
std::list<Card*>* hand) {
  for (std::list<Card*>::iterator hit = hand->begin();
      hit != hand->end(); ++hit) {
    if (toLower((*hit)->getNumber()) == toLower(selected)) {
      return true;
    }
  }
  return false;
}

bool GoFishUI::is_number(const std::string& s) {
  return !s.empty() && std::find_if(s.begin(),
   s.end(), [](unsigned char c) {
       return !std::isdigit(c);
  }) == s.end();
}

std::string GoFishUI::toLower(std::string input) {
    // convert string to lower case
    std::for_each(input.begin(), input.end(), [](char & c) {
        c = ::tolower(c);
    });
    return input;
}

std::string GoFishUI::toUpper(std::string input) {
    // convert string to upper case
    std::for_each(input.begin(), input.end(), [](char& c) {
        c = ::toupper(c);
        });
    return input;
}
