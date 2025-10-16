#include <iostream>
#include <string>

#include "Property.hpp"
#include "Player.hpp"

// method makes player pay rent if they do not own this property; returns true if player pays rent
bool Property::payRent(Player* player){
    // check if current property is owned -> check if current player must pay rent
    if(isOwned){
        // check if current player does not own this property -> current player must pay rent
        if(player->getProperties().find(this) == player->getProperties().end()){
            player->subMoney(rent);     // subtract rent amount

            owner->addMoney(rent);      // rent is paid to owner of property

            return true;                // return true as player must pay rent
        }
    }

    // otherwise player does not need to pay rent, return false
    return false;
}

// // method checks if player would like to buy house/hotel on property; returns true if player CAN buy house
// bool Property::buyHouseOld(Player* player){
//     // if property is not owned, cannot buy house/hotel
//     if(!isOwned) return false;
//
//     // check if current player owns this property
//     if(player->getProperties().find(this) != player->getProperties().end()){
//         // total number of houses/hotels
//         int totalHouses = rentPrice.size()-1;
//
//         // check if player owns all houses/hotels
//         if(numHouses==totalHouses){ return true; }
//
//         // ask if player would like to buy house/hotel
//         std::string houseOrHotel = (numHouses<rentPrice.size()-1) ? "house" : "hotel";
//         char choice;
//         std::cout << "Would you like to buy " << houseOrHotel << " for $" << houseCost << "? (y/n):";
//         std::cin >> choice;
//         if(choice=='y'){
//             player->subMoney(houseCost);    // decrease money by house/hotel cost
//             numHouses++;                    // increase count of number of owned houses/hotels
//             rent = rentPrice[numHouses];    // increase rent price
//         }
//
//         return true;
//     }
//
//     // otherwise return false
//     return false;
// }

// method checks if player would like to buy property; returns true if a player CAN buy property
bool Property::buyPropertyOld(Player* player){
    // if property is owned, cannot buy property (mortgaged properties are always owned so don't need to check)
    if(isOwned) return false;

    // ask if player would like to buy property
    /*LOGIC*/
    char choice;
    std::cout << "Would you like to buy " << Property::getName() << " for $" << rentPrice.front() << "? (y/n):";
    std::cin >> choice;
    if(choice=='y'){
        player->buyProperty(this);
    }

    // player is able to buy property so return true
    return true;
}

// returns true if owner of property can buy another house/hotel
bool Property::canBuyHouse(){
    // if property is not owned, cannot buy house/hotel
    if(!isOwned) return false;

    // if player already owns all houses/hotels, cannot buy house/hotel
    if(numHouses==rentPrice.size()-1) return false; 

    return true;
}

// buys additional house/hotel
void Property::buyHouse(){
    // run check
    if(canBuyHouse()){
        owner->subMoney(houseCost);     // decrease money by house/hotel cost
        numHouses++;                    // increase count of number of owned houses/hotels
        rent = rentPrice[numHouses];    // increase rent price
    } 
}

// returns true if owner of property can buy another house/hotel
bool Property::canBuyProperty(){
    // if property is owned, cannot buy property
    if(isOwned) return false;

    return true;
}

void Property::buyProperty(Player* player){
    // run check
    if(canBuyProperty()){
        player->buyProperty(this);
    }
}

// override pure virtual land function
void Property::land(Player* player){

    // if rent is paid, nothing else must be done so return
    if(payRent(player)) return;

    // otherwise property is not owned, check if player would like to buy property
    // if(buyProperty) return;

    // if(buyHouse) return;
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
        {"blue", ImVec4(0.0f, 0.5f, 0.7f, 1.0f)}
    };


    return colorMap.find(colour)->second;
}