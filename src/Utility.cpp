#include "Space.hpp"
#include "Player.hpp"
#include "Game.hpp"

// private methods
// method makes player pay rent if they do not own this property; returns true if player pays rent
bool Utility::payRent(Player* player, int diceRoll){
    // // rent cannot be collected on a mortgaged property so return false
    // if(isMortgaged) return false;

    // check if current property is owned -> check if current player must pay rent
    if(isOwned){
        // check if current player does not own this property -> current player must pay rent
        if(owner != player){
            /* LOGIC FOR RENT USING DICE ROLL 
            if 1 utility owned: rent 4 times dice roll
            if 2 utilities owned: rent 10 times dice roll
            */
            int rent = diceRoll;
            if(owner->getUtilities().size()==2) rent*=10;
            else                                rent*=4;

            player->subMoney(rent);     // subtract rent amount from player
            owner->addMoney(rent);      // increase rent amount for owner

            return true;                // return true as player must pay rent
        }
    }

    // otherwise player does not need to pay rent, return false
    return false;
}

// method checks if player would like to buy property; returns true if a player CAN buy property
bool Utility::buyProperty(Player* player){
    // if property is owned, cannot buy property (mortgaged properties are always owned so don't need to check)
    if(isOwned) return false;

    // ask if player would like to buy property
    /*LOGIC*/
    char choice;
    std::cout << "Would you like to buy " << Utility::getName() << "? (y/n):";
    std::cin >> choice;
    if(choice=='y'){
        player->buyUtility(this);
    }


    // player is able to buy property so return true
    return true;
}

void Utility::setNotOwned(){
    if(!isOwned) return;
    isOwned = false;
    owner->removeUtility(this);
}

// checks if player can buy Utility
bool Utility::canBuyUtility(){
    if(isOwned) return false;
    return true;
}

// runs buy function
void Utility::buyUtility(Player* player){
    if(canBuyUtility()) player->buyUtility(this);
}


// override pure virtual land function
void Utility::land(Player* player){
    // // rent cannot be collected on a mortgaged property; mortgaged properties are still owned so return
    // if(isMortgaged) return;

    // if rent is paid, nothing else must be done so return
    //if(payRent(player)) return;

    // otherwise property is not owned, check if player would like to buy property
    //if(buyProperty) return;
}