//
// Created by k.leyfer on 03.07.2018.
//

#include "MoveSystem.h"
#include "../properties/Position.h"
#include "../properties/RigidBody.h"

MoveSystem::MoveSystem(World *world) : System(world) {}

void MoveSystem::onMoveEvent(MoveEvent *moveEvent) {
    auto physicBodies = getWorld()->getEntityManager()->getEntitiesWithProperties<Position, RigidBody>();
    auto &currentPos = moveEvent->movedEntity->getProperty<Position>()->getValue()->position_;
    auto potentialPos = currentPos + moveEvent->moveVec;

    if (std::count_if(physicBodies.begin(), physicBodies.end(), [&](Entity *entity) -> bool {
        return entity->getProperty<Position>()->getValue()->position_ == potentialPos;
    }) <= 0) {
        currentPos = potentialPos;
    }
}

void MoveSystem::prepare() {

}

void MoveSystem::update() {

}

void MoveSystem::finalize() {

}
