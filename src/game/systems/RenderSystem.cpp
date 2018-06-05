//
// Created by k.leyfer on 05.06.2018.
//

#include <ncurses/curses.h>
#include "RenderSystem.h"
#include "../properties/Position.h"

RenderSystem::RenderSystem(World *world) : System(world) {}

void RenderSystem::update() {
    blankFill();
    auto entities = getWorld()->getEntityManager()->getEntitiesWithProperties<CharTexture, Position>();
    int width, height;
    getmaxyx(stdscr, height, width);
    for (auto e : entities) {
        auto position = e->getProperty<Position>()->getValue();
        auto texture = e->getProperty<CharTexture>()->getValue();
        if (position->x_ < width && position->y_ < height) {
            draw(position->x_, position->y_, texture);
        } else {
            // TODO: add logging already, will ya?
            std::cout << "out of view" << std::endl;
        }
    }
    refresh();
}

void RenderSystem::prepare() {
    std::cout << "RenderSystem::prepare()" << std::endl;
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, true);
    nodelay(stdscr, true);
    mvaddstr(0, 1, "Hi there!");
}

void RenderSystem::finalize() {
    std::cout << "RenderSystem::finalize()" << std::endl;
    endwin();
}

void RenderSystem::draw(int x, int y, CharTexture *texture) {
    mvaddch(y, x, texture->texture);
}

void RenderSystem::blankFill() {
    int width, height;
    getmaxyx(stdscr, height, width);
    for (int x = 0; x < width; ++x) {
        for (int y = 0; y < height; ++y) {
            mvaddch(y, x, '.');
        }
    }
}
