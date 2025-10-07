#pragma once

#include "Space.hpp"

class Jail : public Space
{
private:
    
public:
    Jail(): Space("Jail"){}

    void land(Player* player){
        // if player is not currently jailed, they are just visiting so return
        if(player->getJailStatus() == false) return;

        /* LOGIC FOR IN JAIL */
    }
};