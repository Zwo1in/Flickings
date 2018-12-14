#include "vec.hpp"

vec::vec(): x(0), y(0) {}
vec::vec(float x_, float y_): x(x_), y(y_) {}

const float vec::len() const {
    return static_cast<float>(sqrt(x*x + y*y));
}

const float vec::arc() const {
    return static_cast<float>(atan(y/x));
}

vec vec::unit() const {
    return vec(x, y)/len();
}

void vec::setLen(const float& len) {
    auto thisUnit = unit();
    x = thisUnit.x * len;
    y = thisUnit.y * len;        
}

void vec::setArc(const float& arc) {
    float length = len();
    x = length * cos(arc);
    y = length * sin(arc);
}

void vec::rotate(const float& arc_) {
    float length = len();
    float rotation = arc();
    x = length * cos(rotation + arc_);
    y = length * sin(rotation + arc_);
}

void vec::limit(const float& len_) {
    if (len() > len_)
        setLen(len_);
}

vec operator+  (const vec& lhs, const vec& rhs) {
    return vec(lhs.x+rhs.x, lhs.y+rhs.y);
}

vec operator-  (const vec& lhs, const vec& rhs) {
    return vec(lhs.x-rhs.x, lhs.y-rhs.y);
}

vec& vec::operator+= (const vec& rhs) {
    x += rhs.x;
    y += rhs.y;
}

vec& vec::operator-= (const vec& rhs) {
    x -= rhs.x;
    y -= rhs.y;
}

vec operator*  (const vec& lhs, const float& val) {
    return vec(lhs.x*val, lhs.y*val);
}

vec operator/  (const vec& lhs, const float& val) {
    return vec(lhs.x/val, lhs.y/val);
}

vec operator*  (const float& val, const vec& rhs) {
    return vec(rhs.x*val, rhs.y*val);
}

vec operator/  (const float& val, const vec& rhs) {
    return vec(rhs.x/val, rhs.y/val);
}

vec& vec::operator*= (const float& val) {
    x *= val;
    y *= val;
}

vec& vec::operator/= (const float& val) {
    x /= val;
    y /= val;
}

bool operator== (const vec& lhs, const vec& rhs) {
    return lhs.x == rhs.x && lhs.y == rhs.y;
}

bool operator!= (const vec& lhs, const vec& rhs) {
    return lhs.x != rhs.x || lhs.y != rhs.y;
}



