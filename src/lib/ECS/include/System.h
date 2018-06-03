//
// Created by k.leyfer on 01.06.2018.
//

#ifndef ROUGETEST_SYSTEM_H
#define ROUGETEST_SYSTEM_H


#include <vector>
#include "Entity.h"
#include "EntityManager.h"
#include "EventBus.h"
#include "World.h"

class System {
protected:
    explicit System(World *world);

    virtual void update() = 0;

    friend class World;

private:

    World *world;
public:
    World *getWorld() const;

};


#endif //ROUGETEST_SYSTEM_H
