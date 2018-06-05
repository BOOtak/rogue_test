//
// Created by kirill on 06.06.18.
//

#ifndef ROGUETEST_RAWINPUTSYSTEM_H
#define ROGUETEST_RAWINPUTSYSTEM_H


#include <System.h>

/**
 * Obtains raw input events, converts it to InputEvents and passes to event handler.
 */
class CursesRawInputSystem : public System {
public:
    CursesRawInputSystem(World *world);

protected:
    void prepare() override;

    void update() override;

    void finalize() override;

};


#endif //ROGUETEST_RAWINPUTSYSTEM_H
