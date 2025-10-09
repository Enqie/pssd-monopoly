#pragma once

#include <unordered_map>
#include <unordered_set>
#include <stdlib.h>

#include "Property.hpp"
#include "Utility.hpp"
#include "Railroad.hpp"

class Player
{
private:
    std::string name;
    int position = 0;           // player starts at pos 0 (GO)
    int money = 1500;           // player starts with 1500

    // Player has 2 dice
    int dice1;
    int dice2;

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
    Player(std::string name): name(name){}

    // getters/setters
    std::string getName(){ return name; }
    int getMoney(){ return money; }
    std::unordered_set<Property*> getProperties(){ return ownedProperties; }
    std::unordered_set<Utility*> getUtilities(){ return ownedUtilities; }
    std::unordered_set<Railroad*> getRailroads(){ return ownedRailroads; }
    bool getJailStatus(){ return isInJail; }
    int getDiceRoll(){ return dice1+dice2; }
    // bool getBankruptStatus(){ return isBankrupt; }
    void setJailStatus(bool status){ isInJail = status; }
    void setBankruptStatus(bool status){ isBankrupt = status; }
    int getPos(){ return position; }
    void setPos(int pos){ position = pos; }

    // function declarations
    int rollDice();
    bool checkBankruptcy();
    void buyProperty(Property* property);

    // methods to add or subtract amounts of money from player
    void addMoney(int amount){ money+=amount; }
    void subMoney(int amount){ 
        money-=amount; 
        checkBankruptcy();
    }
};