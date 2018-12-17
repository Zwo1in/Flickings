#include "boid.hpp"

Boid::Boid(): 
    acc(0, 0), vel(vec::randVec(-10, 10)), pos(vec::randVec(1, 799)) {}

void Boid::update() {
    // acc = vec::randVec(-7, 7);
    vel += acc;
    vel.limit(8);
    pos += vel;
    acc.unset();
}