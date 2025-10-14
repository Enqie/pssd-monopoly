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
    addSpace(new Property("Mediterranean Avenue", "purple", 60));
    // community chest
    addSpace(new Property("Baltic Avenue", "purple", 60));
    addSpace(new Tax("Income Tax", 200));
    addSpace(new Railroad("Reading Railroad", 200));
    addSpace(new Property("Oriental Avenue", "white", 100));
    addSpace(new Property("Vermont Avenue", "white", 100));
    addSpace(new Property("Conneticut Avenue", "white", 120));
    addSpace(new Jail());
    addSpace(new Property("Oriental Avenue", "pink", 100));
    addSpace(new Property("Vermont Avenue", "pink", 100));
    addSpace(new Property("Conneticut Avenue", "pink", 120));
    addSpace(new GoToJail());
}

// move spaces
void Game::move(int spaces) {
    int currentPos = players[activePlayer].getPos();        // get current position
    int newPos = (currentPos + spaces) % getBoardSize();    // get new position, modulus to wrap around the board
    players[activePlayer].setPos(newPos);                   // set position

    // call land function for a space
    Space* landedSpace = getSpace(newPos);
    landedSpace->land(&getPlayer());
};