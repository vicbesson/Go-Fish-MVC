/**
* @class GoFishUI
* @brief
* This class is meant to act as the view for the game
* GoFish.
* @author $Author: Victor Besson $
*/

#ifndef GOFISHUI_H
#define GOFISHUI_H

#include "Player.h"
#include "Card.h"
#include <vector>
#include <list>
#include <string>

class GoFishUI {
 public:
  /**
  * Constructor.
  */
  GoFishUI() {}
  /**
  * Destructor.
  */
  virtual ~GoFishUI() {}
  /**
  * Message displayed at game start.
  */
  virtual void displayWelcomeMessage();
  /**
  * Displays a players hand.
  * @param hand The hand to be displayed.
  */
  virtual void displayPlayerHand(std::list<Card*>* hand);
  /**
  * Displays "Go Fish" if fishable is true
  * else says deck is empty.
  * @param fishable True if deck has cards left false otherwise.
  */
  virtual void displayGoFish(bool fishable);
  /**
  * Displays players name and displays that they made a book.
  * @param p The player used to display name.
  */
  virtual void displayBookMade(Player* p);
  /**
  * Displays and shows that it is a new players turn.
  * @param p The player used to display name.
  */
  virtual void displayStartTurn(Player* p);
  /**
  * Displays amount of cards taken and what they are.
  * @param taken The cards that were obtained
  * from another player
  * @param to Player who obtained cards.
  * @param from Player who gave cards.
  */
  virtual void displayCardsTaken(std::list<Card*> taken,
  Player* to,
  Player* from);
  /**
  * Displays and shows that the turn is over.
  * @param p The player used to display name.
  */
  virtual void displayEndTurn(Player* p);
  /**
  * Displays ending messages, names of players, and scores.
  * @param players The players used to display names and scores.
  */
  virtual void displayEndMessage(std::vector<Player*> players);
  /**
  * Returns the index of the player chosen to fish from.
  * @param players The players available to fish from.
  * @param currentPlayer Index in vector of activePlayer.
  * @return The index of the player chosen to fish from.
  */
  virtual unsigned int inputChoosePlayer(std::vector<Player*> players,
  unsigned int currentPlayer);
  /**
  * Returns the index of the card in hand that will be used
  * to ask the chosen player for.
  * @param hand The hand of cards used to choose from.
  * @return The index of the card chosen in hand.
  */
  std::string inputChooseCard(std::list<Card*>* hand);

 private:
 /**
 * Checks if a string is an unsigned integer.
 * https://stackoverflow.com/questions/4654636/how-to-determine-if-a-string-is-a-number-with-c
 * @param s The string to compare.
 * @return True if string is integer false if not.
 */
  bool is_number(const std::string& s);
  /**
  * Converts string to lower.
  * https://thispointer.com/converting-a-string-to-upper-lower-case-in-c-using-stl-boost-library/
  * @param input The string to be converted.
  * @return Converted string to lower.
  */
  std::string toLower(std::string input);
  /**
  * Converts string to upper.
  * https://thispointer.com/converting-a-string-to-upper-lower-case-in-c-using-stl-boost-library/
  * @param input The string to be converted.
  * @return Converted string to upper.
  */
  std::string toUpper(std::string input);
  /**
  * Checks if hand contains a rank, returns True if it does
  * else False if it does not.
  * @param selected The rank to check for.
  * @param hand The hand to check for rank.
  * @return True if hand contains rank, false if does not.
  */
  bool handContains(std::string selected, std::list<Card*>* hand);
};

#endif // GOFISHUI_H
