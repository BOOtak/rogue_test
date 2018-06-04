//
// Created by kirill on 02.06.18.
//

#ifndef ROUGETEST_INPUTSYSTEM_H
#define ROUGETEST_INPUTSYSTEM_H


#include <EventListener.h>
#include <System.h>
#include "../events/InputEvent.h"
#include "../events/PlayerMoveEvent.h"

class InputSystem : public System, public EventListener<InputEvent> {
protected:
public:

protected:
public:
    explicit InputSystem(World *world);

protected:
    void onEvent(Event<InputEvent> *event) override;

    Event<PlayerMoveEvent> * getPlayerControlEvent(Event<InputEvent> *inputEvent);

    void update() override;

private:
    const std::map<KeyCode, MoveType> inputMap = {{KEY_UP, MOVE_UP}, {KEY_DOWN, MOVE_DOWN}, {KEY_LEFT, MOVE_LEFT}, {KEY_RIGHT, MOVE_RIGHT}};
};


#endif //ROUGETEST_INPUTSYSTEM_H
