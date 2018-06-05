//
// Created by kirill on 31.05.18.
//

#ifndef ROUGETEST_PLAYER_H
#define ROUGETEST_PLAYER_H


#include <Entity.h>
#include "../properties/Position.h"
#include "../properties/PlayerControllable.h"
#include "../properties/CharTexture.h"

class Player : public Entity {
public:
    Player(int x, int y) {
        addProperty<Position>(x, y);
        addProperty<PlayerControllable>();
        addProperty<CharTexture>('@', 0);
    }
};


#endif //ROUGETEST_PLAYER_H
