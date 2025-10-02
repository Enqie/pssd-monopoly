#pragma once

#include <string>

class Space
{
protected:
    std::string name;           // name of space
public:
    // constructors
    Space(/* args */){}
    Space(std::string name) {}

    virtual void land() = 0;    // pure virtual function for what happens if you land on a space
};