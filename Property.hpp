#pragma once

#include <vector>

#include "Player.hpp"
#include "Space.hpp"

class Property: public Space
{
private:
    // Property states
    bool isOwned = false;
    bool isMortgaged = false;

    // Property information
    std::string colour;                 // colour group of property
    std::vector<int> propertyCost;      // cost to buy property/houses/hotels 
    std::vector<int> rentPrice;         // cost of rent with respective amount of houses/hotels
    int rent;                           // current rent
public:
    // constructor sets name and colour of property
    Property(std::string name, std::string colour): Space(name), colour(colour){}

    // getters/setters
    void setHousePrice(std::vector<int> newCost){propertyCost = newCost;}
    void setRentPrice(std::vector<int> newRentPrice){rentPrice = newRentPrice;}

    // override pure virtual land function
    void land(Player* player){
        // rent cannot be collected on a mortgaged property so return
        if(isMortgaged) return;

        // if Property is owned, check if player landing owns this property
        if(isOwned){
            // check if current player owns this property
            if(player->getProperties().find(this) != player->getProperties().end()){
                // check if player owns all properties of this colour -> can buy house ?
            }
        }

        // otherwise property is not owned, check if player would like to buy property
    }
};