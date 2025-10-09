#include "Property.hpp"
#include "Player.hpp"

// method makes player pay rent if they do not own this property; returns true if player pays rent
bool Property::payRent(Player* player){
    // rent cannot be collected on a mortgaged property so return false
    if(isMortgaged) return false;

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

// method checks if player would like to buy house/hotel on property; returns true if player CAN buy house
bool Property::buyHouse(Player* player){
    // if property is not owned, cannot buy house/hotel
    if(!isOwned) return false;

    // if property is mortgaged, cannot buy house/hotel
    if(isMortgaged) return false;

    // check if current player owns this property
    if(player->getProperties().find(this) != player->getProperties().end()){
        // ask if player would like to buy house/hotel
        /*LOGIC*/
            // if player buys house/hotel
            /*LOGIC*/
        return true;
    }
    
    // otherwise return false
    return false;
}

// method checks if player would like to buy property; returns true if a player CAN buy property
bool Property::buyProperty(Player* player){
    // if property is owned, cannot buy property (mortgaged properties are always owned so don't need to check)
    if(isOwned) return false;

    // ask if player would like to buy property
    /*LOGIC*/

    // player is able to buy property so return true
    return true;
}

// override pure virtual land function
void Property::land(Player* player){
    // rent cannot be collected on a mortgaged property; mortgaged properties are still owned so return
    if(isMortgaged) return;

    // if rent is paid, nothing else must be done so return
    if(payRent(player)) return;

    // otherwise property is not owned, check if player would like to buy property
    //if(buyProperty) return;

    //if(buyHouse) return;
}