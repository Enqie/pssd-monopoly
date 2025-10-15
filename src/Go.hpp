#pragma once

#include "Space.hpp"

class Go: public Space
{
private:
    /* data */
public:
    Go(): Space("Go"){}

    std::string getType() override { return "Go"; }
};
