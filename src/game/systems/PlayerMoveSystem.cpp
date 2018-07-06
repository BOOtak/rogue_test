//
// Created by kirill on 02.06.18.
//

#include "PlayerMoveSystem.h"
#include "../properties/PlayerControllable.h"
#include "../properties/Position.h"
#include "../utils/Vector2.h"
#include "../events/MoveEvent.h"
#include "../utils/logging.h"

PlayerMoveSystem::PlayerMoveSystem(World *world) : System(world) {}

void PlayerMoveSystem::update() {

}

void PlayerMoveSystem::onPlayerMoveEvent(PlayerMoveEvent *event) {
    std::vector<Entity *> controllables = getWorld()->getEntityManager()->getEntitiesWithProperties<PlayerControllable, Position>();
    for (auto c : controllables) {
        // TODO: calculate distance depending on other entity properties (e.g stats, wear etc)

        Vector2<int> coordsIncrement = getCoordsIncrement(event);
        getWorld()->getEventBus()->sendEvent<MoveEvent>(c, coordsIncrement);
    }
}

Vector2<int> PlayerMoveSystem::getCoordsIncrement(PlayerMoveEvent *event) {
    switch (event->direction) {
        // todo: refactor to support more events
        case MOVE_UP:
            return Vector2<int>(0, -1);
        case MOVE_DOWN:
            return Vector2<int>(0, 1);
        case MOVE_LEFT:
            return Vector2<int>(-1, 0);
        case MOVE_RIGHT:
            return Vector2<int>(1, 0);
        default:
            // not supported, stay calm
            LOG_WARN("Move event {} is not supported!", event->direction);
            return Vector2<int>(0, 0);
    }
}

void PlayerMoveSystem::prepare() {

}

void PlayerMoveSystem::finalize() {

}
