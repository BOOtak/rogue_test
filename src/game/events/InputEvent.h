//
// Created by kirill on 02.06.18.
//

#ifndef ROUGETEST_INPUTEVENT_H
#define ROUGETEST_INPUTEVENT_H

typedef bool KeyState;

typedef int KeyCode;

struct InputEvent {
    InputEvent(KeyCode keyCode, KeyState isPressed) : isPressed(isPressed), keyCode(keyCode) {}

    KeyCode keyCode;
    KeyState isPressed;
};

#endif //ROUGETEST_INPUTEVENT_H
