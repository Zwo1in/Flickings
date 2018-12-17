#include "loop.hpp"

Loop::Loop(Boids objects_): objects(objects_), pause(false) {
    body.setPointCount(3);
    body.setPoint(0, sf::Vector2f(0, 0));
    body.setPoint(1, sf::Vector2f(-5, 15));
    body.setPoint(2, sf::Vector2f(5, 15));
    body.setOrigin(0, 8);
    body.setFillColor(sf::Color(208, 217, 219, 200));
    body.setOutlineThickness(2);
    body.setOutlineColor(sf::Color(0, 12, 109, 200));
}

Loop::Boids Loop::neighbours(const Boid& obj) const {
    Boids result;
    for (auto& other : objects) {
        auto dist = vec::distance(obj.pos, other.pos);
        auto arc = obj.vel.arc() - (other.pos - obj.pos).arc();
        if (
            dist < 20 && 
            dist != 0 &&
            arc < 0.75*M_PI &&
            arc >-0.75*M_PI
        )
            result.push_back(obj);
    }
    return result;
}

vec Loop::alignment(const Boid& target, const Boids& neighbours) {
    vec result;
    for (auto& obj : neighbours) {
        result += obj.vel;
    }
    if (neighbours.size()) {
        result /= neighbours.size();
    }
    return (result - target.vel)*0.9;
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
        obj.acc = alignment(obj, neighbourhood);
        
    //     // obj.acc += separation(neighbourhood);
    //     // obj.acc += cohesion(neighbourhood);
    }
    for (auto& obj : objects) {
        obj.update();
    }
}

bool Loop::handleEvents(sf::RenderWindow& win) {
    sf::Event event;
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
            update();
            display(win);
        }
    }
}