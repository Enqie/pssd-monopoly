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
    std::vector<int> propertyCost;      // cost to buy property/houses/hotels 
    std::vector<int> rentPrice;         // cost of rent with respective amount of houses/hotels
    int rent;                           // current rent
    int numHouses = 0;                  // number of houses/hotels owned by player

    // private methods
    // method makes player pay rent if they do not own this property; returns true if player pays rent
    bool payRent(Player* player);

    // method checks if player would like to buy house/hotel on property; returns true if player CAN buy house
    bool buyHouse(Player* player);

    // method checks if player would like to buy property; returns true if a player CAN buy property
    bool buyProperty(Player* player);

public:
    // constructor sets name and colour of property
    Property(std::string name, std::string colour, int cost): Space(name), colour(colour), cost(cost) {
        owner = nullptr;
    }

    // getters/setters
    std::string getColour(){ return colour; }
    int getPropertyCost(){ return propertyCost[numHouses]; }
    void setHousePrice(std::vector<int> newCost){propertyCost = newCost;}
    void setRentPrice(std::vector<int> newRentPrice){rentPrice = newRentPrice;}
    void setOwner(Player* newOwner){ owner = newOwner; }
    bool getOwned() { return isOwned; }

    // override pure virtual functions
    void land(Player* player) override;
    std::string getType() override { return "Property"; };

    int getCost() override { return cost; }

    ImVec4 getColourVec() override;
};