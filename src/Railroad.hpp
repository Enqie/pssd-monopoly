#pragma once

#include <vector>
#include "Space.hpp"

class Player; // forward declaration

class Railroad: public Space
{
private:
    // Railroad states
    bool isOwned = false;
    bool isMortgaged = false;

    Player* owned;

    // private methods
    // method makes player pay rent if they do not own this property; returns true if player pays rent
    bool payRent(Player* player);

    // method checks if player would like to buy property; returns true if a player CAN buy property
    bool buyProperty(Player* player);

public:
    // constructor sets name and colour of property
    Railroad(std::string name): Space(name){
        owned = nullptr;
    }

    // override pure virtual land function
    void land(Player* player) override;
};