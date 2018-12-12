#include <SFML/Graphics.hpp>
#include "fpsClock.hpp"
#include <vector>

struct Loop {
    using Boids = std::vector<Boid>;
    
    Boids objects;
    bool pause;
    
    explicit Loop(Boids objects_): objects(objects_), pause(false) {}
    Loop() = delete;
    Loop(Loop&) = delete;

    void display(sf::RenderWindow&);
    void update();
    bool handleEvents(sf::RenderWindow&);
    void play(sf::RenderWindow&, fpsClock&);

    void operator=(Loop&) = delete;
};
