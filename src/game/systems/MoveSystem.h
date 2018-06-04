//
// Created by kirill on 02.06.18.
//

#ifndef ROUGETEST_MOVESYSTEM_H
#define ROUGETEST_MOVESYSTEM_H


#include <System.h>
#include "../events/PlayerMoveEvent.h"

class MoveSystem : public System, public EventListener<PlayerMoveEvent> {
public:
    MoveSystem(World *world);

    void update() override;

protected:
    void onEvent(Event<PlayerMoveEvent> *event) override;

    std::pair<int, int> getCoordsIncrement(PlayerMoveEvent *event);
};


#endif //ROUGETEST_MOVESYSTEM_H
