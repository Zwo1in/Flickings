#include "../include/boid.hpp"
#include <SFML/Graphics.hpp>
#include <cmath>
class vec {
    float x, y;

    vec(): x(0), y(0) {}
    vec(float x_, float y_): x(x_), y(y_) {}
    
    float len() {
        return sqrt(x*x + y*y); 
    }
    
};