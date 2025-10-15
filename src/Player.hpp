#pragma once

#include <unordered_map>
#include <unordered_set>

#include "Property.hpp"
#include "Utility.hpp"
#include "Railroad.hpp"

class Game;

class Player
{
private:
    Game* game;
    std::string name;
    int position = 0;           // player starts at pos 0 (GO)
    int money = 1500;           // player starts with 1500

    // booleans for player state
    bool isInJail = false;
    bool isBankrupt = false;

    // container to store Properties/Utilities/Railroads owned by player
    std::unordered_set<Property*> ownedProperties;
    std::unordered_set<Utility*> ownedUtilities;
    std::unordered_set<Railroad*> ownedRailroads;

    // unordered map to store number of each property colours a player owns
    std::unordered_map<std::string, int> propertyColours;
public:
    Player(std::string name, Game* game): game(game), name(name){}

    // getters/setters
    std::string getName(){ return name; }
    int getMoney(){ return money; }
    std::unordered_set<Property*> getProperties(){ return ownedProperties; }
    std::unordered_set<Utility*> getUtilities(){ return ownedUtilities; }
    std::unordered_set<Railroad*> getRailroads(){ return ownedRailroads; }
    bool getJailStatus(){ return isInJail; }
    // bool getBankruptStatus(){ return isBankrupt; }
    void setJailStatus(bool status){ isInJail = status; }
    void setBankruptStatus(bool status){ isBankrupt = status; }
    int getPos(){ return position; }

    // function declarations
    bool checkBankruptcy();
    void buyProperty(Property* property);
    void buyRailroad(Railroad* railroad);
    void buyUtility(Utility* utility);

    void move(int spaces);  // move spaces
    void setPos(int pos);   // set player
    bool payBail();

    // methods to add or subtract amounts of money from player
    void addMoney(int amount){ money+=amount; }
    void subMoney(int amount){ 
        money-=amount; 
        checkBankruptcy();
    }
};