#pragma once

#include <string>
#include "imgui.h"

class Player;

class Space
{
protected:
    std::string name;           // name of space
public:
    // constructors
    Space(/* args */){}
    Space(std::string name) : name(name) {}
    virtual ~Space() {}

    std::string getName(){ return name; }

    virtual void land(Player* player) {}    // virtual function for what happens if you land on a space

    virtual std::string getType() = 0;      // pure virtual function to get space type

    virtual int getCost() { return -1; }    // function to get property cost, returns -1 if not overridden by a child class

    // virtual functions for returning colour with defaults
    virtual std::string getColour() { return "N/A"; }
    virtual ImVec4 getColourVec() { return ImVec4(0.5f, 0.5f, 0.5f, 0.5f); }

    virtual bool canBuy() { return false; }         // virtual can buy function, returns false by default
    virtual void buy(Player* player) { return; }    // pure virtual buy

    virtual Player* getOwner() { return nullptr; }  // not applicable by default
};