#include "Display.hpp"

void Display::displayBoard(Game& game) {
    // define local static vars
    static int playerCount = 2;
    static bool newGame = true;

    // define window flags
    ImGuiWindowFlags window_flags = 0;
    window_flags |= ImGuiWindowFlags_NoTitleBar;
    window_flags |= ImGuiWindowFlags_NoResize;
    window_flags |= ImGuiWindowFlags_NoMove;
    window_flags |= ImGuiWindowFlags_NoBringToFrontOnFocus;

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

    if (!newGame) {
        ImGui::Begin("Board", NULL, window_flags); // create board window 

        // board window code
        ImGui::Text("Board here");

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

        Player& player = game.getPlayer(); // get current player object

        // controls window code
        ImGui::Begin("Controls", NULL, window_flags);
        if (ImGui::Button("Next player")) { // next player
            game.nextTurn();
        }

        static bool rollDouble = false; // dice controls
        if (ImGui::Button("Roll Test")) rollDouble = game.rollDice();
        ImGui::Text("Roll: %i", game.getDice());
        if (rollDouble) {
            ImGui::Text("Doubles!");
        }

        if (ImGui::Button("Move")) player.move(game.getDice()); // move active player
        ImGui::End(); // end controls window

        displayTest(game); // test window
    }
};

void Display::displayTest(Game& game) {
    Player& player = game.getPlayer(); // get current player object
    int pos = player.getPos();
    Space* space = game.getSpace(pos);

    ImGui::Begin("Debug window");
    ImGui::Text("Players: %i, Current player: %s", game.getPlayerCount(), player.getName().c_str());
    ImGui::Text("Player Balance: %i", player.getMoney());
    ImGui::Text("Player position: %i/%i", pos, game.getBoardSize());
    ImGui::Text("Current Space: %s, Type: %s, Cost: $%i", space->getName().c_str(), space->getType().c_str(), space->getCost());
    ImGui::End();
}