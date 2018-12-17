#include "boid.hpp"

Boid::Boid(): acc(0., 0.), vel(vec::randVec(-10., 10.)), pos(vec::randVec(0, 1400, 0, 1000)) {}

void Boid::update() {
    // acc = vec::randVec(-7, 7);
    vel += acc;
    vel.setLen(8);
    pos += vel;
    acc.unset();
}