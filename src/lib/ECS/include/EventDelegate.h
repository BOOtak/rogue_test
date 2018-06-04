//
// Created by kirill on 05.06.18.
//

#ifndef ROUGETEST_EVENTDELEGATE_H
#define ROUGETEST_EVENTDELEGATE_H

#include "BaseEventDelegate.h"

template<class TListener, class TEvent>
class EventDelegate : public BaseEventDelegate {
public:
    explicit EventDelegate(TListener *listener, void (TListener::*callback)(TEvent *))
            : BaseEventDelegate(listener), callback(callback), listener(listener) {}

private:
    void invoke(BaseEvent *event) const override {
        (listener->*callback)(reinterpret_cast<Event<TEvent> *>(event)->value());
    }

private:
    void (TListener::*callback)(TEvent *event);

    TListener *listener;
};


#endif //ROUGETEST_EVENTDELEGATE_H
