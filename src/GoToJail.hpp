#pragma once

#include "Space.hpp"

class GoToJail : public Space
{
private:
    int jail = 8; // set jail index
public:
    GoToJail(): Space("Go To Jail"){}

    void land(Player* player) override;

    std::string getType() override { return "GoToJail"; };
};