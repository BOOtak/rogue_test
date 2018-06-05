//
// Created by k.leyfer on 05.06.2018.
//

#ifndef ROGUETEST_CHARTEXTURE_H
#define ROGUETEST_CHARTEXTURE_H

#include <ncurses/curses.h>

struct CharTexture {
    CharTexture(chtype texture, int caps) : texture(texture), caps(caps) {}

    chtype texture;
    int caps;
};

#endif //ROGUETEST_CHARTEXTURE_H
