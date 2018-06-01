//
// Created by kirill on 31.05.18.
//

#ifndef ROUGETEST_MOB_H
#define ROUGETEST_MOB_H


#include <Entity.h>
#include "../properties/Position.h"

class Mob : public Entity {
public:
    Mob(int x, int y) {
        addProperty<Position>(x, y);
    }
};


#endif //ROUGETEST_MOB_H
