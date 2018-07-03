//
// Created by kirill on 28.05.18.
//

#ifndef ROUGETEST_POSITION_H
#define ROUGETEST_POSITION_H

#include "../utils/Vector2.h"

struct Position {
    Position(int x, int y) : position_(x, y) {}

    Vector2<int> position_;
};

#endif //ROUGETEST_POSITION_H
