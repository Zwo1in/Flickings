#pragma once

#include "vec.hpp"

struct Boid {
    vec acc;
    vec vel;
    vec pos;

    Boid();
    void update();
};