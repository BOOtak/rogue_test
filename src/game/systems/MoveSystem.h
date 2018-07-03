//
// Created by k.leyfer on 03.07.2018.
//

#ifndef ROGUETEST_MOVESYSTEM_H
#define ROGUETEST_MOVESYSTEM_H

#include <System.h>
#include "../events/MoveEvent.h"

class MoveSystem : public System, public EventListener {
public:
    MoveSystem(World *world);

protected:
    void prepare() override;

    void update() override;

    void finalize() override;

public:
    void onMoveEvent(MoveEvent* moveEvent);
};


#endif //ROGUETEST_MOVESYSTEM_H
