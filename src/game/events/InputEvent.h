//
// Created by kirill on 02.06.18.
//

#ifndef ROUGETEST_INPUTEVENT_H
#define ROUGETEST_INPUTEVENT_H

typedef bool KeyState;

enum KeyCode {
    KEY_UP,
    KEY_DOWN,
    KEY_LEFT,
    KEY_RIGHT
};

struct InputEvent {
    InputEvent(KeyCode keyCode, KeyState isPressed) : isPressed(isPressed), keyCode(keyCode) {}

    KeyCode keyCode;
    KeyState isPressed;
};

#endif //ROUGETEST_INPUTEVENT_H
