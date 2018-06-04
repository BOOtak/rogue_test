//
// Created by k.leyfer on 01.06.2018.
//

#ifndef ROUGETEST_PINGSYSTEM_H
#define ROUGETEST_PINGSYSTEM_H


#include <iostream>
#include <System.h>
#include "../events/PingEvent.h"

class PingSystem : public System, public EventListener {
public:
    explicit PingSystem(World *world);

    void onPing(PingEvent *event) {
        std::cout << "Got ping!" << std::endl;
        getWorld()->getEventBus()->sendEvent<PongEvent>();
    }

protected:
    void update() override;
};

class PongSystem : public System, public EventListener {
public:
    explicit PongSystem(World *world);

    void onPong(PongEvent *event) {
        std::cout << "Got pong!" << std::endl;
        getWorld()->getEventBus()->sendEvent<PingEvent>();
    }

protected:
    void update() override;
};

#endif //ROUGETEST_PINGSYSTEM_H
