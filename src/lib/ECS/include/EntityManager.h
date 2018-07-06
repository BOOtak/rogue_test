//
// Created by kirill on 31.05.18.
//

#ifndef ROUGETEST_ENTITYMANAGER_H
#define ROUGETEST_ENTITYMANAGER_H


#include <vector>
#include "Entity.h"

class EntityManager {
public:
    template<class T, class ...Args>
    Entity *createEntity(Args ...args) {
        Entity *newEntity = new T(args...);
        entities.push_back(newEntity);
        return newEntity;
    }

    template<class ... TProperties>
    std::vector<Entity *> getEntitiesWithProperties() {
        std::vector<Entity *> targetEntities;
        for (auto e : entities) {
            if (e->hasProperties<TProperties...>()) {
                targetEntities.push_back(e);
            }
        }

        return targetEntities;
    }

    ~EntityManager();

private:
    std::vector<Entity *> entities;
};

#endif //ROUGETEST_ENTITYMANAGER_H
