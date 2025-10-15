#include "Display.hpp"

void Display::displayBoard(Game& game) {
    // define local static vars
    static int playerCount = 2;
    static bool newGame = true;

    // define window flags
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



        // board table
        if (ImGui::BeginTable("Board", 11, ImGuiTableFlags_SizingFixedSame)) {
            static int index;
            for (int row = 0; row < 11; ++row) {
                ImGui::TableNextRow();
                for (int col = 0; col < 11; ++col) {
                    ImGui::TableNextColumn();
                    if (row == 0 || col == 0 || row == 10 || col == 10) {   // fill sides only
                        index = idx(row, col);                              // find index with helper function
                        Space* space = game.getSpace(index);

                        ImGui::PushID(index);
                        ImGui::PushStyleColor(ImGuiCol_Button, space->getColourVec());  // colour
                        ImGui::Button(space->getName().c_str(), ImVec2(60,60));
                        ImGui::PopID();
                        ImGui::PopStyleColor();
                    }
                }
            }
        }
        ImGui::EndTable();
        ImGui::End(); // end board window

        displayControls(game);  // controls window
        displayTest(game);      // test window
    }
};

void Display::displayControls(Game& game) {
    Player& player = game.getPlayer(); // get current player object

    // controls window code
    ImGui::Begin("Controls", NULL, window_flags);

    if (ImGui::Button("Next player")) game.nextTurn();

    if (!player.getJailStatus()) {
        // player is not in jail controls
        static bool rollDouble = false; // dice controls
        if (ImGui::Button("Roll Test")) rollDouble = game.rollDice();
        ImGui::Text("Roll: %i", game.getDice());
        if (rollDouble) {
            ImGui::Text("Doubles!");
        }

        if (ImGui::Button("Move")) player.move(game.getDice()); // move active player
    } else {
        // player is in jail controls
        ImGui::Text("You are in Jail!");
        ImGui::Text("Roll doubles or pay bail.");

        // pay bail
        static bool bailPaid = true;
        if (ImGui::Button("Pay Bail")) bailPaid = player.payBail();
        if (!bailPaid) ImGui::Text("Bail cannot be paid.");

        // roll double to escape
        static bool rollDouble = false;
        if (ImGui::Button("Roll")) rollDouble = game.rollDice();
        ImGui::Text("Roll: %i", game.getDice());
        if (rollDouble) {
            player.setJailStatus(false);
            game.nextTurn();
        }
    }
    ImGui::End(); // end controls window
}

void Display::displayTest(Game& game) {
    Player& player = game.getPlayer(); // get current player object
    int pos = player.getPos();
    Space* space = game.getSpace(pos);

    ImGui::Begin("Debug window");
    ImGui::Text("Players: %i, Current player: %s", game.getPlayerCount(), player.getName().c_str());
    ImGui::Text("Player Balance: %i", player.getMoney());
    ImGui::Text("Player position: %i/%i", pos, game.getBoardSize());
    ImGui::Text("Current Space: %s, Type: %s, Cost: $%i", space->getName().c_str(), space->getType().c_str(), space->getCost());

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
    ImGui::End();
}

// private board index helper
int Display::idx(int row, int col) {
    if (row == 10) return 10 - col;
    if (col == 0) return 20 - row;
    if (row == 0) return 20 + col;
    if (col == 10) return 30 + row;
    return -1;
}