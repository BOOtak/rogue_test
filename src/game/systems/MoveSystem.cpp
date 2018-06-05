//
// Created by kirill on 02.06.18.
//

#include "MoveSystem.h"
#include "../properties/PlayerControllable.h"
#include "../properties/Position.h"

MoveSystem::MoveSystem(World *world) : System(world) {}

void MoveSystem::update() {

}

void MoveSystem::onPlayerMoveEvent(PlayerMoveEvent *event) {
    std::vector<Entity *> controllables = getWorld()->getEntityManager()->getEntitiesWithProperties<PlayerControllable, Position>();
    for (auto c : controllables) {
        // TODO: calculate distance depending on other entity properties (e.g stats, wear etc)

        std::pair<int, int> coordsIncrement = getCoordsIncrement(event);

        auto val = c->getProperty<Position>()->getValue();
        val->x_ += coordsIncrement.first;
        val->y_ += coordsIncrement.second;
    }
}

std::pair<int, int> MoveSystem::getCoordsIncrement(PlayerMoveEvent *event) {
    switch (event->direction) {
        // todo: refactor to support more events & collisions
        case MOVE_UP:
            return std::make_pair(0, -1);
        case MOVE_DOWN:
            return std::make_pair(0, 1);
        case MOVE_LEFT:
            return std::make_pair(-1, 0);
        case MOVE_RIGHT:
            return std::make_pair(1, 0);
        default:
            // not supported, stay calm
            std::cout << "Move event " << event->direction << " is not supported!" << std::endl;
            return std::make_pair(0, 0);
    }
}

void MoveSystem::prepare() {

}

void MoveSystem::finalize() {

}
