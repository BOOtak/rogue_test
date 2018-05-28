#include <iostream>
#include "ECS/Entity.h"
#include "properties/Position.h"
#include "MoveCommand.h"

int main() {
    auto *player = new Entity();
    player->addProperty<Position>(12, 3);

    auto *playerPos = player->getProperty<Position>()->getValue();
    std::cout << playerPos->x_ << " " << playerPos->y_ << std::endl;

    auto *command = new MoveCommand(10, 10, player);
    command->execute();

    std::cout << playerPos->x_ << " " << playerPos->y_ << std::endl;

    return 0;
}
