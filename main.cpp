#include "loop.hpp"

int main() {
    sf::RenderWindow win(sf::VideoMode(800, 800), "Boids");
    auto clock = fpsClock(30);

    std::vector<Boid> obj(3000);
    Loop loop(obj);
    loop.play(win, clock);
    
    return 0;
}