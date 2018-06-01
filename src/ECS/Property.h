//
// Created by kirill on 23.05.18.
//

#ifndef ROUGETEST_PROPERTY_H
#define ROUGETEST_PROPERTY_H


#include <utility>

class BaseProperty {
protected:
    static int type_;
public:
    virtual int getType() const = 0;

    template<class PDC>
    static int getPropertyType();
};

template<class PDC>
class Property : public BaseProperty {
public:
    template<class ...Args>
    explicit Property(Args ...args) {
        value = new PDC(args...);
    }

    ~Property();

    PDC *getValue() const {
        return value;
    }

private:
    PDC *value;

    friend class BaseProperty;

    static int type() {
        static int internal_type = type_++;
        return internal_type;
    }

    int getType() const override {
        return type();
    }
};

template<class PDC>
Property<PDC>::~Property() {
    delete (value);
}

template<class PDC>
int BaseProperty::getPropertyType() {
    return Property<PDC>::type();
}

#endif //ROUGETEST_PROPERTY_H
