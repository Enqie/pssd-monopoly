#pragma once

#include <unordered_map>
#include <unordered_set>

#include "Property.hpp"

class Player
{
private:
    std::string name;

    // container to store Properties owned by player
    std::unordered_set<Property*> ownedProperties;

    // unordered map to store number of each property colours a player owns
    std::unordered_map<std::string, int> propertyColours;
public:
    Player(std::string name): name(name){}

    std::string getName(){ return name; }
    std::unordered_set<Property*> getProperties(){ return ownedProperties; }
};