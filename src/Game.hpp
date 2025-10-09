#pragma once

#include <iostream>
#include <vector>
#include "../imgui/imgui.h"
#include "Player.hpp"

using namespace std;

class Game {
    private:
    vector<Player> players;
    int activePlayer;

    public:
    //Game() : players(0), activePlayer(0) {}
    void start(int p);
};