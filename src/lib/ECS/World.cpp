//
// Created by kirill on 31.05.18.
//

#include "System.h"
#include "World.h"

World::World() {
    entityManager = new EntityManager();
    eventBus = new EventBus();
}

World::~World() {
    delete (entityManager);
    delete (eventBus);
    for (auto system : systems) {
        system->finalize();
        delete(system);
    }
}

EventBus *World::getEventBus() const {
    return eventBus;
}

EntityManager *World::getEntityManager() const {
    return entityManager;
}

void World::update() {
    for (auto system : systems) {
        system->update();
        // TODO: figure out whether it is better to update event bus after processing all systems.
        eventBus->update();
    }
}

void World::prepareSystem(System *system) {
    system->prepare();
}
