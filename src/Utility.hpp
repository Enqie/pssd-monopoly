#pragma once

#include <vector>
#include "Space.hpp"

class Player; // forward declaration

class Utility: public Space
{
private:
    // Utility states
    bool isOwned = false;
    // bool isMortgaged = false;

    // Utility information
    Player* owner;
    int cost;

    // private methods
    // method makes player pay rent if they do not own this utility; returns true if player pays rent
    bool payRent(Player* player, int diceRoll);

    // method checks if player would like to buy utility; returns true if a player CAN buy 
    bool buyProperty(Player* player);

public:
    // constructor sets name and cost of Utility
    Utility(std::string name, int cost): Space(name), cost(cost){
        owner = nullptr;
    }

    // getters/setters
    int getCost(){ return cost; }
    void setOwner(Player* newOwner){ owner = newOwner; }

    // override pure virtual land function
    void land(Player* player) override;
    std::string getType() override { return "Utility"; };
};