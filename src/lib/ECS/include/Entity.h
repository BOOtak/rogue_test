//
// Created by kirill on 23.05.18.
//

#ifndef ROUGETEST_ENTITY_H
#define ROUGETEST_ENTITY_H


#include <map>
#include "Property.h"

class Entity {
private:
    std::map<int, const BaseProperty *> properties;
public:
    ~Entity();

    template<class PDC, class ...Args>
    void addProperty(Args ... args) {
        properties.insert(std::make_pair(BaseProperty::getPropertyType<PDC>(), new Property<PDC>(args...)));
    }

    template<class TProperty, class ... Args>
    bool hasProperties() {
        bool hasProp = properties.find(BaseProperty::getPropertyType<TProperty>()) != properties.end();
        if constexpr(sizeof...(Args) > 0) {
            return hasProp && hasProperties<Args...>();
        } else {
            return hasProp;
        }
    }

    template<class PDC>
    const Property<PDC> *getProperty() const {
        auto it = properties.find(BaseProperty::getPropertyType<PDC>());
        if (it != properties.end()) {
            return dynamic_cast<const Property<PDC> *>(it->second);
        } else {
            return nullptr;
        }
    }
};

#endif //ROUGETEST_ENTITY_H
