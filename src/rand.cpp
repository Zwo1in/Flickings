#include "rand.hpp"

void random::init() {
    srand(time(0));
}
float random::randf() {
    return static_cast<float>(rand())/RAND_MAX;
}
float random::randf(int upperBound) {
    double value = static_cast<double>(rand())/RAND_MAX;
    return static_cast<float>(value*upperBound);
}
float random::randf(int lowerBound, int upperBound) {
    double value = static_cast<double>(rand())/RAND_MAX;
    return static_cast<float>(
        value*(upperBound - lowerBound) + lowerBound
    );
}
int random::randi() {
    return rand();
}
int random::randi(int upperBound) {
    
    return rand()%upperBound;
}
int random::randi(int lowerBound, int upperBound) {
    return rand()%(upperBound-lowerBound)+lowerBound;
}