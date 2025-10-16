#pragma once

#include <vector>
#include <memory>
#include "Player.hpp"
#include "Space.hpp"
#include "Utility.hpp"
#include "FreeParking.hpp"
#include "Property.hpp"
#include "Jail.hpp"
#include "Go.hpp"
#include "GoToJail.hpp"
#include "Tax.hpp"

using namespace std;

class Game {
    private:
    vector<unique_ptr<Space>> board;
    vector<Player> players;
    int activePlayer;
    int playerCount;
    int roll;

    public:
    Game() : activePlayer(0), playerCount(0), roll(0) {} // constructor, initialises ints
    void start(int p);

    // get and add space
    Space* getSpace(int i) { return board[i].get(); }
    void addSpace(Space* space) { board.emplace_back(space); }

    // get board size
    int getBoardSize() { return board.size(); }

    // player getters
    Player& getPlayer() { return players[activePlayer]; }
    vector<Player>& getPlayerVec() { return players; }
    int getPlayerCount() { return playerCount; }

    void nextTurn() { activePlayer = (activePlayer + 1) % playerCount; }

    // dice functions
    bool rollDice() {
        int dice1 = rand() % 6 + 1;
        int dice2 = rand() % 6 + 1;
        roll = dice1 + dice2;
        if (dice1 == dice2) return true;
        return false;
    }
    int getDice() { return roll; }
};