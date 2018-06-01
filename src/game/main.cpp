#include <iostream>
#include <bits/unique_ptr.h>
#include <World.h>
#include "properties/Position.h"
#include "commands/MoveCommand.h"
#include "entities/Player.h"
#include "entities/Mob.h"
#include "systems/PingSystem.h"

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

    auto *eventBus = new EventBus();
    auto *pingSystem = new PingSystem(em, eventBus);
    auto *pongSystem = new PongSystem(em, eventBus);

    eventBus->registerListener(pingSystem);
    eventBus->registerListener(pongSystem);

    eventBus->sendEvent<PingEvent>();
    eventBus->update();
    eventBus->update();
    eventBus->update();
    eventBus->update();
    eventBus->update();

    eventBus->unregisterListener(pingSystem);
    eventBus->unregisterListener(pongSystem);
    eventBus->update();
    eventBus->update();

    return 0;
}
