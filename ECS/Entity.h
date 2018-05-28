//
// Created by kirill on 23.05.18.
//

#ifndef ROUGETEST_ENTITY_H
#define ROUGETEST_ENTITY_H


#include <vector>
#include "Property.h"

class Entity {
private:
    std::vector<const BaseProperty*> properties;
public:
    template <class PDC, class ...Args> void addProperty(Args ... args) {
        properties.push_back(new Property<PDC>(args...));
    }

    template <class PDC>
    bool hasProperty() {
        for (auto prop : properties) {
            if (prop->getType() == BaseProperty::getPropertyType<PDC>()) {
                return true;
            }
        }

        return false;
    }

    template <class PDC>
    const Property<PDC>* getProperty() {
        for (auto prop : properties) {
            if (prop->getType() == BaseProperty::getPropertyType<PDC>()) {
                return dynamic_cast<const Property<PDC> *>(prop);
            }
        }
    }
};

#endif //ROUGETEST_ENTITY_H
