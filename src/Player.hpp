#pragma once

#include <unordered_map>
#include <unordered_set>
#include <stdlib.h>

#include "Property.hpp"
#include "Utility.hpp"
#include "Railroad.hpp"

class Player
{
private:
    std::string name;

    int money = 1500;           // player starts with 1500

    // Player has 2 dice
    int dice1;
    int dice2;

    // booleans for player state
    bool isInJail = false;
    bool isBankrupt = false;

    // container to store Properties/Utilities/Railroads owned by player
    std::unordered_set<Property*> ownedProperties;
    std::unordered_set<Utility*> ownedUtilities;
    std::unordered_set<Railroad*> ownedRailroads;

    // unordered map to store number of each property colours a player owns
    std::unordered_map<std::string, int> propertyColours;
public:
    Player(std::string name): name(name){}

    // getters/setters
    std::string getName(){ return name; }
    int getMoney(){ return money; }
    std::unordered_set<Property*> getProperties(){ return ownedProperties; }
    std::unordered_set<Utility*> getUtilities(){ return ownedUtilities; }
    std::unordered_set<Railroad*> getRailroads(){ return ownedRailroads; }
    bool getJailStatus(){ return isInJail; }
    int getDiceRoll(){ return dice1+dice2; }
    // bool getBankruptStatus(){ return isBankrupt; }
    void setJailStatus(bool status){ isInJail = status; }
    void setBankruptStatus(bool status){ isBankrupt = status; }

    // roll dice function
    int rollDice(){
        dice1 = rand() % 6 + 1;
        dice2 = rand() % 6 + 1;
        return dice1+dice2;
    }

    // calculate bankruptcy status of player based on money 
    bool checkBankruptcy(){
        if(money<=0) isBankrupt = true;
        return isBankrupt;
    }

    // buy functions
    void buyProperty(Property* property){
        // update owner in property
        property->setOwner(this);

        // add property to list of owned properties
        ownedProperties.insert(property);

        // update list of owned property colours
        auto found = propertyColours.find(property->getColour());
        if(found != propertyColours.end()) found->second++;
        else propertyColours.insert({property->getColour(), 1});
    }

    // methods to add or subtract amounts of money from player
    void addMoney(int amount){ money+=amount; }
    void subMoney(int amount){ 
        money-=amount; 
        checkBankruptcy();
    }
};