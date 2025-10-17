#pragma once

#include "../imgui/imgui.h"
#include "Game.hpp"
#include "Player.hpp"

class Display {
    private:
    ImGuiWindowFlags window_flags = 0;
    int selected = -1;

    int idx(int row, int col);

    // individual window functions, called within displayBoard
    void displayTest(Game& game);
    void displayControls(Game& game);
    void displaySpaceInfo(Game& game);

    public:
    void displayBoard(Game& game);  // main display function
};