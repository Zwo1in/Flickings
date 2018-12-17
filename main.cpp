#include "loop.hpp"

const int width = 1400;
const int height = 1000;

int main() {
    sf::RenderWindow win(sf::VideoMode(width, height), "Boids");
    auto clock = fpsClock(30);

    std::vector<Boid> obj(200);
    Loop loop(obj);
    loop.play(win, clock);
    
    return 0;
}