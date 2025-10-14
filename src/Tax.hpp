#pragma once

#include "Space.hpp"
#include "Player.hpp"

class Tax : public Space
{
private:
    std::string name;
    int taxAmount;
public:
    Tax(std::string name, int taxAmount): Space(name), taxAmount(taxAmount){}

    void land(Player* player){
        player->subMoney(taxAmount);
    }

    std::string getType() override { return "Tax"; }
};