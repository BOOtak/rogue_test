//
// Created by kirill on 02.06.18.
//

#include "InputSystem.h"

InputSystem::InputSystem(World *world) : System(world) {}

void InputSystem::onEvent(Event<InputEvent> *event) {
    Event<PlayerMoveEvent> *controlEvent = getPlayerControlEvent(event);
    if (controlEvent != nullptr) {
        getWorld()->getEventBus()->sendEvent(controlEvent);
    }
}

Event<PlayerMoveEvent> *InputSystem::getPlayerControlEvent(Event<InputEvent> *inputEvent) {
    InputEvent* val = inputEvent->value();
    if (!val->isPressed) {
        return nullptr;
    }

    auto type = inputMap.find(val->keyCode);
    if (type != inputMap.end()) {
        return new Event<PlayerMoveEvent>(type->second);
    }
}

void InputSystem::update() {

}
