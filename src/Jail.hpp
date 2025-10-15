#pragma once

#include <stdlib.h>

#include <ctime>
#include <iostream>
#include <unordered_map>

#include "Player.hpp"
#include "Space.hpp"
#include "Game.hpp"

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
  Jail() : Space("Jail") {}

  void land(Player* player) {
    // if player is not currently jailed, they are just visiting so return
    if (player->getJailStatus() == false) return;
  }

  std::string getType() override { return "Jail"; }
};