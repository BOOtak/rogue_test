//
// Created by kirill on 31.05.18.
//

#ifndef ROUGETEST_WORLD_H
#define ROUGETEST_WORLD_H


#include "EntityManager.h"

class World {
public:
    World();

    ~World();

    EntityManager *getEntityManager() {
        return _entityManager;
    }

private:
    EntityManager *_entityManager;
};


#endif //ROUGETEST_WORLD_H
