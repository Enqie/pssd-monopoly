#include <iostream>

#include "Railroad.hpp"
#include "Space.hpp"
#include "Player.hpp"

// private methods
// method makes player pay rent if they do not own this property; returns true if player pays rent
bool Railroad::payRent(Player* player){
    // // rent cannot be collected on a mortgaged property so return false
    // if(isMortgaged) return false;

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

// override pure virtual land function
void Railroad::land(Player* player){
    // // rent cannot be collected on a mortgaged property; mortgaged properties are still owned so return
    // if(isMortgaged) return;

    // if rent is paid, nothing else must be done so return
    if(Railroad::payRent(player)) return;

    // otherwise property is not owned, check if player would like to buy property
    //if(Railroad::buyProperty) return;
}