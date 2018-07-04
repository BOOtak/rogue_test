//
// Created by kirill on 04.07.18.
//

#ifndef ROGUETEST_VIEWPORT_H
#define ROGUETEST_VIEWPORT_H

#include <Entity.h>
#include "../utils/Vector2.h"

/**
 * Class representing properties of camera in terms of following entity in focus.
 */
struct Focus {
    Focus(int paddingX, int paddingY, const Entity *focus) : padding(paddingX, paddingY), focus(focus) {}

    /**
     * Entity currently in focus.
     */
    const Entity *focus;

    /**
     * Amount of cells entity is allowed to move out of center of camera viewport. If entity shift exceeds this amount,
     * camera will start to follow it.
     */
    Vector2<int> padding;
};

#endif //ROGUETEST_VIEWPORT_H
