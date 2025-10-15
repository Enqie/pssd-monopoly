#include "Game.hpp"

// game initialisation. handles player and board assignments
void Game::start(int p) {

    // clear players and add new players for player number
    players.clear();
    for (int i = 0; i < p; i++) {
        players.emplace_back("P" + std::to_string(i + 1), this);
    }
    playerCount = p;
    
    // clear board and add new spaces
    board.clear();
    addSpace(new Go());
    addSpace(new Property("Mediterranean Avenue", "purple", 60));
    addSpace(new Tax("Community Chest", 200));
    addSpace(new Property("Baltic Avenue", "purple", 60));
    addSpace(new Tax("Income Tax", 200));
    addSpace(new Railroad("Reading Railroad", 200));
    addSpace(new Property("Oriental Avenue", "white", 100));
    addSpace(new Tax("Chance", 200));
    addSpace(new Property("Vermont Avenue", "white", 100));
    addSpace(new Property("Conneticut Avenue", "white", 120));
    addSpace(new Jail());
    addSpace(new Property("St. Charles Place", "pink", 140));
    addSpace(new Utility("Electric Company", 150));
    addSpace(new Property("States Avenue", "pink", 140));
    addSpace(new Property("Virginia Avenue", "pink", 160));
    addSpace(new Railroad("Pennsylvania Railroad", 200));
    addSpace(new Property("St. James Place", "orange", 180));
    addSpace(new Tax("Community Chest", 200));
    addSpace(new Property("Tennessee Avenue", "orange", 180));
    addSpace(new Property("New York Avenue", "orange", 200));
    addSpace(new FreeParking("Free Parking"));
    addSpace(new Property("Kentucky Avenue", "red", 220));
    addSpace(new Tax("Chance", 200));
    addSpace(new Property("Indiana Avenue", "red", 220));
    addSpace(new Property("Illinois Avenue", "red", 240));
    addSpace(new Railroad("B. & O. Railroad", 200));
    addSpace(new Property("Atlantic Avenue", "yellow", 260));
    addSpace(new Property("Ventnor Avenue", "yellow", 260));
    addSpace(new Utility("Water Works", 150));
    addSpace(new Property("Marvin Gardens", "yellow", 280));
    addSpace(new GoToJail());
    addSpace(new Property("Pacific Avenue", "green", 300));
    addSpace(new Property("North Carolina Avenue", "green", 300));
    addSpace(new Tax("Community Chest", 200));
    addSpace(new Property("Pennsylvania Avenue", "green", 320));
    addSpace(new Railroad("Short Line", 200));
    addSpace(new Tax("Chance", 200));
    addSpace(new Property("Park Place", "blue", 350));
    addSpace(new Tax("Income Tax", 200));
    addSpace(new Property("Boardwalk", "blue", 400));
}