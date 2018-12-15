#pragma once

#include "vec.hpp"

struct Boid {
    vec acceleration;
    vec velocity;
    vec position;

    Boid();
    void update();
};