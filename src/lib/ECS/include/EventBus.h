//
// Created by k.leyfer on 01.06.2018.
//

#ifndef ROUGETEST_EVENTMANAGER_H
#define ROUGETEST_EVENTMANAGER_H


#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include "Event.h"
#include "EventDelegate.h"

typedef void (*EventCallback)(BaseEvent *);

class EventBus {
public:
    template<class TEvent, class TListener>
    void registerListener(TListener *listener, void(TListener::*callback)(TEvent *event)) {
        EventType type = BaseEvent::getEventType<TEvent>();
        if (listenerMap.find(type) == listenerMap.end()) {
            listenerMap.insert(std::make_pair(type, std::vector<BaseEventDelegate *>()));
        }

        listenerMap.at(type).push_back(new EventDelegate<TListener, TEvent>(listener, callback));
    }

    template<class TEvent, class TListener>
    void unregisterListener(TListener *listener) {
        EventType type = BaseEvent::getEventType<TEvent>();
        if (listenerMap.find(type) == listenerMap.end()) {
            return;
        }

        auto &delegatesOfType = listenerMap.at(type);
        auto newDelegates = std::remove_if(delegatesOfType.begin(), delegatesOfType.end(), [&](BaseEventDelegate *delegate) -> bool {
            return (delegate->getListener() == listener);
        });
        delegatesOfType.resize(static_cast<unsigned long>(newDelegates - delegatesOfType.begin()));
    }

    template<class PDC, class ... Args>
    void sendEvent(Args ... args) {
        eventQueue.push(new Event<PDC>(args...));
    }

    void sendEvent(BaseEvent *event) {
        eventQueue.push(event);
    }

    void update();

private:
    std::map<EventType, std::vector<BaseEventDelegate *>> listenerMap;
    std::queue<BaseEvent *> eventQueue;
};


#endif //ROUGETEST_EVENTMANAGER_H
