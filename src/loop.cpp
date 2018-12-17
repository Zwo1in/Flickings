#include "loop.hpp"
#include <iostream>

Loop::Loop(Boids objects_, int w, int h)
    : objects(objects_), pause(false), width(w), height(h) {
    body.setPointCount(3);
    body.setPoint(0, sf::Vector2f(0,  0));
    body.setPoint(1, sf::Vector2f(-5, 15));
    body.setPoint(2, sf::Vector2f(5,  15));
    body.setOrigin(0, 8);
    body.setFillColor(sf::Color(208, 217, 219, 200));
    body.setOutlineThickness(2);
    body.setOutlineColor(sf::Color(0, 12, 109, 200));
}

void Loop::edges() {
    for (auto& obj : objects) {
        if (obj.pos.x < 0)
            obj.pos.x = width;
        if (obj.pos.x > width)
            obj.pos.x = 0;
        if (obj.pos.y < 0)
            obj.pos.y = height;
        if (obj.pos.y > height)
            obj.pos.y = 0;
    }
}

Loop::Boids Loop::neighbours(const Boid& obj) const {
    Boids result{};
    for (auto& other : objects) {
        auto dist = vec::distance(obj.pos, other.pos);
        auto arc = obj.vel.arc() - (other.pos - obj.pos).arc();
        if (
            dist < 50       && 
            dist != 0       //&&
            //arc < 0.75*M_PI &&
            //arc >-0.75*M_PI
        )
            result.push_back(other);
    }
    return result;
}

void Loop::align(Boid& target, const Boids& neighbours) {
    float desiredArc{};
    if (neighbours.size()) {
        for (auto& obj : neighbours) {
            desiredArc += obj.vel.arc();
        }
        desiredArc /= neighbours.size();
        desiredArc -= target.vel.arc();
        target.acc = target.vel;
        target.acc
            .rotate(0.2*desiredArc)
            .limit(4);
    }
}

void Loop::display(sf::RenderWindow& win) {
    win.clear(sf::Color(51, 51, 51));
    for (auto& obj : objects) {
        body.setPosition(obj.pos.x, obj.pos.y);
        body.setRotation(obj.vel.arc()*180/M_PI +90);
        win.draw(body);
    }
    win.display();
}

void Loop::update() {
    for (auto& obj : objects) {
        auto neighbourhood = neighbours(obj);
        align(obj, neighbourhood);
        // obj.acc += separation(neighbourhood);
        // obj.acc += cohesion(neighbourhood);
    }
    for (auto& obj : objects) {
        obj.update();
    }
}

bool Loop::handleEvents(sf::RenderWindow& win) {
    sf::Event event{};
    while (win.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                win.close();
                break;
            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::Space)
                    pause = !pause;
                break;
        }
    }
}

void Loop::play(sf::RenderWindow& win, fpsClock& clock) {
    while (win.isOpen()) {
        handleEvents(win);
        if(clock.tick() && !pause) { 
            edges();
            update();
            display(win);
        }
    }
}