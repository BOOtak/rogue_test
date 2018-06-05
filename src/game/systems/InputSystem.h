//
// Created by kirill on 02.06.18.
//

#ifndef ROUGETEST_INPUTSYSTEM_H
#define ROUGETEST_INPUTSYSTEM_H


#include <System.h>
#include "../events/InputEvent.h"
#include "../events/PlayerMoveEvent.h"

class InputSystem : public System, public EventListener {
protected:
public:

protected:
public:
    explicit InputSystem(World *world);

    void onInputEvent(InputEvent* event);

protected:
    Event<PlayerMoveEvent> *getPlayerControlEvent(InputEvent *inputEvent);

    void update() override;

    void prepare() override;

    void finalize() override;

private:
    const std::map<KeyCode, MoveType> inputMap = {{KEY_UP,    MOVE_UP},
                                                  {KEY_DOWN,  MOVE_DOWN},
                                                  {KEY_LEFT,  MOVE_LEFT},
                                                  {KEY_RIGHT, MOVE_RIGHT}};
};


#endif //ROUGETEST_INPUTSYSTEM_H
