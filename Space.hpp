#pragma once

#include <string>

class Space
{
protected:
    /* data */
    std::string name;   // name of space
    bool canBuy;        // can space be bought by player
    int cost;           // cost of landing on this space
public:
    Space(/* args */){}
    Space(std::string name): name(name){}
};