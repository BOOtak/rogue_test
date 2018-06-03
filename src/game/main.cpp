#include <iostream>
#include <bits/unique_ptr.h>
#include <World.h>
#include <unistd.h>
#include "properties/Position.h"
#include "commands/MoveCommand.h"
#include "entities/Player.h"
#include "entities/Mob.h"
#include "systems/PingSystem.h"

static const int FPS = 1;
static const int64_t SLEEP_INTERVAL_US = 1000 * 1000 / FPS;  // microseconds

int64_t getTimestamp(timespec* ts) {
    clock_gettime(CLOCK_MONOTONIC, ts);
    return ts->tv_sec * 1000 * 1000 + ts->tv_nsec / 1000;
}

useconds_t getSleepTime(int64_t timestamp, timespec *ts) {
    return SLEEP_INTERVAL_US + timestamp - getTimestamp(ts);
}

int main() {
    std::unique_ptr<World> world(new World());
    auto em = world->getEntityManager();

    em->createEntity<Player>(12, 3);
    em->createEntity<Mob>(10, 20);
    em->createEntity<Mob>(20, 20);
    em->createEntity<Mob>(30, 20);

    auto positionedEntities = em->getEntitiesWithProperty<Position>();
    for (auto e : positionedEntities) {
        Position *pos = e->getProperty<Position>()->getValue();
        std::cout << pos->x_ << " " << pos->y_ << std::endl;

        // TODO: handle this more hicely
        std::unique_ptr<Command> command(new MoveCommand(10, 10, e));
        command->execute();
    }

    positionedEntities = em->getEntitiesWithProperty<Position>();
    for (auto e : positionedEntities) {
        Position *pos = e->getProperty<Position>()->getValue();
        std::cout << pos->x_ << " " << pos->y_ << std::endl;
    }

    auto *pingSystem = world->addSystem<PingSystem>();
    auto *pongSystem = world->addSystem<PongSystem>();
    world->getEventBus()->registerListener(pingSystem);
    world->getEventBus()->registerListener(pongSystem);

    world->getEventBus()->sendEvent<PingEvent>();

    bool shouldStop = false;
    timespec ts{};
    while (!shouldStop) {
        int64_t timestamp = getTimestamp(&ts);
        std::cout << timestamp << std::endl;
        world->update();
        usleep(getSleepTime(timestamp, &ts));
    }

    return 0;
}
