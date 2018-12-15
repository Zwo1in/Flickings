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

//FIXME: Remove obj for which method is called from vector
Loop::Boids Loop::neighbours(const Boid& obj) const {
    Boids result;
    for (auto& other : objects) {
        if (
            vec::distance(obj.position, other.position) < 20 && 
            obj.velocity.arc() - (other.position - obj.position).arc() < 0.75*M_PI &&
            obj.velocity.arc() - (other.position - obj.position).arc() >-0.75*M_PI
        )
            result.push_back(obj);
    }
    return result;
}

vec Loop::alignment(const Boids&) {

}

void Loop::display(sf::RenderWindow& win) {
    win.clear(sf::Color(51, 51, 51));
    for (auto& obj : objects) {
        body.setPosition(obj.position.x, obj.position.y);
        body.setRotation(obj.velocity.arc()*180/M_PI +90);
        win.draw(body);
    }
    win.display();
}

void Loop::update() {
    for (auto& obj : objects) {
        auto neighbourhood = neighbours(obj);
        obj.acceleration += alignment(neighbourhood);
        // obj.acceleration += separation(neighbourhood);
        // obj.acceleration += cohesion(neighbourhood);
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