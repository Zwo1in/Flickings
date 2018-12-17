#pragma once

#include <cmath>
#include "rand.hpp"

struct vec {
    float x, y;

    vec();
    vec(float, float);
    static vec randVec(int, int);
    static vec randVec(int, int, int, int);
    static float distance(const vec&, const vec&);

    const float len() const;
    const float arc() const;
    vec& unit();
    vec& setLen(const float&);
    vec& setArc(const float&);
    vec& rotate(const float&);
    vec& limit(const float&);
    vec& unset();

    friend vec  operator+  (const vec&, const vec&);
    friend vec  operator-  (const vec&, const vec&);
    vec& operator+= (const vec&);
    vec& operator-= (const vec&);
    friend vec operator*  (const vec&, const float&);
    friend vec operator/  (const vec&, const float&);
    friend vec operator*  (const float&, const vec&);
    friend vec operator/  (const float&, const vec&);
    vec& operator*= (const float&);
    vec& operator/= (const float&);
    friend bool operator== (const vec&, const vec&);
    friend bool operator!= (const vec&, const vec&);
};