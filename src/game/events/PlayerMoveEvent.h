//
// Created by kirill on 02.06.18.
//

#ifndef ROUGETEST_PLAYERMOVEEVENT_H
#define ROUGETEST_PLAYERMOVEEVENT_H

enum MoveType {
    MOVE_UP,
    MOVE_DOWN,
    MOVE_LEFT,
    MOVE_RIGHT
};

struct PlayerMoveEvent {
    PlayerMoveEvent(MoveType direction) : direction(direction) {}

    MoveType direction;
};

#endif //ROUGETEST_PLAYERMOVEEVENT_H
