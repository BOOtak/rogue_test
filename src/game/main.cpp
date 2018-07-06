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
#include "systems/CameraSystem.h"
#include "entities/Camera.h"
#include "utils/logging.h"

#include <spdlog/spdlog.h>

const int FPS = 60;

const int DEFAULT_PADDING_X = 6;
const int DEFAULT_PADDING_Y = 4;
using clk = std::chrono::high_resolution_clock;

int main() {
    INIT_LOGGER("root");

    const std::chrono::microseconds sleepInterval(1000 * 1000 / FPS);

    std::unique_ptr<World> world(new World());
    auto em = world->getEntityManager();

    auto *player = em->createEntity<Player>(12, 3);

    em->createEntity<Wall>(10, 5);
    em->createEntity<Wall>(10, 6);
    em->createEntity<Wall>(10, 7);
    em->createEntity<Wall>(10, 8);

    em->createEntity<Camera>(12, 3, DEFAULT_PADDING_X, DEFAULT_PADDING_Y, player);

    auto *is = world->addSystem<InputSystem>();
    world->getEventBus()->registerListener<InputEvent, InputSystem>(is, &InputSystem::onInputEvent);

    auto *pMs = world->addSystem<PlayerMoveSystem>();
    world->getEventBus()->registerListener<PlayerMoveEvent, PlayerMoveSystem>(pMs, &PlayerMoveSystem::onPlayerMoveEvent);

    auto *ms = world->addSystem<MoveSystem>();
    world->getEventBus()->registerListener<MoveEvent, MoveSystem>(ms, &MoveSystem::onMoveEvent);

    world->addSystem<CameraSystem>();
    world->addSystem<RenderSystem>();
    world->addSystem<CursesRawInputSystem>();

    LOG_INFO("World prepare...");
    world->prepare();
    LOG_INFO("World prepare... Done!");

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
