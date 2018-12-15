#pragma once

#include <ctime>
#include <cstdlib>

struct random {

    random() = delete;
    random(random&) = delete;
    random(random&&) = delete;
    void operator= (random&) = delete;
    void operator= (random&&) = delete;

    static void init();
    static float randf();
    static float randf(int);
    static float randf(int, int);
    static int randi();
    static int randi(int);
    static int randi(int, int);
};