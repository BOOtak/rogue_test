//
// Created by kirill on 02.06.18.
//

#ifndef ROUGETEST_MOVESYSTEM_H
#define ROUGETEST_MOVESYSTEM_H


#include <System.h>
#include "../events/PlayerMoveEvent.h"

class PlayerMoveSystem : public System, public EventListener {
public:
    explicit PlayerMoveSystem(World *world);

protected:
    void prepare() override;

    void finalize() override;

public:

    void update() override;

    void onPlayerMoveEvent(PlayerMoveEvent *event);

private:
    std::pair<int, int> getCoordsIncrement(PlayerMoveEvent *event);
};


#endif //ROUGETEST_MOVESYSTEM_H
