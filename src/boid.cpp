#include "boid.hpp"

Boid::Boid(): acceleration(0., 0.), velocity(0., 0.), position(vec::randVec(300., 500.)) {}

void Boid::update() {
    acceleration = vec::randVec(-2., 2.);
    velocity += acceleration;
    velocity.limit(10);
    position += velocity;
    acceleration.unset();
}