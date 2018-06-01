//
// Created by kirill on 23.05.18.
//

#ifndef ROUGETEST_ENTITY_H
#define ROUGETEST_ENTITY_H


#include <map>
#include "Property.h"

class Entity {
private:
    std::map<int, const BaseProperty*> properties;
public:
    ~Entity();

    template <class PDC, class ...Args> void addProperty(Args ... args) {
        properties.insert(std::make_pair(BaseProperty::getPropertyType<PDC>(), new Property<PDC>(args...)));
    }

    template <class PDC>
    bool hasProperty() {
        return properties.find(BaseProperty::getPropertyType<PDC>()) != properties.end();
    }

    template <class PDC>
    const Property<PDC>* getProperty() {
        auto it = properties.find(BaseProperty::getPropertyType<PDC>());
        if (it != properties.end()) {
            return dynamic_cast<const Property<PDC> *>(it->second);
        }
    }
};

#endif //ROUGETEST_ENTITY_H
