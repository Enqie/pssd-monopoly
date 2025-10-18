#pragma once

#include "Space.hpp"

class GoToJail : public Space
{
public:
    GoToJail(): Space("Go To Jail"){}

    void land(Player* player) override;

    std::string getType() override { return "GoToJail"; };

    ImVec4 getColourVec() override { return ImVec4(0.8f, 0.4f, 0.4f, 1.0f); }
};