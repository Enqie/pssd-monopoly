#pragma once

#include <vector>
#include "Space.hpp"

class Player; // forward declaration

class Railroad: public Space
{
private:
    // Railroad states
    bool isOwned = false;
    // bool isMortgaged = false;

    // Railroad information
    Player* owner;
    int cost;

    // private methods
    // method makes player pay rent if they do not own this railroad; returns true if player pays rent
    bool payRent(Player* player);

    // method checks if player would like to buy railroad; returns true if a player CAN buy 
    bool buyProperty(Player* player);

public:
    // constructor sets name and cost of railroad
    Railroad(std::string name, int cost): Space(name), cost(cost){
        owner = nullptr;
    }

    // getters/setters
    int getCost(){ return cost; }
    void setOwner(Player* newOwner){ owner = newOwner; }

    // override pure virtual land function
    void land(Player* player) override;
};