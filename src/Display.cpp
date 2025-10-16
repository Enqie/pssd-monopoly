#include "Display.hpp"

// main board window function. calls other windows
void Display::displayBoard(Game& game) {
    // define local static vars
    static int playerCount = 2;
    static bool newGame = true;

    // ImGui styling
    ImGuiStyle& style = ImGui::GetStyle();
    style.FrameBorderSize = 1.0f;
    style.CellPadding = ImVec2(0, 0);
    style.FontSizeBase = 11;

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

        // board rendering
        if (ImGui::BeginTable("Board", 11, ImGuiTableFlags_SizingFixedSame)) {
            vector<Player>& players = game.getPlayerVec();     // get current player object
            static int index;
            for (int row = 0; row < 11; ++row) {    // board create loop
                ImGui::TableNextRow();
                for (int col = 0; col < 11; ++col) {
                    ImGui::TableNextColumn();
                    if (row == 0 || col == 0 || row == 10 || col == 10) {   // fill sides only
                        index = idx(row, col);                              // find index with helper function
                        Space* space = game.getSpace(index);

                        ImGui::PushID(index);
                        ImGui::PushStyleColor(ImGuiCol_Button, space->getColourVec());  // colour

                        if (ImGui::Button("", ImVec2(70,70))) {   // when clicked, update selected square to display on info window
                            selected = index;
                        }

                        // get min and max coordinate of the most recently rendered item
                        ImVec2 min = ImGui::GetItemRectMin();
                        ImVec2 max = ImGui::GetItemRectMax();
                        int offset = 4;

                        // text wrapping
                        float padding = 4.0f;
                        ImGui::SetCursorScreenPos(ImVec2(min.x + padding, min.y + padding));
                        ImGui::PushTextWrapPos(max.x - padding);
                        ImGui::TextWrapped(space->getName().c_str());
                        ImGui::PopTextWrapPos();

                        for (Player& player : players) {                        // overlay players onto the board
                            if (index == player.getPos()) {
                                ImU32 colour = IM_COL32(255, 255, 255, 255);    // default player colour
                                if (&game.getPlayer() == &player) {             // colour the selected player
                                    colour = IM_COL32(0, 255, 255, 255);
                                }
                                ImGui::GetWindowDrawList()->AddText(            // add text overlay to the window
                                    ImVec2(min.x + offset, max.y - 18),
                                    colour,
                                    player.getName().c_str()
                                );
                                offset += 16;
                            }
                        }

                        ImGui::PopID();
                        ImGui::PopStyleColor();
                    }
                }
            }
        }
        ImGui::EndTable();
        ImGui::End(); // end board window

        displayControls(game);       // call controls window
        displaySpaceInfo(game);      // call game space information window
        displayTest(game);           // call test window

        // ImGui Demo window
        bool show_demo_window = true;
        if (show_demo_window)
            ImGui::ShowDemoWindow(&show_demo_window);
    }
};

// controls window function
void Display::displayControls(Game& game) {
    Player& player = game.getPlayer(); // get current player object

    // controls window code
    ImGui::Begin("Controls", NULL, window_flags);

    //ImGui::SetWindowFontScale(1.36f);    // set font scale

    ImGui::Text("%s's Turn!", player.getName().c_str());
    ImGui::SameLine();
    ImGui::Text("Balance: $%i", player.getMoney());

    if (!player.getJailStatus()) {
        // player is not in jail controls
        static bool rollDouble = false;         // dice controls
        ImGui::BeginDisabled(game.getDice());   // only allow one roll
        if (ImGui::Button("Roll Dice")) rollDouble = game.rollDice();
        ImGui::EndDisabled();
        ImGui::Text("Roll: %i", game.getDice());
        if (rollDouble) {
            ImGui::Text("Doubles!");
        }
        ImGui::BeginDisabled(!player.canMove());    // disable button if player can't move
        if (ImGui::Button("Move")) {
            player.move(game.getDice());            // move active player
            selected = player.getPos();             // set selected square
        }
        ImGui::EndDisabled();

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
        ImGui::BeginDisabled(game.getDice());
        if (ImGui::Button("Roll")) rollDouble = game.rollDice();
        ImGui::Text("Roll: %i", game.getDice());

        if (rollDouble) {
            player.setJailStatus(false);
            game.nextTurn();
        }
        ImGui::EndDisabled();
    }

    if (ImGui::Button("End turn")) game.nextTurn();  // next player button

    ImGui::End(); // end controls window
}

// test/debug window function
void Display::displayTest(Game& game) {
    Player& player = game.getPlayer(); // get current player object
    int pos = player.getPos();
    Space* space = game.getSpace(pos);

    // debug information rendering
    ImGui::Begin("Debug window");
    
    static int moveTo = 0;
    ImGui::InputInt("moveto", &moveTo);
    ImGui::SameLine();
    if (ImGui::Button("Set Position")) player.setPos(moveTo);

    ImGui::Text("Players: %i, Current player: %s, Move: %i", game.getPlayerCount(), player.getName().c_str(), player.canMove());
    ImGui::Text("Player Balance: $%i", player.getMoney());
    ImGui::Text("Player position: %i/%i", pos, game.getBoardSize());
    ImGui::Text("Current Space: %s, Type: %s, Cost: $%i", space->getName().c_str(), space->getType().c_str(), space->getCost());

    // check if board has spaces before rendering them
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
}

// space information window function
void Display::displaySpaceInfo(Game& game) {
    ImGui::Begin("Space Information", NULL, window_flags);
    if (selected != -1) {
        // get space object
        Space* currentSpace = game.getSpace(selected);

        // render space details
        ImGui::Text("%s", currentSpace->getName().c_str());

        ImGui::Text("Colour:");
        ImGui::SameLine();
        ImGui::PushStyleColor(ImGuiCol_Text, currentSpace->getColourVec());
        ImGui::Text("%s", currentSpace->getColour().c_str());
        ImGui::PopStyleColor();

        ImGui::Text("Type: %s", currentSpace->getType().c_str());

    } else ImGui::Text("Please select a space");
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