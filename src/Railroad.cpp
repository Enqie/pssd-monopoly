#include <iostream>

#include "Railroad.hpp"
#include "Space.hpp"
#include "Player.hpp"

// private methods
// method makes player pay rent if they do not own this property; returns true if player pays rent
bool Railroad::payRent(Player* player){

    // check if current property is owned -> check if current player must pay rent
    if(isOwned){
        // check if current player does not own this property -> current player must pay rent
        if(player->getRailroads().find(this) == player->getRailroads().end()){
            // calculate rent
            int rent = 25;              // initial rent for railroad is 25
            for(int i = 0; i < player->getRailroads().size(); i++)
                rent*=2;                // rent doubles for each owned railroad
            
            player->subMoney(rent);     // subtract rent amount

            /* INCREASE RENT AMOUNT FOR OWNER OF RAILROAD */

            return true;                // return true as player must pay rent
        }
    }

    // otherwise player does not need to pay rent, return false
    return false;
}

// method checks if player would like to buy property; returns true if a player CAN buy property
bool Railroad::buyProperty(Player* player){
    // if property is owned, cannot buy property (mortgaged properties are always owned so don't need to check)
    if(isOwned) return false;

    // ask if player would like to buy property
    /*LOGIC*/
    char choice;
    std::cout << "Would you like to buy " << Railroad::getName() << "? (y/n):";
    std::cin >> choice;
    if(choice=='y'){
        player->buyRailroad(this);
    }

    // player is able to buy property so return true
    return true;
}

void Railroad::setNotOwned(){
    if(!isOwned) return;
    isOwned = false;
    owner->removeRailroad(this);
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
        setOwner(player);
        isOwned = true;
    }
}

// override pure virtual land function
void Railroad::land(Player* player){
    // if rent is paid, nothing else must be done so return
    if (isOwned && getOwner() != player) {
        payRent(player);
    }
}