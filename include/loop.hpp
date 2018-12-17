#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "fpsClock.hpp"
#include "boid.hpp"

struct Loop {
    using Boids = std::vector<Boid>;

    const int width, height;    
    sf::ConvexShape body;
    Boids objects;
    bool pause;
    
    Loop(Boids, int, int);
    Loop() = delete;
    Loop(Loop&) = delete;
    void operator= (Loop&) = delete;

    void align(Boid&, const Boids&);

    Boids neighbours(const Boid&) const;
    void edges();
    void display(sf::RenderWindow&);
    void update();
    bool handleEvents(sf::RenderWindow&);
    void play(sf::RenderWindow&, fpsClock&);
};
