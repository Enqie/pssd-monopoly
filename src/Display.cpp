#include "Display.hpp"

void Display::displayBoard(Game& game) {
    // define local static vars
    static int playerCount = 2;
    static bool newGame = true;

    ImGui::Begin("Board"); // create board window 

    if (newGame) ImGui::OpenPopup("New Game"); // create popup if new game.
    
    // popup modal code
    if (ImGui::BeginPopupModal("New Game", NULL, ImGuiWindowFlags_AlwaysAutoResize)) {
        ImGui::SliderInt("players.", &playerCount, 2, 4); // input field sets player count
        // new game button logic. starts game and closes popup.
        if (ImGui::Button("Start Game")) {
            if (newGame) newGame = false;
            if (playerCount >= 2 && playerCount <= 4) { // check player count before calling start
                game.start(playerCount);
                ImGui::CloseCurrentPopup();
            }
        }
        ImGui::EndPopup();
    }

    // board window code
    ImGui::Text("Board here");
    ImGui::Text("Players: %i, Current player: %i", game.getPlayerCount(), game.getPlayer());

    // check if board has spaces before rendering them
    if (!game.getBoardSize()) { 
        ImGui::Text("Board is empty!");
    } else {
        for (int i = 0; i < game.getBoardSize(); i++) { // TODO: actually render the board
            Space* space = game.getSpace(i);
            if (space) {
                ImGui::Text("Space %d: %s", i, space->getName().c_str());
            }
        }
    }
    ImGui::End(); // end board window


    // controls window code
    ImGui::Begin("Controls");
    if (ImGui::Button("Next player")) { // next player
        game.nextTurn();
    }

    static bool rollDouble = false; // dice controls
    if (ImGui::Button("Roll Test")) rollDouble = game.rollDice();
    ImGui::Text("Roll: %i", game.getDice());
    if (rollDouble) {
        ImGui::Text("Doubles!");
    }

    ImGui::End(); // end controls window
};