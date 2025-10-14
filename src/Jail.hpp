#pragma once

#include <stdlib.h>

#include <ctime>
#include <iostream>
#include <unordered_map>

#include "Player.hpp"
#include "Space.hpp"
using namespace std;
/* using map so i and the game can keep track of how many turns each player has
been in jail.
- Player can either visit or be in jail
- once in jail, players can decide to either pay $50 to get out imediately
- Or they can attempt to roll a double each turn so they can escape for free.
- After 3 unsuccessful turns, they must pay $50 to get out automatically?
*/

class Jail : public Space {
 private:
  const int bailAmount = 50;  // amount required to pay
  const int maxTurns = 3;  // 3 turns a player is forced to say in jail till a
                           // double is rolled or forced payment
  unordered_map<Player*, int> jailTurns;  // track the turns

 public:
  Jail() : Space("Jail") {
    srand(time(nullptr));  // RNG for dice rolls
  }

  void land(Player* player) {
    // if player is not currently jailed, they are just visiting so return
    if (player->getJailStatus() == false) return;

    /* LOGIC FOR IN JAIL */
    // if the player's 1st time to jail
    if (jailTurns.find(player) == jailTurns.end()) {
      jailTurns[player] = 0;
    }

    // allow the player with a choice to pay or attempt to roll
    char choice;
    cout << "Pay money $" << bailAmount << "to get out now? (y/n):";
    cin >> choice;

    // optn 1 = if the player said yes to pay
    if (choice == 'y') {
      if (player->getMoney() >= bailAmount) { // checking if the player has enough money to pay for their own bail
        player->subMoney(bailAmount); // subtract bail money 
        player->setJailStatus(false); // mark as free = no longer in jail
        jailTurns.erase(player); // reset counter for how many turns
        cout << "Player paid the money to bail out\n";
      } else {  // player said no or doesnt have enough money
        cout << "Doesn't have enough money for bail.\n";
      }
      return; // given either the case, stopping the current jail turn
    }

    // optn 2= Player chooses to roll doubles
    int dice1 = rand() % 6 + 1;
    int dice2 = rand() % 6 + 1;

    // if they are same = double
    if (dice1 == dice2) { // if the values are same
      player->setJailStatus(false); // free the player = no longer in jail
      jailTurns.erase(player); // remove them from jail
    } else { // if the player failed to roll doubles, 
      jailTurns[player]++; // incrementing jail turn count
      cout << " That was not a double." << " " << jailTurns[player] << " / "
           << maxTurns << "turns used. \n";

      // after 3 turs, player now must pay the bail money      
      if (jailTurns[player] >= maxTurns) {
        cout
            << "Player has exhaused 3 turns to roll a double and must now pay $"
            << bailAmount << "to get out.\n";
        player->subMoney(bailAmount); // deduct the bail amount 
        player->setJailStatus(false); // free player = no longer in jail
        jailTurns.erase(player); // remove them jail turn record
      } else {
        cout << "player remains in jail.\n";
      }
    }
  }

  std::string getType() override { return "Jail"; }
};
