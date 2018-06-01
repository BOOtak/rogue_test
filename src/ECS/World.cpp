//
// Created by kirill on 31.05.18.
//

#include "include/World.h"

World::World() {
    _entityManager = new EntityManager();
}

World::~World() {
    delete(_entityManager);
}
