//
// Created by kirill on 05.06.18.
//

#ifndef ROUGETEST_BASEEVENTDELEGATE_H
#define ROUGETEST_BASEEVENTDELEGATE_H

#include "Event.h"
#include "EventListener.h"

class BaseEventDelegate {
public:
    explicit BaseEventDelegate(EventListener *listener) : listener(listener) {}

    virtual void invoke(BaseEvent *event) const = 0;

    EventListener *getListener() const {
        return listener;
    }

private:
    EventListener *listener;
};

#endif //ROUGETEST_BASEEVENTDELEGATE_H
