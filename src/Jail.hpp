#pragma once

#include <unordered_map>

#include "Player.hpp"
#include "Space.hpp"

using namespace std;

class Jail : public Space {
 private:
  const int bailAmount = 50;      // amount required to pay
  const int maxTurns = 3;         // max 3 turns to roll a double
  unordered_map<Player*, int> jailTurns;  // track the turns

 public:
  Jail() : Space("Jail") {}

  void land(Player* player) {
    // if player is not currently jailed, they are just visiting so return
    if (player->getJailStatus() == false) return;
  }

  // getters and incrementers for turns a player has been in jail
  bool canRoll(Player* player) { return jailTurns[player] < maxTurns; }   // player can roll if maxTurns hasn't been reached
  void addTurn(Player* player) { jailTurns[player] += 1; }
  int getTurns(Player* player) { return jailTurns[player]; }
  int getMaxTurns() { return maxTurns; }

  std::string getType() override { return "Jail"; }

  ImVec4 getColourVec() override { return ImVec4(0.6f, 0.0f, 0.0f, 1.0f); }
};