//
// Created by k.leyfer on 01.06.2018.
//

#ifndef ROUGETEST_EVENTLISTENER_H
#define ROUGETEST_EVENTLISTENER_H


#include <vector>
#include <algorithm>
#include "Event.h"

class BaseEventListener {
public:
    virtual EventType getSubscriptionEventType() = 0;
    virtual void onEvent(BaseEvent *event) = 0;
};

template<class T>
class EventListener : public BaseEventListener {
public:
    void onEvent(BaseEvent *event) override {
        if (event->getType() == getSubscriptionEventType()) {
            onEvent(reinterpret_cast<Event<T> *>(event));
        }
    }

    EventType getSubscriptionEventType() override {
        return BaseEvent::getEventType<T>();
    }

protected:
    virtual void onEvent(Event<T> *event) = 0;
};


#endif //ROUGETEST_EVENTLISTENER_H
