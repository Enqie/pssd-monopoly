#include "GoToJail.hpp"
#include "Player.hpp"

#include <iostream>

void GoToJail::land(Player* player){
    player->setPos(3);
    std::cout << "went to jail" << std::endl;
}