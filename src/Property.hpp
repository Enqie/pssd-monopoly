#pragma once

#include <vector>
#include "Space.hpp"

class Player; 

class Property: public Space
{
private:
    // Property states
    bool isOwned = false;
    bool isMortgaged = false;

    // Property information
    Player* owner;
    std::string colour;                 // colour group of property
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
    Property(std::string name, std::string colour): Space(name), colour(colour){
        owner = nullptr;
    }

    // getters/setters
    std::string getColour(){ return colour; }
    int getCost(){ return propertyCost[numHouses]; }
    void setHousePrice(std::vector<int> newCost){propertyCost = newCost;}
    void setRentPrice(std::vector<int> newRentPrice){rentPrice = newRentPrice;}
    void setOwner(Player* newOwner){ owner = newOwner; }

    // override pure virtual land function
    void land(Player* player) override;
};