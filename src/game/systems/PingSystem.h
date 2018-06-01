//
// Created by k.leyfer on 01.06.2018.
//

#ifndef ROUGETEST_PINGSYSTEM_H
#define ROUGETEST_PINGSYSTEM_H


#include <iostream>
#include <System.h>
#include "../events/PingEvent.h"

class PingSystem : public System, public EventListener<PingEvent> {
public:
    PingSystem(EntityManager *em_, EventBus *eventBus_);

    void onEvent(Event<PingEvent> *event) override {
        std::cout << "Got ping!" << std::endl;
        getEventBus()->sendEvent<PongEvent>();
    }

protected:
    void update() override;
};

class PongSystem : public System, public EventListener<PongEvent> {
public:
    PongSystem(EntityManager *em_, EventBus *eventBus_);

    void onEvent(Event<PongEvent> *event) override {
        std::cout << "Got pong!" << std::endl;
        getEventBus()->sendEvent<PingEvent>();
    }

protected:
    void update() override;
};

#endif //ROUGETEST_PINGSYSTEM_H
