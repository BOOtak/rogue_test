//
// Created by kirill on 06.06.18.
//

#include <curses.h>
#include "CursesRawInputSystem.h"
#include "../events/InputEvent.h"

CursesRawInputSystem::CursesRawInputSystem(World *world) : System(world) {}

void CursesRawInputSystem::prepare() {
    keypad(stdscr, true);
    nodelay(stdscr, true);
}

void CursesRawInputSystem::update() {
    int ch = getch();
    if (ch != ERR) {
        getWorld()->getEventBus()->sendEvent<InputEvent>(ch);
    }
}

void CursesRawInputSystem::finalize() {

}
