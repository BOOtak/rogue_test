//
// Created by k.leyfer on 01.06.2018.
//

#include "System.h"

System::System(World *world_) : world(world_) {}

World *System::getWorld() const {
    return world;
}
