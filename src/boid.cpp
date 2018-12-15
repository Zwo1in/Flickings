#include "boid.hpp"

Boid::Boid(): acceleration(0., 0.), velocity(vec::randVec(5., 10.)), position(vec::randVec(300., 500.)) {}

void Boid::update() {
    acceleration = vec::randVec(-7, 7);
    velocity += acceleration;
    velocity.setLen(8);
    position += velocity;
    acceleration.unset();
}