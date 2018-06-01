//
// Created by kirill on 31.05.18.
//

#include "EntityManager.h"

EntityManager::~EntityManager() {
    for (auto e : entities) {
        delete (e);
    }
}
