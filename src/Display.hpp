#pragma once

#include "../imgui/imgui.h"
#include "Game.hpp"
#include "Player.hpp"

class Display {
    private:
    ImGuiWindowFlags window_flags = 0;
    int idx(int row, int col);
    public:
    void displayBoard(Game& game);
    void displayTest(Game& game);
    void displayControls(Game& game);
};