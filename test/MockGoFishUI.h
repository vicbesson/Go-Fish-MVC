#ifndef MOCKGOFISHUI_H_INCLUDED
#define MOCKGOFISHUI_H_INCLUDED

#include <list>
#include <vector>
#include <string>
#include "../include/GoFishUI.h"
#include "../include/Player.h"
#include "../include/Card.h"
#include "gmock/gmock.h"

class MockGoFishUI : public GoFishUI {
 public:
  explicit MockGoFishUI() {}
  virtual ~MockGoFishUI() {}
  MOCK_METHOD0(displayWelcomeMessage, void());
  MOCK_METHOD1(displayPlayerHand, void(std::list<Card*>*));
  MOCK_METHOD1(displayGoFish, void(bool));
  MOCK_METHOD1(displayBookMade, void(Player*));
  MOCK_METHOD1(displayStartTurn, void(Player*));
  MOCK_METHOD1(displayEndTurn, void(Player*));
  MOCK_METHOD3(displayCardsTaken, void(std::list<Card*>, Player*, Player*));
  MOCK_METHOD1(displayEndMessage, void(std::vector<Player*>));
  MOCK_METHOD2(inputChoosePlayer,
  unsigned int(std::vector<Player*>, unsigned int));
  MOCK_METHOD1(inputChooseCard, std::string(std::list<Card*>*));
};

#endif //MOCKGOFISHUI_H_INCLUDED
