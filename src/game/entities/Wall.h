//
// Created by k.leyfer on 03.07.2018.
//

#ifndef ROGUETEST_WALL_H
#define ROGUETEST_WALL_H


#include <Entity.h>
#include "../properties/Position.h"
#include "../properties/CharTexture.h"
#include "../properties/RigidBody.h"

class Wall : public Entity {
public:
    Wall(int x, int y) {
        addProperty<Position>(x, y);
        addProperty<RigidBody>();
        addProperty<CharTexture>(' ', A_REVERSE);
    }
};


#endif //ROGUETEST_WALL_H
