#include "Player.hpp"

using namespace std;

// roll dice function
int Player::rollDice(){
    dice1 = rand() % 6 + 1;
    dice2 = rand() % 6 + 1;
    return dice1+dice2;
}

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
}