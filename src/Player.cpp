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

    // update list of owned property colours
    // auto found = propertyColours.find(property->getColour());
    // if(found != propertyColours.end()) found->second++;
    // else propertyColours.insert({property->getColour(), 1});

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

// remove all owned Properties
void Player::clearOwnedProperty(){
    // set all properties in set to not owned
    for(auto itr : ownedProperties)
        itr->setNotOwned();
    
    // clear set of owned properties and map of owned colours
    ownedProperties.clear();
    propertyColours.clear();
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

    // call land function for a space
    Space* newSpace = game->getSpace(space);
    newSpace->land(this);
    this->setCanMove(false);            // player can't move twice
}

bool Player::payBail() {
    if (isInJail) {
        this->subMoney(50);
        this->setJailStatus(false);
        return true;
    } else return false;
}

void Player::subMoney(int amount) {
    money-=amount; 
    if (checkBankruptcy()) {
        std::cout << game->getPlayer().getName() << " has gone bankrupt!" << std::endl;
        resetAllOwnedSpaces();
        game->deletePlayer(game->getPlayerIdx());
    }
}