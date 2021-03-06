//
// Created by kirill on 31.05.18.
//

#ifndef ROUGETEST_WORLD_H
#define ROUGETEST_WORLD_H


#include "EntityManager.h"
#include "EventBus.h"

// forward declaration
class System;

class World {
public:
    World();

    ~World();

    template<class T, class ... Args>
    T *addSystem(Args... args) {
        auto *system = new T(this, args...);
        systems.push_back(system);
        return system;
    }

    EntityManager *getEntityManager() const;

    EventBus *getEventBus() const;

    void prepare();

    void update();

private:
    EntityManager *entityManager;

    EventBus *eventBus;

    std::vector<System *> systems;
};

#endif //ROUGETEST_WORLD_H
