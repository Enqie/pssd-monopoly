#include "Display.hpp"

void Display::displayBoard(Game& game) {
    static int playerCount = 0;
    static bool newGame = true;

    ImGui::Begin("Board"); // create board window 

    if (newGame) ImGui::OpenPopup("New Game"); // create popup if new game.
    
    // popup modal code
    if (ImGui::BeginPopupModal("New Game", NULL, ImGuiWindowFlags_AlwaysAutoResize)) {
        ImGui::InputInt("Player Count:", &playerCount); // input field sets player count
        // new game button logic. starts game and closes popup.
        if (ImGui::Button("Start Game")) {
            if (newGame) newGame = false;
            game.start(playerCount);
            ImGui::CloseCurrentPopup();
        }
        ImGui::EndPopup();
    }

    // board window code
    ImGui::Text("Board here");

    // check if board has spaces before rendering
    if (!game.getBoardSize()) { 
        ImGui::Text("Board is empty!");
    } else {
        for (int i = 0; i < game.getBoardSize(); i++) {
            Space* space = game.getSpace(i);
            if (space) {
                ImGui::Text("Space %d: %s", i, space->getName().c_str());
            }
        }
    }

    ImGui::End();
};