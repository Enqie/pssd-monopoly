#pragma once

#include <string>

class Player;

class Space
{
protected:
    std::string name;           // name of space
public:
    // constructors
    Space(/* args */){}
    Space(std::string name) {}

    std::string getName(){ return name; }

    virtual void land(Player* player) = 0;    // pure virtual function for what happens if you land on a space
};