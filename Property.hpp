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

    // private methods
    // method makes player pay rent if they do not own this property; returns true if player pays rent
    bool payRent(Player* player){
        // rent cannot be collected on a mortgaged property so return false
        if(isMortgaged) return false;

        // check if current property is owned -> check if current player must pay rent
        if(isOwned){
            // check if current player does not own this property -> current player must pay rent
            if(player->getProperties().find(this) == player->getProperties().end()){
                player->subMoney(rent);     // subtract rent amount
                return true;                // return true as player must pay rent
            }
        }

        // otherwise player does not need to pay rent, return false
        return false;
    }

    // method checks if player would like to buy house/hotel on property; returns true if player CAN buy house
    bool buyHouse(Player* player){
        // if property is not owned, cannot buy house/hotel
        if(!isOwned) return false;

        // if property is mortgaged, cannot buy house/hotel
        if(isMortgaged) return false;

        // check if current player owns this property
        if(player->getProperties().find(this) != player->getProperties().end()){
            // check if player owns all properties of this colour -> can buy house/hotel
            /*LOGIC*/
                // ask if player would like to buy house/hotel
                /*LOGIC*/
                return true;
        }
        
        // otherwise return false
        return false;
    }

    // method checks if player would like to buy property; returns true if a player CAN buy property
    bool buyProperty(Player* player){
        // if property is owned, cannot buy property (mortgaged properties are always owned so don't need to check)
        if(isOwned) return false;

        // ask if player would like to buy property
        /*LOGIC*/

        // player is able to buy property so return true
        return true;
    }

public:
    // constructor sets name and colour of property
    Property(std::string name, std::string colour): Space(name), colour(colour){}

    // getters/setters
    std::string getColour(){ return colour; }
    void setHousePrice(std::vector<int> newCost){propertyCost = newCost;}
    void setRentPrice(std::vector<int> newRentPrice){rentPrice = newRentPrice;}

    // override pure virtual land function
    void land(Player* player){
        // rent cannot be collected on a mortgaged property; mortgaged properties are still owned so return
        if(isMortgaged) return;

        // if rent is paid, nothing else must be done so return
        if(payRent(player)) return;

        // otherwise property is not owned, check if player would like to buy property
        if(buyProperty) return;

        if(buyHouse) return;
    }
};