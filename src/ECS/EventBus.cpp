//
// Created by k.leyfer on 01.06.2018.
//

#include <iostream>
#include "EventBus.h"

void EventBus::update() {
    std::cout << __FUNCTION__ << std::endl;

    // Protect from onEvent() { sendEvent(); } loop.
    unsigned long queueSize = eventQueue.size();

    for (int i = 0; i < queueSize; ++i) {
        BaseEvent *event = eventQueue.front();
        EventType type = event->getType();
        if (listenerMap.find(type) != listenerMap.end()) {
            for (auto *listener : listenerMap.at(type)) {
                listener->onEvent(event);
            }
        }

        eventQueue.pop();
        delete (event);
    }
}

void EventBus::registerListener(BaseEventListener *listener) {
    EventType listenerSubscriptionEventType = listener->getSubscriptionEventType();
    if (listenerMap.find(listenerSubscriptionEventType) == listenerMap.end()) {
        listenerMap.insert(std::make_pair(listenerSubscriptionEventType, std::vector<BaseEventListener *>()));
    }

    listenerMap.at(listenerSubscriptionEventType).push_back(listener);
}

void EventBus::unregisterListener(BaseEventListener *listener) {
    EventType type = listener->getSubscriptionEventType();
    if (listenerMap.find(type) == listenerMap.end()) {
        std::cout << "no listener of type " << type << std::endl;
        return;
    }

    auto &listenersOfType = listenerMap.at(type);
    auto targetListener = std::find(listenersOfType.begin(), listenersOfType.end(), listener);

    if (targetListener != listenersOfType.end()) {
        listenersOfType.erase(targetListener);
        std::cout << "Unregister listener of type " << type << std::endl;
    } else {
        std::cout << "Target listener of type " << type << " Not found!" << std::endl;
    }
}
