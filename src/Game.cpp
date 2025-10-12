#include "Game.hpp"

// game initialisation. handles player and board assignments
void Game::start(int p) {

    // clear players and add new players for player number
    players.clear();
    for (int i = 0; i < p; i++) {
        players.emplace_back("P" + std::to_string(i + 1));
    }
    playerCount = p;
    
    // clear board and add new spaces
    board.clear();
    addSpace(new Go());
    addSpace(new Property("test", "colour"));
    addSpace(new Property("test2", "colour"));
    addSpace(new Railroad("test3"));
    addSpace(new Jail());
}

// move spaces
void Game::move(int spaces) {
    static int currentPos = players[activePlayer].getPos();                 // get current position
    players[activePlayer].setPos((currentPos + spaces) % getBoardSize());   // add new spaces, modulus to wrap around the board
};