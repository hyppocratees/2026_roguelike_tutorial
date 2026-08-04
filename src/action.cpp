#include "action.h"

#include <cstdlib>

struct Player {
    int x;
    int y;
};

void EscapeAction::Perform(Player& player)
{
    std::exit(0);
}

void MovementAction::Perform(Player& player)
{
    player.x += dx_;
    player.y += dy_;
}
