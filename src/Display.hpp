#pragma once

#include "../imgui/imgui.h"
#include "Game.hpp"

class Display {
    public:
    void displayBoard(Game& game) {
        static int playerCount = 0;
        static bool newGame = true;

        ImGui::Begin("Board");

        if (newGame) ImGui::OpenPopup("New Game");
        
        ImGui::Text("Board here");
        
        if (ImGui::BeginPopupModal("New Game", NULL, ImGuiWindowFlags_AlwaysAutoResize)) {
            ImGui::InputInt("Player Count:", &playerCount);
            if (ImGui::Button("Start Game")) {
                if (newGame) newGame = false;
                game.start(playerCount);
                ImGui::CloseCurrentPopup();
            }
            ImGui::EndPopup();
        }
        ImGui::End();
    };
};