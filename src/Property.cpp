#include <iostream>
#include <string>

#include "Property.hpp"
#include "Player.hpp"

// method makes player pay rent if they do not own this property; returns true if player pays rent
void Property::payRent(Player* player){
    player->subMoney(rent);     // subtract rent amount
    owner->addMoney(rent);      // rent is paid to owner of property
}

// function to set owned status to false and reset Property variables
void Property::setNotOwned(){
    if(!isOwned) return;            // if isOwned is already false, do nothing
    isOwned = false;                // set isOwned to false
    rent = rentPrice[0];            // reset rent price to initial
    numHouses = 0;                  // reset number of houses
    owner->removeProperty(this);    // remove this property from player's list of owned property
}

// returns true if owner of property can buy another house/hotel
bool Property::canBuyHouse(Player* player){
    // if property is not owned, cannot buy house/hotel
    if(!isOwned || getOwner() != player) return false;

    // if player already owns all houses/hotels, cannot buy house/hotel
    if(numHouses==rentPrice.size()-1) return false; 

    return true;
}

// buys additional house/hotel
void Property::buyHouse(Player* player){
    // run check
    if(canBuyHouse(player)){
        owner->subMoney(houseCost);     // decrease money by house/hotel cost
        numHouses++;                    // increase count of number of owned houses/hotels
        rent = rentPrice[numHouses];    // increase rent price
    } 
}

// returns true if owner of property can buy property
bool Property::canBuy() {
    // if property is owned, cannot buy property
    if(isOwned) return false;

    return true;
}

void Property::buy(Player* player) {
    if (!isOwned) {
        player->buyProperty(this);
        setOwner(player);
        isOwned = true;
    }
}

// override pure virtual land function
void Property::land(Player* player){
    // if rent is paid, nothing else must be done so return
    if (isOwned && getOwner() != player) {
        payRent(player);
    }
}

ImVec4 Property::getColourVec() {
    static const std::unordered_map<std::string, ImVec4> colorMap = {
        {"purple", ImVec4(0.4f, 0.0f, 0.7f, 1.0f)},
        {"white", ImVec4(0.6f, 0.8f, 1.0f, 1.0f)},
        {"pink", ImVec4(0.8f, 0.2f, 0.6f, 1.0f)},
        {"orange", ImVec4(1.0f, 0.6f, 0.1f, 1.0f)},
        {"red", ImVec4(0.9f, 0.1f, 0.1f, 1.0f)},
        {"yellow", ImVec4(1.0f, 0.9f, 0.0f, 1.0f)},
        {"green", ImVec4(0.1f, 0.7f, 0.4f, 1.0f)},
        {"blue", ImVec4(0.0f, 0.4f, 0.6f, 1.0f)}
    };


    return colorMap.find(colour)->second;
}