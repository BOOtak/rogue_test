//
// Created by k.leyfer on 01.06.2018.
//

#ifndef ROUGETEST_EVENTMANAGER_H
#define ROUGETEST_EVENTMANAGER_H


#include <vector>
#include <queue>
#include <map>
#include "EventListener.h"
#include "Event.h"

class EventBus {
public:
    void registerListener(BaseEventListener *listener);

    void unregisterListener(BaseEventListener *listener);

    template<class PDC, class ... Args>
    void sendEvent(Args ... args) {
        eventQueue.push(new Event<PDC>(args...));
    }

    void update();

private:
    std::map<EventType, std::vector<BaseEventListener *>> listenerMap;
    std::queue<BaseEvent *> eventQueue;
};


#endif //ROUGETEST_EVENTMANAGER_H
