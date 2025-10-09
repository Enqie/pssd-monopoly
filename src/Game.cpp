#include "Game.hpp"

void Game::start(int p) {
    players.clear();
    for (int i = 0; i < p; i++) {
        players.emplace_back("P" + std::to_string(i + 1));
    }
}