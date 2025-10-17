#pragma once

#include "Space.hpp"

class FreeParking : public Space
{
public:
    FreeParking(std::string name): Space(name){}

    void land(Player* player){ return; }
    
    std::string getType() override { return "FreeParking"; }

    ImVec4 getColourVec() override { return ImVec4(0.4f, 0.4f, 0.8f, 1.0f); }
};