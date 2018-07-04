//
// Created by k.leyfer on 03.07.2018.
//

#ifndef ROGUETEST_VECTOR2_H
#define ROGUETEST_VECTOR2_H

template<class T>
class Vector2 {
public:
    Vector2(T x, T y) : x(x), y(y) {}

    T x;
    T y;

    Vector2<T> operator+(const Vector2<T> &other) {
        return Vector2<int>(x + other.x, y + other.y);
    }

    Vector2<T> operator-(const Vector2<T> &other) {
        return Vector2<int>(x - other.x, y - other.y);
    }

    Vector2<T> operator/(int scalar) {
        return Vector2<int>(x / scalar, y  / scalar);
    }

    bool operator==(const Vector2 &other) const {
        return x == other.x &&
               y == other.y;
    }

    bool operator!=(const Vector2 &other) const {
        return !(other == *this);
    }
};


#endif //ROGUETEST_VECTOR2_H
