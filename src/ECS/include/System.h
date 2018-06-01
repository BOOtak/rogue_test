//
// Created by k.leyfer on 01.06.2018.
//

#ifndef ROUGETEST_SYSTEM_H
#define ROUGETEST_SYSTEM_H


#include <vector>
#include "Entity.h"
#include "EntityManager.h"
#include "EventBus.h"

class System {
public:
    explicit System(EntityManager *em_, EventBus *eventBus_);

protected:
    EntityManager *getEm() {
        return em;
    }

    EventBus* getEventBus() {
        return eventBus;
    }

    virtual void update() = 0;

private:
    EntityManager *em;
    EventBus *eventBus;
};


#endif //ROUGETEST_SYSTEM_H
