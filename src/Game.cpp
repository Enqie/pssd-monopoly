#include "Game.hpp"

// game initialisation. handles player and board assignments
void Game::start(int p) {

    // clear players and add new players for player number
    players.clear();
    for (int i = 0; i < p; i++) {
        players.emplace_back("P" + std::to_string(i + 1));
    }
    
    // clear board and add new spaces
    board.clear();
    addSpace(new Property("test", "colour"));
    addSpace(new Property("test2", "colour"));
    addSpace(new Railroad("test3"));
    addSpace(new Jail());
    addSpace(new Go());
}