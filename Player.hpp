#pragma once

#include <unordered_map>
#include <unordered_set>

#include "Property.hpp"

class Player
{
private:
    std::string name;

    int money = 1500;           // player starts with 1500

    // booleans for player state
    bool isInJail = false;
    bool isBankrupt = false;

    // container to store Properties owned by player
    std::unordered_set<Property*> ownedProperties;

    // unordered map to store number of each property colours a player owns
    std::unordered_map<std::string, int> propertyColours;
public:
    Player(std::string name): name(name){}

    // getters/setters
    std::string getName(){ return name; }
    int getMoney(){ return money; }
    std::unordered_set<Property*> getProperties(){ return ownedProperties; }
    void setMoney(int newAmount){ money = newAmount; }

    // money functions
    void addMoney(int amount){ money+=amount; }
    void subMoney(int amount){ money-=amount; }
};