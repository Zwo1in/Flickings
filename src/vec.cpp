#include "vec.hpp"

vec::vec(): x(0), y(0) {}
vec::vec(float x_, float y_): x(x_), y(y_) {}

vec vec::randVec(int lb, int ub) {
    return vec(random::randf(lb, ub), random::randf(lb, ub));
}

vec vec::randVec(int lbx, int lby, int ubx, int uby) {
    return vec(random::randf(lbx, lby), random::randf(ubx, uby));
}

float vec::distance(const vec& vec1, const vec& vec2) {
    return (vec2-vec1).len();
}

const float vec::len() const {
    return static_cast<float>(sqrt(x*x + y*y));
}

const float vec::arc() const {
    if (x > 0)
        if (y >= 0)
            return static_cast<float>(atan(y/x));
        else
            return 2*M_PI + static_cast<float>(atan(y/x));
    else if (x < 0)
        return static_cast<float>(atan(y/x))+M_PI;
    else {
        if (y > 0)
            return M_PI_2;
        else
            return 1.5*M_PI;
    }
}

vec& vec::unit() {
    if (len() == 0)
        return *this;
    x /= len();
    y /= len();
    return *this;
}

vec& vec::setLen(const float& len) {
    auto thisUnit = unit();
    x = thisUnit.x * len;
    y = thisUnit.y * len;     
    return *this;
}

vec& vec::setArc(const float& arc) {
    float length = len();
    x = length * cos(arc);
    y = length * sin(arc);
    return *this;
}

vec& vec::rotate(const float& arc_) {
    float length = len();
    float rotation = arc();
    x = length * cos(rotation + arc_);
    y = length * sin(rotation + arc_);
    return *this;
}

vec& vec::limit(const float& len_) {
    if (len() > len_)
        setLen(len_);
    return *this;
}

vec& vec::unset() {
    x = y = 0;
    return *this;
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
    return *this;
}

vec& vec::operator-= (const vec& rhs) {
    x -= rhs.x;
    y -= rhs.y;
    return *this;
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
    return *this;
}

vec& vec::operator/= (const float& val) {
    x /= val;
    y /= val;
    return *this;
}

bool operator== (const vec& lhs, const vec& rhs) {
    return lhs.x == rhs.x && lhs.y == rhs.y;
}

bool operator!= (const vec& lhs, const vec& rhs) {
    return lhs.x != rhs.x || lhs.y != rhs.y;
}



