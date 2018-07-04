//
// Created by k.leyfer on 05.06.2018.
//

#ifndef ROGUETEST_RENDERSYSTEM_H
#define ROGUETEST_RENDERSYSTEM_H


#include <System.h>
#include "../properties/CharTexture.h"

class RenderSystem : public System {
public:
    RenderSystem(World *world);

protected:
    void prepare() override;

    void update() override;

    void finalize() override;

private:
    void draw(int x, int y, CharTexture *texture);

    void blankFill(int maxWidth, int maxHeight);
};


#endif //ROGUETEST_RENDERSYSTEM_H
