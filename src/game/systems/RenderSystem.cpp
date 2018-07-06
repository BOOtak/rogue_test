//
// Created by k.leyfer on 05.06.2018.
//

#include <curses.h>
#include <sstream>
#include "RenderSystem.h"
#include "../properties/Position.h"
#include "../properties/Focus.h"

#define CURSOR_INVISIBLE 0

RenderSystem::RenderSystem(World *world) : System(world) {}

void RenderSystem::update() {
    auto entities = getWorld()->getEntityManager()->getEntitiesWithProperties<CharTexture, Position>();
    int width, height;
    getmaxyx(stdscr, height, width);
    blankFill(width, height);

    std::vector<Entity *> cameras = getWorld()->getEntityManager()->getEntitiesWithProperties<Position, Focus>();
    if (cameras.size() > 1) {
        LOG_WARN("More than one camera is found! Seems like not okay.");
    } else if (cameras.empty()) {
        LOG_WARN("No cameras found, refuse to render!");
        return;
    }

    auto &mainCam = cameras.at(0);
    auto &camPos = mainCam->getProperty<Position>()->getValue()->position_;
    auto centerPos = Vector2<int>(width, height) / 2;

    for (auto e : entities) {
        auto position = e->getProperty<Position>()->getValue()->position_ - camPos + centerPos;
        auto texture = e->getProperty<CharTexture>()->getValue();
        if (position.x < width && position.y < height) {
            draw(position.x, position.y, texture);
        }
    }
    refresh();
}

void RenderSystem::prepare() {
    LOG_DEBUG("RenderSystem::prepare()");
    initscr();
    curs_set(CURSOR_INVISIBLE);
    cbreak();
    noecho();
    mvaddstr(0, 1, "Hi there!");
}

void RenderSystem::finalize() {
    LOG_DEBUG("RenderSystem::finalize()");
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
