#include "GoToJail.hpp"
#include "Player.hpp"

#include <iostream>

void GoToJail::land(Player* player){
    player->setPos(10);
    player->setJailStatus(true);

    std::cout << "Player sent to jail." << std::endl;
}