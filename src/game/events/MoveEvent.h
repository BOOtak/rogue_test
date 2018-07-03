//
// Created by k.leyfer on 03.07.2018.
//

#ifndef ROGUETEST_MOVEEVENT_H
#define ROGUETEST_MOVEEVENT_H

#include <Entity.h>
#include "../utils/Vector2.h"

struct MoveEvent {
    MoveEvent(Entity *movedEntity, const Vector2<int> &moveVec) : movedEntity(movedEntity), moveVec(moveVec) {}

    Entity *movedEntity;
    Vector2<int> moveVec;
};

#endif //ROGUETEST_MOVEEVENT_H
