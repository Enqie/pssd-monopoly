#pragma once

#include <unordered_map>
#include <unordered_set>

#include "Property.hpp"
#include "Utility.hpp"
#include "Railroad.hpp"

class Player
{
private:
    std::string name;

    int money = 1500;           // player starts with 1500

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
    // bool getBankruptStatus(){ return isBankrupt; }
    void setJailStatus(bool status){ isInJail = status; }
    void setBankruptStatus(bool status){ isBankrupt = status; }

    // calculate bankruptcy status of player based on money 
    bool checkBankruptcy(){
        if(money<=0) isBankrupt = true;
        return isBankrupt;
    }

    // buy functions
    void buyProperty(Property* property){
        // add property to list of owned properties
        ownedProperties.insert(property);

        // update list of owned property colours
        auto found = propertyColours.find(property->getColour());
        if(found != propertyColours.end()) found->second++;
        else propertyColours.insert({property->getColour(), 1});
    }

    // does interface stuff checking if Player would like to buy property (return true if yes)
    bool isBuyProperty(){
        /* LOGIC FOR INTERFACE */
        // check if Player has enough money


        // ask if Player would like to buy property


        // return true if Player buys property and false otherwise
    }

    // methods to add or subtract amounts of money from player
    void addMoney(int amount){ money+=amount; }
    void subMoney(int amount){ money-=amount; }
};