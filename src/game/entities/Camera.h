//
// Created by kirill on 04.07.18.
//

#ifndef ROGUETEST_CAMERA_H
#define ROGUETEST_CAMERA_H


#include <Entity.h>
#include "../properties/Position.h"
#include "../properties/Focus.h"

class Camera : public Entity {
public:
    Camera(int x, int y, int paddingX, int paddingY, const Entity* focusedEntity) {
        addProperty<Position>(x, y);
        addProperty<Focus>(paddingX, paddingY, focusedEntity);
    }
};


#endif //ROGUETEST_CAMERA_H
