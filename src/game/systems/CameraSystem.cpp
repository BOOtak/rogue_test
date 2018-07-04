//
// Created by kirill on 04.07.18.
//

#include "CameraSystem.h"
#include "../properties/Focus.h"
#include "../properties/Position.h"

template<typename T>
int sgn(T val) {
    return (T(0) < val) - (val < T(0));
}

CameraSystem::CameraSystem(World *world) : System(world) {}

void CameraSystem::prepare() {

}

void CameraSystem::update() {
    std::vector<Entity *> cameras = getWorld()->getEntityManager()->getEntitiesWithProperties<Position, Focus>();

    for (auto &cam : cameras) {
        auto &camPos = cam->getProperty<Position>()->getValue()->position_;
        auto focus = cam->getProperty<Focus>()->getValue();
        if (focus->focus == nullptr) {
            continue;
        }
        auto entityPos = focus->focus->getProperty<Position>()->getValue();
        if (entityPos == nullptr) {
            continue;
        }

        int distX = camPos.x - entityPos->position_.x;
        int distY = camPos.y - entityPos->position_.y;
        if (std::abs(distX) > focus->padding.x) {
            camPos.x = entityPos->position_.x + focus->padding.x * sgn(distX);
        }

        if (std::abs(distY) > focus->padding.y) {
            camPos.y = entityPos->position_.y + focus->padding.y * sgn(distY);
        }
    }
}

void CameraSystem::finalize() {

}
