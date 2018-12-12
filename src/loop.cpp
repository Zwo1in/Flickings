#include "../include/loop.hpp"

void Loop::display( sf::RenderWindow& win ) {
    win.clear( sf::Color(51, 51, 51) );
    for ( auto* obj : objects )
        obj -> draw( win );
    win.display();
}

void Loop::update() {
    for (auto* obj : objects)
        obj -> update();
}

bool Loop::handleEvents( sf::RenderWindow& win ) {
    sf::Event event;
    while ( win.pollEvent( event ) ) {
        switch ( event.type ) {
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
void Loop::play( sf::RenderWindow& win, fpsClock& clock ) {
    while ( win.isOpen() ) {
        handleEvents( win );
        if( clock.tick() && !pause ) { 
            update();
            display( win );
        }
    }
}