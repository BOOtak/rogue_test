//
// Created by k.leyfer on 01.06.2018.
//

#ifndef ROUGETEST_EVENT_H
#define ROUGETEST_EVENT_H

typedef int EventType;

class BaseEvent {
protected:
    static EventType type_;
public:
    virtual EventType getType() = 0;

    template<class PDC>
    static EventType getEventType();
};

template<class PDC>
class Event : public BaseEvent {
public:
    template<class ...Args>
    explicit Event(Args ... args) {
        data_ = new PDC(args...);
    }

    ~Event() {
        delete data_;
    }

    PDC *value() {
        return data_;
    }

private:

    friend class BaseEvent;

    static EventType type() {
        static int internal_type = type_++;
        return internal_type;
    }

    EventType getType() override {
        return type();
    }

    PDC *data_;
};

template<class PDC>
int BaseEvent::getEventType() {
    return Event<PDC>::type();
}

#endif //ROUGETEST_EVENT_H
