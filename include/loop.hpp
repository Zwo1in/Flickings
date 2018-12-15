#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "fpsClock.hpp"
#include "boid.hpp"

struct Loop {
    using Boids = std::vector<Boid>;
    
    sf::ConvexShape body;
    Boids objects;
    bool pause;
    
    explicit Loop(Boids);
    Loop() = delete;
    Loop(Loop&) = delete;
    void operator=(Loop&) = delete;

    vec alignment(const Boids&);

    Boids neighbours(const Boid&) const;
    void display(sf::RenderWindow&);
    void update();
    bool handleEvents(sf::RenderWindow&);
    void play(sf::RenderWindow&, fpsClock&);
};
