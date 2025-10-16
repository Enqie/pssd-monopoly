#include "Game.hpp"

// game initialisation. handles player and board assignments
void Game::start(int p) {
    srand(time(nullptr));  // RNG for dice rolls

    // clear players and add new players for player number
    players.clear();
    for (int i = 0; i < p; i++) {
        players.emplace_back("P" + std::to_string(i + 1), this);
    }
    playerCount = p;
    
    // clear board and add new spaces
    board.clear();
    addSpace(new Go());
    addSpace(new Property("Mediterranean Avenue", "purple", 60, 50, {2,10,30,90,250}));
    addSpace(new Tax("Community Chest", 200));
    addSpace(new Property("Baltic Avenue", "purple", 60, 50, {4,20,60,180,450}));
    addSpace(new Tax("Income Tax", 200));
    addSpace(new Railroad("Reading Railroad", 200));
    addSpace(new Property("Oriental Avenue", "white", 100, 50, {6,30,90,270,550}));
    addSpace(new Tax("Chance", 200));
    addSpace(new Property("Vermont Avenue", "white", 100, 50, {6,30,90,270,550}));
    addSpace(new Property("Conneticut Avenue", "white", 120, 50, {8,40,100,300,600}));
    addSpace(new Jail());
    addSpace(new Property("St. Charles Place", "pink", 140, 100, {10,50,150,450,750}));
    addSpace(new Utility("Electric Company", 150));
    addSpace(new Property("States Avenue", "pink", 140, 100, {10,50,150,450,750}));
    addSpace(new Property("Virginia Avenue", "pink", 160, 100, {12,60,180,500,900}));
    addSpace(new Railroad("Pennsylvania Railroad", 200));
    addSpace(new Property("St. James Place", "orange", 180, 100, {14,70,200,550,950}));
    addSpace(new Tax("Community Chest", 200));
    addSpace(new Property("Tennessee Avenue", "orange", 180, 100, {14,70,200,550,950}));
    addSpace(new Property("New York Avenue", "orange", 200, 100, {16,80,220,600,1000}));
    addSpace(new FreeParking("Free Parking"));
    addSpace(new Property("Kentucky Avenue", "red", 220, 150, {18,90,250,700,1050}));
    addSpace(new Tax("Chance", 200));
    addSpace(new Property("Indiana Avenue", "red", 220, 150, {18,90,250,700,1050}));
    addSpace(new Property("Illinois Avenue", "red", 240, 150, {20,100,300,750,1100}));
    addSpace(new Railroad("B. & O. Railroad", 200));
    addSpace(new Property("Atlantic Avenue", "yellow", 260, 150, {22,110,330,800,1150}));
    addSpace(new Property("Ventnor Avenue", "yellow", 260, 150, {22,110,330,800,1150}));
    addSpace(new Utility("Water Works", 150));
    addSpace(new Property("Marvin Gardens", "yellow", 280, 150, {24,120,360,850,1200}));
    addSpace(new GoToJail());
    addSpace(new Property("Pacific Avenue", "green", 300, 200, {26,130,390,900,1275}));
    addSpace(new Property("North Carolina Avenue", "green", 300, 200, {26,130,390,900,1275}));
    addSpace(new Tax("Community Chest", 200));
    addSpace(new Property("Pennsylvania Avenue", "green", 320, 200, {28,150,450,1000,1400}));
    addSpace(new Railroad("Short Line", 200));
    addSpace(new Tax("Chance", 200));
    addSpace(new Property("Park Place", "blue", 350, 200, {35,175,500,1100,1500}));
    addSpace(new Tax("Luxury Tax", 75));
    addSpace(new Property("Boardwalk", "blue", 400, 200, {50,200,600,1400,2000}));
}