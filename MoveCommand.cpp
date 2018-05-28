//
// Created by kirill on 24.05.18.
//

#include "MoveCommand.h"
#include "properties/Position.h"

MoveCommand::MoveCommand(int x, int y, Entity *entity) : x(x), y(y), entity(entity) {}

void MoveCommand::execute() {
    Position* position = entity->getProperty<Position>()->getValue();
    if (position != nullptr) {
        position->x_ += x;
        position->y_ += y;
    }
}

