//
// Created by kirill on 04.07.18.
//

#ifndef ROGUETEST_CAMERASYSTEM_H
#define ROGUETEST_CAMERASYSTEM_H


#include <System.h>

class CameraSystem : public System {
public:
    explicit CameraSystem(World *world);

protected:
    void prepare() override;

    void update() override;

    void finalize() override;
};


#endif //ROGUETEST_CAMERASYSTEM_H
