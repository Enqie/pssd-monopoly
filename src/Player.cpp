#include <iostream>
#include "Player.hpp"
#include "Game.hpp"

using namespace std;

// calculate bankruptcy status of player based on money 
bool Player::checkBankruptcy(){
    if(money<=0) {
        isBankrupt = true;
    }
    return isBankrupt;
}

// buy functions
void Player::buyProperty(Property* property){
    // update owner in property
    property->setOwner(this);

    // add property to list of owned properties
    ownedProperties.insert(property);

    // decrease money of player by cost of buying
    subMoney(property->getCost());
}

void Player::buyRailroad(Railroad* railroad){
    // update owner in railroad
    railroad->setOwner(this);

    // add to list of owned railroads
    ownedRailroads.insert(railroad);

    // decrease money of player by cost of buying
    subMoney(railroad->getCost());
}

void Player::buyUtility(Utility* utility){
    // update owner in railroad
    utility->setOwner(this);

    // add to list of owned railroads
    ownedUtilities.insert(utility);

    // decrease money of player by cost of buying
    subMoney(utility->getCost());
}

// remove all owned Properties
void Player::clearOwnedProperty(){
    // set all properties in set to not owned
    for(auto itr : ownedProperties)
        itr->setNotOwned();
    
    // clear set of owned properties 
    ownedProperties.clear();
}

// remove all owned Railroads
void Player::clearOwnedRailroad(){
    // set all Railroads in set to not owned
    for(auto itr : ownedRailroads)
        itr->setNotOwned();

    // clear set of owned Railroads 
    ownedRailroads.clear();
}

// remove all owned Utilities
void Player::clearOwnedUtility(){
    // set all Utilities in set to not owned
    for(auto itr : ownedUtilities)
        itr->setNotOwned();

    // clear set of owned Utilities
    ownedUtilities.clear();
}

// reset status of all owned spaces
void Player::resetAllOwnedSpaces(){
    clearOwnedProperty();   // reset owned properties
    clearOwnedRailroad();   // reset owned railroads
    clearOwnedUtility();    // reset owned utilities
}

// move spaces
void Player::move(int spaces) {
    int boardSize = game->getBoardSize();
    int pos = position + spaces;        // position without wrapping
    setPos(pos % boardSize);            // set position, modulus to wrap around the board

    if (boardSize <= pos) {             // pass go check
        this->addMoney(200);
    }
};

void Player::setPos(int space) {
    position = space;

    // call "land" function for a space
    Space* newSpace = game->getSpace(space);
    newSpace->land(this);
    this->setCanMove(false);    // player can't move twice
}

// player requests to pay bail
bool Player::payBail() {
    if (isInJail) {                     // can't pay bail if not in jail
        this->subMoney(50);
        this->setJailStatus(false);     // out of jail, can roll again to move
        return true;
    } else return false;
}

// subtract money from players account
void Player::subMoney(int amount) {
    money-=amount; 
    if (checkBankruptcy()) {
        // bankruptcy check & logic
        std::cout << game->getPlayer().getName() << " has gone bankrupt!" << std::endl;
        resetAllOwnedSpaces();
        game->deletePlayer(game->getPlayerIdx());
    }
}