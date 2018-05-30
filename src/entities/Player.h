//
// Created by kirill on 31.05.18.
//

#ifndef ROUGETEST_PLAYER_H
#define ROUGETEST_PLAYER_H


#include "../ECS/Entity.h"
#include "../properties/Position.h"

class Player : public Entity {
public:
    Player(int x, int y) {
        addProperty<Position>(x, y);
    }
};


#endif //ROUGETEST_PLAYER_H
