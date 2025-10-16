#include "Player.hpp"
#include "Game.hpp"

using namespace std;

// calculate bankruptcy status of player based on money 
bool Player::checkBankruptcy(){
    if(money<=0) isBankrupt = true;
    return isBankrupt;
}

// buy functions
void Player::buyProperty(Property* property){
    // update owner in property
    property->setOwner(this);

    // add property to list of owned properties
    ownedProperties.insert(property);

    // update list of owned property colours
    auto found = propertyColours.find(property->getColour());
    if(found != propertyColours.end()) found->second++;
    else propertyColours.insert({property->getColour(), 1});

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

// remove Property from owned list
void Player::removeProperty(Property* property){
    // ensure property exists in owned list
    auto found = ownedProperties.find(property);
    if(found == ownedProperties.end()) return;
    
    // erase from owned set
    ownedProperties.erase(found);

    // decrement property colour count
    propertyColours.find(property->getColour())->second--;
}

// remove Railroad from owned list
void Player::removeRailroad(Railroad* railroad){
    // ensure railroad exists in owned list
    auto found = ownedRailroads.find(railroad);
    if(found == ownedRailroads.end()) return;
    
    // erase from owned set
    ownedRailroads.erase(found);
}

// remove Utility from owned list
void Player::removeUtility(Utility* utility){
    // ensure utility exists in owned list
    auto found = ownedUtilities.find(utility);
    if(found == ownedUtilities.end()) return;
    
    // erase from owned set
    ownedUtilities.erase(found);
}

// move spaces
void Player::move(int spaces) {
    int boardSize = game->getBoardSize();
    int pos = position + spaces;        // position without wrapping
    setPos(pos % boardSize);            // set position, modulus to wrap around the board

    if (boardSize <= pos) {            // pass go check
        this->addMoney(200);
    }
};

void Player::setPos(int space) {
    position = space;

    // call land function for a space
    Space* newSpace = game->getSpace(space);
    newSpace->land(this);
}

bool Player::payBail() {
    if (isInJail) {
        this->subMoney(50);
        this->setJailStatus(false);
        return true;
    } else return false;
}