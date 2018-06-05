//
// Created by kirill on 02.06.18.
//

#ifndef ROUGETEST_INPUTEVENT_H
#define ROUGETEST_INPUTEVENT_H

typedef int KeyCode;

struct InputEvent {
    explicit InputEvent(KeyCode keyCode) : keyCode(keyCode) {}

    KeyCode keyCode;
};

#endif //ROUGETEST_INPUTEVENT_H
