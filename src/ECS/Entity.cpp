//
// Created by kirill on 23.05.18.
//

#include "Entity.h"

Entity::~Entity() {
    for (auto property : properties) {
        delete(property.second);
    }
}
