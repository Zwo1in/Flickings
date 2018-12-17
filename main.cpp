#include "loop.hpp"
#include <iostream>
#include <cassert>

const int width = 800;
const int height = 800;

int main() {
    
    const float v1 = vec(4, 0).arc();
    const float v2 = vec(0, 4).arc();
    const float v3 = vec(-4, 0).arc();
    const float v4 = vec(0, -4).arc();

    assert(v1 == 0);
    assert(v2 == M_PI_2f32);
    assert(v3 == M_PIf32);
    assert(v4 == static_cast<float>(1.5*M_PI));

    sf::RenderWindow win(sf::VideoMode(width, height), "Boids");
    auto clock = fpsClock(30);

    std::vector<Boid> obj(150);
    Loop loop(obj, width, height);
    loop.play(win, clock);

    return 0;
}