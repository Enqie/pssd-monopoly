#include "Space.hpp"
#include "Player.hpp"
#include "Game.hpp"

// private methods
// method makes player pay rent if they do not own this property; returns true if player pays rent
void Utility::payRent(Player* player){
    // check if current property is owned -> check if current player must pay rent
    if(isOwned){
        // check if current player does not own this property -> current player must pay rent
        if(owner != player){
            Game* game = player->getGame();
            /* LOGIC FOR RENT USING DICE ROLL 
            if 1 utility owned: rent 4 times dice roll
            if 2 utilities owned: rent 10 times dice roll
            */
           int rent = game->getDice();

            if (rent == 0) {
                player->setCanMove(false);
                return;
            }

            if(owner->getUtilities().size()==2) rent*=10;
            else rent*=4;

            player->subMoney(rent);     // subtract rent amount from player
            owner->addMoney(rent);      // increase rent amount for owner

            player->setUtilityStatus(false);
            game->nextTurn();
        }
    }
}

void Utility::setNotOwned(){
    if(!isOwned) return;
    isOwned = false;
    // owner->removeUtility(this);
}

// checks if player can buy Utility
bool Utility::canBuy(){
    if(isOwned) return false;
    return true;
}

// runs buy function
void Utility::buy(Player* player) {
    if (!isOwned) {
        player->buyUtility(this);
        isOwned = true;
    }
}


// override pure virtual land function
void Utility::land(Player* player){
    if (isOwned && getOwner() != player) {  // if property owned & current player is not owner
        player->setUtilityStatus(true);
    }
}