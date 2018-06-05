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
        T *system = new T(this, args...);
        // Work-around forward declaration (we have no clue about System methods at this point).
        prepareSystem(system);
        systems.push_back(system);
        return system;
    }

    EntityManager *getEntityManager() const;

    EventBus *getEventBus() const;

    void update();

private:
    EntityManager *entityManager;

    EventBus *eventBus;

    std::vector<System *> systems;

    void prepareSystem(System *system);
};

#endif //ROUGETEST_WORLD_H
