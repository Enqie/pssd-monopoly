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
    Space(std::string name) : name(name) {}

    std::string getName(){ return name; }

    virtual void land(Player* player) = 0;  // pure virtual function for what happens if you land on a space

    virtual std::string getType() = 0;      // pure virtual function to get space type

    virtual int getCost() { return 0; }     // function to get property cost, returns 0 if not overridden by a child class
};