#pragma once

#include "Space.hpp"

class Tax : public Space
{
private:
    int taxAmount;
public:
    Tax(std::string name, int taxAmount): Space(name), taxAmount(taxAmount){}

    void land(Player* player){
        player->subMoney(taxAmount);
    }
};