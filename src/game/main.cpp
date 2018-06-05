#include <iostream>
#include <bits/unique_ptr.h>
#include <World.h>
#include <unistd.h>
#include <assert.h>
#include "properties/Position.h"
#include "entities/Player.h"
#include "entities/Mob.h"
#include "systems/InputSystem.h"
#include "systems/MoveSystem.h"
#include "systems/RenderSystem.h"

static const int FPS = 1;
static const int64_t SLEEP_INTERVAL_US = 1000 * 1000 / FPS;  // microseconds

int64_t getTimestamp(timespec *ts) {
    clock_gettime(CLOCK_MONOTONIC, ts);
    return ts->tv_sec * 1000 * 1000 + ts->tv_nsec / 1000;
}

useconds_t getSleepTime(int64_t timestamp, timespec *ts) {
    return static_cast<useconds_t>(SLEEP_INTERVAL_US + timestamp - getTimestamp(ts));
}

int main() {
    std::unique_ptr<World> world(new World());
    auto em = world->getEntityManager();

    auto *player = em->createEntity<Player>(12, 3);
    em->createEntity<Mob>(10, 20);

    auto *is = world->addSystem<InputSystem>();
    auto *ms = world->addSystem<MoveSystem>();
    world->addSystem<RenderSystem>();
    world->getEventBus()->registerListener<InputEvent, InputSystem>(is, &InputSystem::onInputEvent);
    world->getEventBus()->registerListener<PlayerMoveEvent, MoveSystem>(ms, &MoveSystem::onPlayerMoveEvent);

    world->getEventBus()->sendEvent<InputEvent>(KEY_DOWN, true);
    world->getEventBus()->sendEvent<InputEvent>(KEY_DOWN, true);
    world->getEventBus()->sendEvent<InputEvent>(KEY_LEFT, true);
    world->getEventBus()->sendEvent<InputEvent>(KEY_LEFT, true);
    world->getEventBus()->sendEvent<InputEvent>(KEY_LEFT, true);

    world->update();
    world->update();
    world->update();
    world->update();
    world->update();

//    bool shouldStop = false;
//    timespec ts{};
//    while (!shouldStop) {
//        int64_t timestamp = getTimestamp(&ts);
//        std::cout << timestamp << std::endl;
//        usleep(getSleepTime(timestamp, &ts));
//    }

    auto *pos = player->getProperty<Position>()->getValue();
    std::cout << pos->x_ << " " << pos->y_ << std::endl;
    assert(pos->x_ == 9);
    assert(pos->y_ == 5);

    return 0;
}
