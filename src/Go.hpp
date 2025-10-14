#pragma once

#include "Space.hpp"

class Go: public Space
{
private:
    /* data */
public:
    Go(): Space("Go"){}

    void land(Player* player){ player->addMoney(200); }
    std::string getType() override { return "Go"; }
};
