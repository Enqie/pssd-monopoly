#pragma once

#include "Space.hpp"

class FreeParking : public Space
{
public:
    FreeParking(std::string name): Space(name){}

    void land(Player* player){ return; }
    std::string getType() override { return "FreeParking"; }
};