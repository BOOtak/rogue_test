//
// Created by k.leyfer on 05.06.2018.
//

#include <curses.h>
#include <sstream>
#include "RenderSystem.h"
#include "../properties/Position.h"

#define CURSOR_INVISIBLE 0

RenderSystem::RenderSystem(World *world) : System(world) {}

void RenderSystem::update() {
    auto entities = getWorld()->getEntityManager()->getEntitiesWithProperties<CharTexture, Position>();
    int width, height;
    getmaxyx(stdscr, height, width);
    blankFill(width, height);

    for (auto e : entities) {
        auto position = e->getProperty<Position>()->getValue()->position_;
        auto texture = e->getProperty<CharTexture>()->getValue();
        if (position.x < width && position.y < height) {
            draw(position.x, position.y, texture);
        } else {
            // TODO: add logging already, will ya?
        }
    }
    refresh();
}

void RenderSystem::prepare() {
    std::cout << "RenderSystem::prepare()" << std::endl;
    initscr();
    curs_set(CURSOR_INVISIBLE);
    cbreak();
    noecho();
    mvaddstr(0, 1, "Hi there!");
}

void RenderSystem::finalize() {
    std::cout << "RenderSystem::finalize()" << std::endl;
    endwin();
}

void RenderSystem::draw(int x, int y, CharTexture *texture) {
    mvaddch(y, x, texture->texture | texture->caps);
}

void RenderSystem::blankFill(int maxWidth, int maxHeight) {
    for (int x = 0; x < maxWidth; ++x) {
        for (int y = 0; y < maxHeight; ++y) {
            mvaddch(y, x, '.');
        }
    }
    std::stringstream dimens;
    dimens << "(" << maxWidth << ";" << maxHeight << ")";
    mvaddstr(0, 0, dimens.str().c_str());
}
