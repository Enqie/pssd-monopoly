#pragma once

#include <vector>
#include <memory>
#include "Player.hpp"
#include "Space.hpp"
#include "Property.hpp"
#include "Jail.hpp"
#include "Go.hpp"

using namespace std;

class Game {
    private:
    vector<unique_ptr<Space>> board;
    vector<Player> players;
    int activePlayer;

    public:
    Game() : activePlayer(0) {}; // constructor, sets activePlayer to 0
    void start(int p);

    // get and add space
    Space* getSpace(int i) { return board[i].get(); };
    void addSpace(Space* space) { board.emplace_back(space); };

    // get board size
    int getBoardSize() const { return board.size(); }
};