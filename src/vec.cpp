#include "vec.hpp"

vec::vec(): x(0), y(0) {}
vec::vec(float x_, float y_): x(x_), y(y_) {}

vec vec::randVec(int lbound, int ubound) {
    return vec(random::randf(lbound, ubound), random::randf(lbound, ubound));
}

vec vec::randVec(int lboundx, int lboundy, int uboundx, int uboundy) {
    return vec(random::randf(lboundx, lboundy), random::randf(uboundx, uboundy));
}

float vec::distance(const vec& vec1, const vec& vec2) {
    return (vec2-vec1).len();
}

const float vec::len() const {
    return static_cast<float>(sqrt(x*x + y*y));
}

const float vec::arc() const {
    if (x > 0)
        return static_cast<float>(atan(y/x));
    else if (x < 0)
        return static_cast<float>(atan(y/x))+M_PI;
    else {
        if (y > 0)
            return M_PI_2;
        else
            return -M_PI_2;
    }
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

void vec::unset() {
    x = y = 0.;
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



