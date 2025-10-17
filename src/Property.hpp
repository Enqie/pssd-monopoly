#pragma once

#include <vector>
#include "Space.hpp"

class Player; 

class Property: public Space
{
private:
    // Property states
    bool isOwned = false;

    // Property information
    Player* owner;
    std::string colour;                 // colour group of property
    int cost;                           // cost of the land title
    int houseCost;
    std::vector<int> rentPrice;         // cost of rent with respective amount of houses/hotels
    int rent;                           // current rent
    int numHouses = 0;                  // number of houses/hotels owned by player

public:
    // constructor sets name and colour of property
    Property(std::string name, std::string colour, int cost, int house, std::vector<int> rents): Space(name), colour(colour), cost(cost) {
        owner = nullptr;
        houseCost = house;
        rentPrice = rents;
        rent = rentPrice[0];    // initialise rent price
    }

    // getters/setters
    void setOwner(Player* newOwner){ owner = newOwner; }
    void setNotOwned();     // reset Property ownership 
    
    // method makes player pay rent if they do not own this property; returns true if player pays rent
    void payRent(Player* player);

    // public buy functions
    bool canBuyHouse(Player* player);
    void buyHouse(Player* player);
    int getHouseNum(){ return numHouses; }

    // overrides for Space functions
    bool canBuy() override;
    void buy(Player* player) override;
    Player* getOwner() override { return owner; }

    // override pure virtual functions
    void land(Player* player) override;
    std::string getType() override { return "Property"; };

    int getCost() override { return cost; }

    // get colours
    ImVec4 getColourVec() override;
    std::string getColour() override { return colour; }
};