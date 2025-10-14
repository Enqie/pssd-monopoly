#pragma once

#include "../imgui/imgui.h"
#include "Game.hpp"
#include "Player.hpp"

class Display {
    public:
    void displayBoard(Game& game);
    void displayTest(Game& game);
};