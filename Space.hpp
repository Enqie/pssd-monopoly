#pragma once

#include <string>

class Space
{
protected:
    std::string name;       // name of space
    bool canBuy;            // can space be bought by player
    int cost;               // cost of landing on this space
    bool isOwned = false;   // bool for if space is owned? 
    bool hasEffect;         // for jail or chance/community chest - if true then can call function?
public:
    Space(/* args */){}
    Space(std::string name, bool canBuy, int cost, bool hasEffect): name(name), canBuy(canBuy), cost(cost), hasEffect(hasEffect) {}
    
    int getCost(){ return cost; }
    void setCost(int newCost){ cost = newCost; }
};