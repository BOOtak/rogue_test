#include <iostream>
#include <bits/unique_ptr.h>
#include <World.h>
#include <assert.h>
#include <chrono>
#include <zconf.h>
#include <thread>
#include "properties/Position.h"
#include "entities/Player.h"
#include "entities/Mob.h"
#include "systems/InputSystem.h"
#include "systems/PlayerMoveSystem.h"
#include "systems/RenderSystem.h"
#include "systems/CursesRawInputSystem.h"
#include "entities/Wall.h"
#include "systems/MoveSystem.h"

const int FPS = 60;

using clk = std::chrono::high_resolution_clock;

int main() {
    const std::chrono::microseconds sleepInterval(1000 * 1000 / FPS);

    std::unique_ptr<World> world(new World());
    auto em = world->getEntityManager();

    auto *player = em->createEntity<Player>(12, 3);

    em->createEntity<Wall>(10, 5);
    em->createEntity<Wall>(10, 6);
    em->createEntity<Wall>(10, 7);
    em->createEntity<Wall>(10, 8);

    auto *is = world->addSystem<InputSystem>();
    world->getEventBus()->registerListener<InputEvent, InputSystem>(is, &InputSystem::onInputEvent);

    auto *pMs = world->addSystem<PlayerMoveSystem>();
    world->getEventBus()->registerListener<PlayerMoveEvent, PlayerMoveSystem>(pMs, &PlayerMoveSystem::onPlayerMoveEvent);

    auto *ms = world->addSystem<MoveSystem>();
    world->getEventBus()->registerListener<MoveEvent, MoveSystem>(ms, &MoveSystem::onMoveEvent);

    world->addSystem<RenderSystem>();
    world->addSystem<CursesRawInputSystem>();

    bool shouldStop = false;
    while (!shouldStop) {
        auto time_start = clk::now();

        // This logic implies we can handle update cycle in 1 / FPS seconds. If at some point we overrun
        // given time interval, we will have to change this logic to something more complex.
        world->update();

        auto elapsed = clk::now() - time_start;
        std::this_thread::sleep_for(sleepInterval - elapsed);
    }

    return 0;
}
