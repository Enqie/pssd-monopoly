#include "GoToJail.hpp"
#include "Player.hpp"

#include <iostream>

void GoToJail::land(Player* player){
    player->setPos(jail);                 // move to jail position
    player->setJailStatus(true);        // player is in jail

    std::cout << "Player sent to jail." << std::endl;
}