#include <iostream>

#include "Railroad.hpp"
#include "Space.hpp"
#include "Player.hpp"

// private methods
// method makes player pay rent if they do not own this property; returns true if player pays rent
void Railroad::payRent(Player* player){

    // calculate rent
    int rent = 25;                              // initial rent for railroad is 25
    rent*=(2*owner->getRailroads().size());    // rent doubles for each owned railroad
    
    player->subMoney(rent);     // subtract rent amount
    owner->addMoney(rent);
}

void Railroad::setNotOwned(){
    if(!isOwned) return;
    isOwned = false;
}

// checks if player can buy Railroad
bool Railroad::canBuy(){
    if(isOwned) return false;
    return true;
}

// runs buy function
void Railroad::buy(Player* player) {
    if (!isOwned) {
        player->buyRailroad(this);
        isOwned = true;
    }
}

// override pure virtual land function
void Railroad::land(Player* player){
    if (isOwned && getOwner() != player) {  // if property owned & current player is not owner
        payRent(player);
    }
}